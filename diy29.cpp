#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string line;
    int lineNumber = 1;

    if (!fin)
    {
        cout << "Error opening input file!";
        return 1;
    }
    if (!fout)
    {
        cout << "Error opening output file!";
        return 1;
    }

    while (getline(fin, line))
    {
        fout << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    fin.close();
    fout.close();

    cout << "File copied successfully with line numbers.";
    return 0;
}
