#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
// Made on Arch, BTW.
// extra optimized version
bool isPrime(int num){
    if (num == 2) return 1;
    if (num <= 1) return 0;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]){
    int iterations = std::atoi(argv[1]);
    int starting_num = 1;
    //start timing
    auto start_time = std::chrono::high_resolution_clock::now();
    //calculations
    for (int i = 1; i < iterations; i++) {
        if (isPrime(starting_num) == 1) {std::cout << starting_num << '\n';}
        starting_num++;
    }
    //end timing
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    double seconds = static_cast<double>(duration.count()) / 1e9;
    std::cout << "Calculation time: " << std::fixed << std::setprecision(8) << seconds << " seconds" << '\n';
    return 0;
}
// mc_modder, 2025
