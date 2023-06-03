#include <iostream>
#include <math.h>
using namespace std;

// Diffie-Hellman key exchange algorithm
int DiffieHellman(int p, int g, int x) {
  // Calculate the shared secret
  int sharedSecret = pow(g, x, p);

  // Return the shared secret
  return sharedSecret;
}

int main() {
  // Generate a prime number
  int p = generatePrimeNumber(1000);

  // Generate a generator
  int g = 2;

  // Alice generates a random private key
  int aliceX = rand() % p;

  // Bob generates a random private key
  int bobX = rand() % p;

  // Alice calculates the shared secret
  int aliceSharedSecret = DiffieHellman(p, g, aliceX);

  // Bob calculates the shared secret
  int bobSharedSecret = DiffieHellman(p, g, bobX);

  // Alice and Bob now share a secret that they can use to communicate securely
  cout << "Alice's shared secret: " << aliceSharedSecret << endl;
  cout << "Bob's shared secret: " << bobSharedSecret << endl;

  return 0;
}
