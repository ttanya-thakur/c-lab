#include <iostream>
#include <string>
using namespace std;
int main()
{
string s1, s2;
int count[26] = {0};
cout << "Enter first word: ";
cin >> s1;
cout << "Enter second word: ";
cin >> s2;
if (s1.length() != s2.length())
{
cout << "Not an Anagram";
return 0;
}
for (int i = 0; i < s1.length(); i++)
{
count[s1[i] - 'a']++;
count[s2[i] - 'a']--;
}
for (int i = 0; i < 26; i++)
{
if (count[i] != 0)
{
cout << "Not an Anagram";
return 0;
}
} 
cout << "Anagram";
return 0;
}