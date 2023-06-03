#include <iostream>
#include <string>

using namespace std;

string rail_fence_cipher(string text, int n) {
  // Create a matrix to store the ciphertext.
  char rail[n][text.length()];

  // Initialize the matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < text.length(); j++) {
      rail[i][j] = ' ';
    }
  }

  // Encrypt the text.
  int row = 0, col = 0;
  bool down = true;
  for (char c : text) {
    rail[row][col] = c;
    col++;
    if (col == n) {
      row++;
      col = 0;
      down = !down;
    }
  }

  // Convert the matrix to a string.
  string ciphertext;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < text.length(); j++) {
      if (rail[i][j] != ' ') {
        ciphertext += rail[i][j];
      }
    }
  }

  return ciphertext;
}

int main() {
  string text;
  int n;

  // Get the text and the number of rails.
  cout << "Enter the text: ";
  getline(cin, text);
  cout << "Enter the number of rails: ";
  cin >> n;

  // Encrypt the text.
  string ciphertext = rail_fence_cipher(text, n);

  // Display the ciphertext.
  cout << "The ciphertext is: " << ciphertext << endl;

  return 0;
}
