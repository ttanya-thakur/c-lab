#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    long long product = accumulate(v.begin(), v.end(), 1LL, [](long long result, int x) {
        return result * x;
    });

    int evenSum = accumulate(v.begin(), v.end(), 0, [](int sum, int x) {
        return (x % 2 == 0) ? sum + x : sum;
    });

    cout << "Product of all elements: " << product << endl;
    cout << "Sum of even elements: " << evenSum << endl;
    return 0;
}