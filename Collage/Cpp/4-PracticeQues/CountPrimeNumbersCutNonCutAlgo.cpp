// 4-PracticeQues/CountPrimeNumbersCutNonCutAlgo.h
// In this file, we will implement a function to count prime numbers within a given range using cut and non-cut algorithms.
// Time complexity: O(n * log(log n))
// Space complexity: O(n)
#include <iostream>
using namespace std;

#define ll long long int

vector<ll> isPrime(int num) {
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

int main() {
    ll n;
    // cout << "Enter the number of integers: ";
    // cin >> n;

    n = 1e7;

    vector<ll> primes = isPrime(n);
    cout << "The prime numbers are: ";
    for (ll i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }

    return 0;
}

