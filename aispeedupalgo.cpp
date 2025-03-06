#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")

#include <iostream>
#include <chrono>
#include <cmath>
#include <bitset>
#include <omp.h>
#include <iomanip>

const int CACHE_LINE_SIZE = 64;
const int NUM_THREADS = 4;

struct CacheAligned {
    alignas(CACHE_LINE_SIZE) std::bitset<1000001> isPrime;
};

CacheAligned cacheAligned;

bool isPrimeOptimized(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Use 6k ± 1 optimization
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

void parallelPrimeCheck(int iterations) {
    std::cout << "Starting prime number calculation...\n";

    auto start_time = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for num_threads(NUM_THREADS) schedule(dynamic, 1000)
    for (int i = 0; i < NUM_THREADS; ++i) {
        int start = (iterations / NUM_THREADS) * i + 1;
        int end = (iterations / NUM_THREADS) * (i + 1);

        if (i == NUM_THREADS - 1) end = iterations;

        for (int num = start; num <= end; ++num) {
            if (isPrimeOptimized(num)) {
                #pragma omp critical
                std::cout << num << '\n';
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    double seconds = static_cast<double>(duration.count()) / 1e9;

    std::cout << "\nCalculation time: " << std::fixed << std::setprecision(8)
              << seconds << " seconds\n";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <iterations>\n";
        return 1;
    }

    int iterations = std::atoi(argv[1]);
    if (iterations <= 0) {
        std::cerr << "Iterations must be positive\n";
        return 1;
    }

    parallelPrimeCheck(iterations);
    return 0;
}
