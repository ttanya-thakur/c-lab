#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> freq;
    string word;

    cout << "Enter words (type END to stop):" << endl;
    while (cin >> word && word != "END") {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";
    string mostFrequent;
    int maxCount = 0;

    for (const auto& p : freq) {
        cout << p.first << " : " << p.second << endl;
        if (p.second > maxCount) {
            maxCount = p.second;
            mostFrequent = p.first;
        }
    }

    if (!freq.empty()) {
        cout << "\nMost frequent word: " << mostFrequent << endl;
        cout << "Count: " << maxCount << endl;
    } else {
        cout << "No words entered." << endl;
    }

    return 0;
}