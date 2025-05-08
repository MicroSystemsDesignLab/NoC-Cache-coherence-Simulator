# NoC Coherence Simulator

## Overview

Cycle-accurate discrete-event simulator of a mesh NoC with directory-based cache coherence.  
Supports hierarchical directories, bloom filters, leases, dynamic domains, and RDMA fallback.

## Build

```bash
mkdir build && cd build
cmake ..
make
```

## Run

```bash
./noc_simulator GRID_DIM REQUESTS P_REMOTE
```

- `GRID_DIM`: dimension of the mesh (e.g., 16 for 16×16 devices)
- `REQUESTS`: total memory requests
- `P_REMOTE`: probability a request goes to a remote device

Example:

```bash
./noc_simulator 16 1000000 0.1
```

## Structure

- `include/`: headers for core modules (Event, Router, Network, Protocol, etc.)
- `src/`: implementation files
- `main.cpp`: entry point
