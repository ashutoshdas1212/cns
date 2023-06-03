#include <iostream>
#include <math.h>
using namespace std;

// Function to generate two random prime numbers
int generatePrimeNumber(int n) {
  int prime = 2;
  while (true) {
    bool isPrime = true;
    for (int i = 2; i <= sqrt(prime); i++) {
      if (prime % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      return prime;
    }
    prime++;
  }
}

// Function to calculate the public and private keys
void generateKeys(int p, int q, int &e, int &d) {
  int n = p * q;
  int phi = (p - 1) * (q - 1);

  // Find a value for e such that it is coprime to phi and e > 1
  for (e = 2; e < phi; e++) {
    if (gcd(e, phi) == 1) {
      break;
    }
  }

  // Calculate the private key d
  d = modInverse(e, phi);
}

// Function to encrypt a message
int encrypt(int message, int e, int n) {
  return pow(message, e) % n;
}

// Function to decrypt a message
int decrypt(int ciphertext, int d, int n) {
  return pow(ciphertext, d) % n;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
  return pow(a, m - 2, m);
}

int main() {
  // Generate two random prime numbers
  int p = generatePrimeNumber(1000);
  int q = generatePrimeNumber(1000);

  // Calculate the public and private keys
  int e, d;
  generateKeys(p, q, e, d);

  // Encrypt a message
  int message = 1234;
  int ciphertext = encrypt(message, e, p * q);

  // Decrypt the message
  int decryptedMessage = decrypt(ciphertext, d, p * q);

  // Print the message
  cout << "Original message: " << message << endl;
  cout << "Encrypted message: " << ciphertext << endl;
  cout << "Decrypted message: " << decryptedMessage << endl;

  return 0;
}
