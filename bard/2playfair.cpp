#include <iostream>
#include <string>

using namespace std;

void encryptPlayfair(string plainText, string key, string& cipherText) {
  // Convert the plain text to lowercase.
  for (int i = 0; i < plainText.length(); i++) {
    plainText[i] = tolower(plainText[i]);
  }

  // Create a 5x5 key square.
  char keySquare[5][5];
  int index = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      keySquare[i][j] = key[index];
      index++;
    }
  }

  // Encrypt the plain text.
  for (int i = 0; i < plainText.length(); i += 2) {
    // Get the two letters in the current pair.
    char letter1 = plainText[i];
    char letter2 = plainText[i + 1];

    // Check if the two letters are the same.
    if (letter1 == letter2) {
      // If they are, add 'z' to the first letter and encrypt that.
      letter1 += 'z' - letter1;
    }

    // Find the coordinates of the two letters in the key square.
    int row1 = -1, col1 = -1;
    int row2 = -1, col2 = -1;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (keySquare[i][j] == letter1) {
          row1 = i;
          col1 = j;
        } else if (keySquare[i][j] == letter2) {
          row2 = i;
          col2 = j;
        }
      }
    }

    // If the two letters are in the same row, encrypt them by moving one letter to the right.
    if (row1 == row2) {
      if (col1 + 1 < 5) {
        col1++;
      } else {
        col1 = 0;
      }
      cipherText += keySquare[row1][col1];
      cipherText += keySquare[row2][col2];
    } else if (col1 == col2) {
      if (row1 + 1 < 5) {
        row1++;
      } else {
        row1 = 0;
      }
      cipherText += keySquare[row1][col1];
      cipherText += keySquare[row2][col2];
    } else {
      cipherText += keySquare[row1][col2];
      cipherText += keySquare[row2][col1];
    }
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
  encryptPlayfair(plainText, key, cipherText);

  // Print the cipher text.
  cout << "The cipher text is: " << cipherText << endl;

  return 0;
}
