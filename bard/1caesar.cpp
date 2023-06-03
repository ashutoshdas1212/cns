#include <iostream>
#include <string>

using namespace std;

string encryptCaesar(string plainText, int shift) {
  // Convert the plain text to uppercase.
  for (int i = 0; i < plainText.length(); i++) {
    plainText[i] = toupper(plainText[i]);
  }

  // Encrypt the plain text.
  string cipherText = "";
  for (char c : plainText) {
    // Get the index of the current character in the alphabet.
    int index = c - 'A';

    // Encrypt the character by shifting it by the specified amount.
    index += shift;
    if (index >= 26) {
      index -= 26;
    }

    // Add the encrypted character to the cipher text.
    cipherText += (char)('A' + index);
  }

  return cipherText;
}

int main() {
  // Get the plain text and shift from the user.
  string plainText;
  cout << "Enter the plain text: ";
  getline(cin, plainText);

  int shift;
  cout << "Enter the shift: ";
  cin >> shift;

  // Encrypt the plain text.
  string cipherText = encryptCaesar(plainText, shift);

  // Print the cipher text.
  cout << "The cipher text is: " << cipherText << endl;

  return 0;
}
