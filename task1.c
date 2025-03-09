#include<iostream>
#include<vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to execute Sieve of Eratosthenes
void sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Uncomment below to print primes (for debugging or small N)
    /*
    cout << "Prime numbers up to " << N << ":\n";
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
    */
}

int main() {
    int N = 1000000; // Change this to test with different values

    auto start = high_resolution_clock::now();
    
    sieveOfEratosthenes(N);

    auto end = high_resolution_clock::now();
    duration<double> execTime = end - start; // Now in seconds

    cout << "Execution Time: " << execTime.count() << " seconds\n";

    return 0;
}