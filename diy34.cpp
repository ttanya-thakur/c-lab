#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Apple", 30},
        {"Banana", 10},
        {"Mango", 20},
        {"Orange", 5},
        {"Grapes", 15}
    };

    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    cout << "Sorted pairs:\n";
    for (const auto& p : v) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}