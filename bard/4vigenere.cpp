#include <iostream>
#include <string>

using namespace std;

void encryptVigenere(string plainText, string key, string& cipherText) {
  // Convert the plain text to uppercase.
  for (int i = 0; i < plainText.length(); i++) {
    plainText[i] = toupper(plainText[i]);
  }

  // Encrypt the plain text.
  for (int i = 0; i < plainText.length(); i++) {
    // Get the current letter in the plain text and the key.
    char letter1 = plainText[i];
    char letter2 = key[i % key.length()];

    // Encrypt the letter by adding the two letters together modulo 26.
    char encryptedLetter = (letter1 + letter2 - 'A' + 26) % 26;

    // Add the encrypted letter to the cipher text.
    cipherText += encryptedLetter;
  }
}

int main() {
  // Get the plain text and key from the user.
  string plainText;
  cout << "Enter the plain text: ";
  getline(cin, plainText);

  string key;
  cout << "Enter the key: ";
  getline(cin, key);

  // Encrypt the plain text.
  string cipherText;
  encryptVigenere(plainText, key, cipherText);

  // Print the cipher text.
  cout << "The cipher text is: " << cipherText << endl;

  return 0;
}
