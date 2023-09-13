#include<iostream>
#include<string>
#include<vector>
using namespace std;

char crossWord[10][10];

bool canPlaceWordHorizontally(string word, int row, int col) {
    int wordLen = word.size();
    // Check if the word fits horizontally and doesn't overlap
    if (col + wordLen > 10) return false;
    for (int i = 0; i < wordLen; i++) {
        if (crossWord[row][col + i] != '-' && crossWord[row][col + i] != word[i]) {
            return false;
        }
    }
    return true;
}

bool canPlaceWordVertically(string word, int row, int col) {
    int wordLen = word.size();
    // Check if the word fits vertically and doesn't overlap
    if (row + wordLen > 10) return false;
    for (int i = 0; i < wordLen; i++) {
        if (crossWord[row + i][col] != '-' && crossWord[row + i][col] != word[i]) {
            return false;
        }
    }
    return true;
}

void placeWordHorizontally(string word, int row, int col) {
    int wordLen = word.size();
    for (int i = 0; i < wordLen; i++) {
        crossWord[row][col + i] = word[i];
    }
}

void placeWordVertically(string word, int row, int col) {
    int wordLen = word.size();
    for (int i = 0; i < wordLen; i++) {
        crossWord[row + i][col] = word[i];
    }
}

void placeWords(string* words, int wordCount, int wordIndex) {
    if (wordIndex == wordCount + 1) {
        // All words placed, print the crossword grid
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << crossWord[i][j];
            }
            cout << endl;
        }
        return;
    }

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (canPlaceWordHorizontally(words[wordIndex], row, col)) {
                placeWordHorizontally(words[wordIndex], row, col);
                placeWords(words, wordCount, wordIndex + 1);
                // Backtrack
                for (int i = 0; i < words[wordIndex].size(); i++) {
                    crossWord[row][col + i] = '-';
                }
            }

            if (canPlaceWordVertically(words[wordIndex], row, col)) {
                placeWordVertically(words[wordIndex], row, col);
                placeWords(words, wordCount, wordIndex + 1);
                // Backtrack
                for (int i = 0; i < words[wordIndex].size(); i++) {
                    crossWord[row + i][col] = '-';
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> crossWord[i][j];
        }
    }

    string input;
    cin >> input;

    string* words = new string[10];
    int wordCount = 0;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ';') {
            wordCount++;
        } else {
            words[wordCount] += input.at(i);
        }
    }

    // for (int i = 0; i <= wordCount; i++) {
    //     cout << words[i] << endl;
    // }

    placeWords(words, wordCount, 0);

    return 0;
}
