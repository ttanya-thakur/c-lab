#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
string s, word;
cout << "Enter a sentence: ";
getline(cin, s);
stringstream ss(s);
string words[100];
int count = 0;
while (ss >> word)
{
words[count] = word;
count++;
}
cout << "Reversed sentence: ";
for (int i = count - 1; i >= 0; i--)
{
cout << words[i] << " ";
}
return 0;
}#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    int vowels = 0, consonants = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);

    for (char ch : s) {
        ch = tolower(static_cast<unsigned char>(ch));
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;
    return 0;
}
