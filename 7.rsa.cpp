#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  int t;
  while (1) {
    t = a % b;
    if (t == 0)
      return b;
    a = b;
    b = t;
  }
}

int main() {
  // 2 random prime numbers
  int p = 13;
  int q = 11;
  int n = p * q; // calculate n
  int track;
  int phi = (p - 1) * (q - 1); // calculate phi
  // public key
  // e stands for encrypt
  int e = 7;
  // for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
  while (e < phi) {
    track = gcd(e, phi);
    if (track == 1)
      break;
    else
      e++;
  }
  // private key
  // d stands for decrypt
  // choosing d such that it satisfies d*e = 1 mod phi
  double d1 = 1.0 / e;
  int d = fmod(d1, phi);
  int message = 9;
  int c = pow(message, e); // encrypt the message
  int m = pow(c, d);
  c = fmod(c, n);
  m = fmod(m, n);
  cout << "Original Message = " << message << endl;
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;
  cout << "n = pq = " << n << endl;
  cout << "phi = " << phi << endl;
  cout << "e = " << e << endl;
  cout << "d = " << d << endl;
  cout << "Encrypted message = " << c << endl;
  cout << "Decrypted message = " << m << endl;
  return 0;
}
