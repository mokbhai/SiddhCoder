#include <iostream>

long MOD = 1000000007;

// Function to calculate (x - y) % M
int modSub(int x, int y, int M) { 
    int res = (x % M) - (y % M); 
    if (res < 0) 
        res += M; 
    return res % M;
}

// Function to calculate (x + y) % M
int modAdd(int x, int y, int M) { 
    return ((x % M) + (y % M)) % M; 
}

// Function to calculate (x * y) % M
int modMul(long x, long y, long M) { 
    return ((x % M) * (y % M)) % M; 
}

// Function to calculate (x / y) % M using long long for division and modulus operations
int modDiv(int x, int y, int M) { 
    // Ensure x is within the range [0, M-1] for division
    x %= M;

    long long quotient = 0;
    while (x >= y) {
        quotient *= 2; // Double the quotient
        y <<= 1; // Multiply y by 2
    }

    int result = 0; // Use long long to handle large intermediate results

    while (quotient > 0 && x > 0) {
        if (x >= y) { // If x is greater than or equal to y, subtract y from x
            x -= y;
            result += quotient;
        }
        quotient >>= 1; // Divide the quotient by 2
        y >>= 1; // Divide y by 2
    }

    return static_cast<int>(result); // Cast the result back to int since we are dealing with integers
}


// Function to calculate modular inverse of a number
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}