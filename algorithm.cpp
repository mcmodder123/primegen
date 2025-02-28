#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <iomanip>

// Made on Arch Linux, BTW.
// mc_modder, 2025

using namespace std;

char algorithm(int num) {
    if (num <= 1) return 'n';
    if (num == 2) return 'y';
    if (num % 2 == 0) return 'n';
    
    
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 'n';
    }
    return 'y';
}

void calc(int starting_num, int iterations) {
    for (int i = 1; i < iterations; i++) {
        cout << starting_num << " " << algorithm(starting_num) << endl;
        starting_num++;
    }
}

int main() {
    int x, y;
    cout << "starting number: ";
    cin >> x;
    cout << "ending number: ";
    cin >> y;
    
    
    auto start_time = chrono::high_resolution_clock::now();
    
    calc(x, y);
    cout << "Done" << endl;
    
    
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    double seconds = static_cast<double>(duration.count()) / 1e9;
    
    cout << "Calculation time: " << fixed << setprecision(8) << seconds << " seconds" << endl;
    
    char z;
    cout << "Write prime nums? (y/n): ";
    cin >> z;
    if (z == 'y' || z == 'Y') {
        ofstream f("prime_numbers.txt");
        for (int num = x; num <= y + 1; num++) {
            if (algorithm(num) == 'y') {
                f << num << '\n';
            }
        }
        cout << "Done" << endl;
    }
    else if (z == 'n' || z == 'N') {
        cout << "Finished" << endl;
    }
    else {
        cout << "Program Finished" << endl;
    }
    return 0;
}
