#include "Network.h"
int main(int argc, char**argv){
    if(argc<4) return -1;
    int dim = atoi(argv[1]);
    uint64_t req = atoll(argv[2]);
    double p = atof(argv[3]);
    Network net(dim, req, p);
    net.simulate();
    return 0;
}
