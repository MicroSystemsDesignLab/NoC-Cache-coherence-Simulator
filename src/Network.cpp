#include "Network.h"
#include "Packet.h"
#include <iostream>
#include <cstdlib>

Network::Network(int d, uint64_t req, double p)
    : dim(d), nodes(d*d), requests(req), p_remote(p), dir(nodes), wl(nodes,req,p) {
    routers.reserve(nodes);
    for(uint32_t i=0;i<nodes;++i){
        routers.push_back(new Router(i,dim,&eq));
    }
}

void Network::simulate(){
    // inject events
    for(uint64_t i=0; i<requests; ++i){
        bool remote = wl.isRemote(i);
        uint32_t src = rand()%nodes;
        uint32_t dst = remote?(rand()%nodes):src;
        uint32_t addr = rand();
        bool write = rand()%2;
        eq.push({i, [=](){
            // generate packet of 4 flits
            for(int f=0; f<4; ++f){
                Flit fl{src,dst,(f==0?HEAD:(f==3?TAIL:BODY)),i,addr};
                routers[src]->recv_flit(fl, i);
                msg_count++;
            }
            dir.access(src, addr, write);
        }});
    }
    // run simulation
    while(!eq.empty()){
        auto e = eq.pop();
        e.action();
    }
    std::cout<<"Msgs="<<msg_count
             <<" Invalidations="<<dir.get_invalidations()
             <<" MetadataMB="<<(double)dir.metadata_bytes()/(1024*1024)
             <<std::endl;
}
