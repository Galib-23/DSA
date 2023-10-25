/*
    Sieve algorithm is generally used to find number of prime numbers in a definite range
    Lets say we wanna find number of primes between  1-12.
    Now lets make an array: 1 2 3 4 5 6 7 8 9 10 11 12
    firstly consider all T: T T T T T T T T T T T T
    Now start taking
    the multiples : for 2 : T T T F T F T F T F T F
    Multiples of 3        : T T T F T F T F F F T F
    NOW MARK 1 AS F :       F T T F T F T F F F T F
    So the True are the Primes. We conducted the operation
    upto sqrt(12) = 3.xxx
*/
#include <bits/stdc++.h>
using namespace std;

bool* sieveOfEratoSthenes(int n) {
    bool* isPrime = new bool[n + 1]; // Dynamic array to store primes
    fill(isPrime, isPrime + n + 1, true); // Initialize all elements as true

    int lim = sqrt(n);
    for (int i = 2; i <= lim; i++) {
        if (isPrime[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    int n;
    cout << "Enter the limit: ";
    cin >> n;

    bool* isPrime = sieveOfEratoSthenes(n);

    // Printing prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " is prime." << endl;
        }
    }

    delete[] isPrime; // Don't forget to free the dynamically allocated array

    return 0;
}
