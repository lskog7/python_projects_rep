#include <iostream>
#include <cmath>

// Function to check if a number is prime
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::cout << "Prime numbers of the form (2^n - 1)^2 - 2 with up to 100 characters:" << std::endl;
    long long n = 1;
    while (true) {
        long long mersennePrime = std::pow(2, n) - 1;
        long long carolPrime = std::pow(mersennePrime, 2) - 2;
        if (isPrime(carolPrime)) {
            std::string carolStr = std::to_string(carolPrime);
            if (carolStr.size() <= 100) {
                std::cout << carolPrime << std::endl;
            } else {
                break; // Break the loop if number exceeds 100 characters
            }
        }
        ++n;
    }

    return 0;
}