#include <iostream>
#include <string>

using namespace std;

void encryptHill(string plainText, string key, string& cipherText) {
  // Convert the plain text to uppercase.
  for (int i = 0; i < plainText.length(); i++) {
    plainText[i] = toupper(plainText[i]);
  }

  // Get the key matrix.
  int keyMatrix[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      keyMatrix[i][j] = key[i * 3 + j] - 'A';
    }
  }

  // Encrypt the plain text.
  for (int i = 0; i < plainText.length(); i += 3) {
    // Get the three letters in the current block.
    int letter1 = plainText[i] - 'A';
    int letter2 = plainText[i + 1] - 'A';
    int letter3 = plainText[i + 2] - 'A';

    // Encrypt the three letters using the key matrix.
    int encryptedLetter1 = (letter1 * keyMatrix[0][0] + letter2 * keyMatrix[1][0] + letter3 * keyMatrix[2][0]) % 26;
    int encryptedLetter2 = (letter1 * keyMatrix[0][1] + letter2 * keyMatrix[1][1] + letter3 * keyMatrix[2][1]) % 26;
    int encryptedLetter3 = (letter1 * keyMatrix[0][2] + letter2 * keyMatrix[1][2] + letter3 * keyMatrix[2][2]) % 26;

    // Add the encrypted letters to the cipher text.
    cipherText += (char)('A' + encryptedLetter1);
    cipherText += (char)('A' + encryptedLetter2);
    cipherText += (char)('A' + encryptedLetter3);
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
  encryptHill(plainText, key, cipherText);

  // Print the cipher text.
  cout << "The cipher text is: " << cipherText << endl;

  return 0;
}
