# primegen
Generates prime numbers using the square root method.

Made on Arch, BTW.
<br/><br/>
mc_modder, 2025

This version includes three versions:
- C++ Version
- Python Version
- Precompiled Linux Binary
- Extra Optimized Binary

Includes a calculation timer, an option to store the prime numbers to a text file, and most importantly, the algorithm.

**Compiling** <br/><br/>
*Optimized* <br/><br/>
g++ -O3 -march=native -o primegen algorithm.cpp <br/><br/>
*Normal* <br/><br/>
g++ algorithm.cpp -o primegen -O3
