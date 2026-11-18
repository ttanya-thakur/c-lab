#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;
    int count[26] = {0};

    cout << "Enter first word: ";
    cin >> s1;
    cout << "Enter second word: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "Not an Anagram" << endl;
        return 0;
    }

    for (size_t i = 0; i < s1.length(); i++) {
        char c1 = tolower(static_cast<unsigned char>(s1[i]));
        char c2 = tolower(static_cast<unsigned char>(s2[i]));

        if (c1 < 'a' || c1 > 'z' || c2 < 'a' || c2 > 'z') {
            cout << "Not an Anagram" << endl;
            return 0;
        }

        count[c1 - 'a']++;
        count[c2 - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            cout << "Not an Anagram" << endl;
            return 0;
        }
    }

    cout << "Anagram" << endl;
    return 0;
}
