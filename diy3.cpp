#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, word;
    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    cout << "Reversed sentence: ";
    for (int i = static_cast<int>(words.size()) - 1; i >= 0; i--) {
        cout << words[i] << (i > 0 ? " " : "");
    }
    cout << endl;

    return 0;
}
