#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("nums.txt");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int num, count = 0;
    int sum = 0, min, max;

    while (file >> num)
    {
        if (count == 0)
        {
            min = max = num;
        }
        else
        {
            if (num < min)
                min = num;
            if (num > max)
                max = num;
        }
        sum += num;
        count++;
    }

    file.close();

    if (count == 0)
    {
        cout << "No integers found in the file." << endl;
    }
    else
    {
        cout << "Count: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    }

    return 0;
}
