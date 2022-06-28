#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findDuplicate(string s)
{

    unordered_map<char, int> mp;

    for (auto i : s)
        mp[i]++;

    for (auto i : mp)
    {
        if (i.second > 1)
        {
            cout << "The Duplicate characters are : " << i.first << endl;
        }
    }
}

int main()
{

    string s;
    cout << "Enter the String : " << endl;
    cin >> s;

    findDuplicate(s);
    return 0;
}