#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string succ_alien(string n, string B)
{
    int base = B.size() - 1, j = 0;
    int len = n.size(), i = len - 1;
    string ans = "";
    if (len == 0 or base <= 0)
        return ans;

    map<char, int> alien_to_decimal;
    for (char c : B)
    {
        alien_to_decimal[c] = j++;
    }

    // increment from the right
    while (i >= 0 && n[i] == B[base])
    {
        ans += B[0]; //carry to the next position
        i--;
    }
    if (i < 0)
    {
        ans = B[1] + ans;
    }
    else
    {
        int index = alien_to_decimal[n[i]];
        ans = n.substr(0, i) + B[index + 1] + ans;
    }
    return ans;
}
int main()
{
    string n = "!@^&*";
    string b = "!@^&*";
    cout << n << endl;
    cout << succ_alien(n, b) << endl;
}