// 4-PracticeQues/CountPrimeNumbersCutNonCutAlgo.h
// In this file, we will implement a function to count prime numbers within a given range using cut and non-cut algorithms.
// Time complexity: O(n * log(log n))
// Space complexity: O(n)

#include <vector>
#include <iostream>
using namespace std;

#define ll long long int

vector<ll> listAllPrimesTillN(int num) {
    vector<bool> numbers(num + 1, false);
    vector<ll> primes;

    numbers[0] = true;
    
    for (ll i = 2; i <= num; i++) {
        if (!numbers[i]) {
            primes.push_back(i);
            for (ll j = i; j * i < num + 1; j++) {
                numbers[j * i] = true;
            }
        }
    }

    return primes;
}

int main2() {
    ll n;
    // cout << "Enter the number of integers: ";
    // cin >> n;

    n = 1e7;

    vector<ll> primes = listAllPrimesTillN(n);
    cout << "The prime numbers are: ";
    for (ll i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }

    return 0;
}


// for efficent query we can use sieve of eratosthenes
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000000

// Function to precompute the number of primes up to MAX_N
void sieve(vector<int>& primeCount) {
    vector<bool> isPrime(MAX_N + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    // Fill the primeCount array
    for (int i = 1; i <= MAX_N; i++) {
        primeCount[i] = primeCount[i - 1] + (isPrime[i] ? 1 : 0);
    }
}

int main() {
    int t;
    cin >> t;

    vector<int> primeCount(MAX_N + 1, 0);
    sieve(primeCount); // Precompute the prime counts

    while (t--) {
        int n;
        cin >> n;
        cout << primeCount[n] << endl; // Output the count of primes <= N
    }

    return 0;
}