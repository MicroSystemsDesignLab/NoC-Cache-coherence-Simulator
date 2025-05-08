#include "Router.h"
#include "Packet.h"
#include <cassert>

static int xy_to_port(int sx,int sy,int dx,int dy){
    if(dx>sx) return 1;
    if(dx<sx) return 3;
    if(dy>sy) return 2;
    if(dy<sy) return 0;
    return -1;
}

Router::Router(uint32_t i, int d, EventQueue *q) : id(i), dim(d), eq(q) {
    credits.fill(8); // initial credits per port
}

void Router::recv_flit(const Flit &f, Cycle at){
    uint32_t sx = id % dim, sy = id / dim;
    uint32_t dx = f.dst % dim, dy = f.dst / dim;
    int port = xy_to_port(sx,sy,dx,dy);
    if(port<0) port = 0;
    in_q[port].push(f);
    schedule_stage(port, at+1);
}

void Router::schedule_stage(uint32_t port, Cycle when){
    eq->push({when, [=](){
        process_flit(port);
    }});
}

void Router::process_flit(uint32_t port){
    if(in_q[port].empty()) return;
    Flit f = in_q[port].front(); in_q[port].pop();
    uint32_t sx = id % dim, sy = id / dim;
    uint32_t dx = f.dst % dim, dy = f.dst / dim;
    int outp = xy_to_port(sx,sy,dx,dy);
    if(outp<0) outp = 0;
    if(credits[outp]>0){
        credits[outp]--;
        // send to next router or host
        // For brevity: we assume direct mapping; real code would lookup neighbor
        // Re-credit local port immediately for simplicity
        credits[port]++;
    }
}
