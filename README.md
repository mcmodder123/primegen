# primegen
Generates prime numbers using the square root method.

Made on Arch, BTW.
<br/><br/>
mc_modder, 2025

This includes two versions:
- C++ Version
- Precompiled Linux Binary

For some reason, I decided to make it as optimized as possible, so older versions will no longer be maintained.

**Usage**
<br/><br/>
Usage: ./primegen NUM
Computes all prime numbers <= NUM.

**Compiling** <br/><br/>
g++ -O3 -march=native -o primegen optoalgo.cpp <br/><br/>
If compile time is too slow, use the below:
<br/><br/>
g++ optoalgo.cpp -o primegen
