#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void succ_alien(string &n, string B)
{
    int base = B.size() - 1, j = 0;
    int len = n.size(), i = len - 1;
    if (len == 0 or base == 0)
        return;
    // increment from the right
    while (i >= 0 && n[i] == B[base])
    {
        n[i] = B[0];  //carry to the next position
        i--;
    }
    if (i < 0)
    {
        n = B[1] + n;
    }
    else
    {
        int index;
        for (; j <= base; j++)
        {
            if (B[j] == n[i])
            {
                index = j;
                break;
            }
        }
        n[i] = B[index + 1];
    }
}
int main()
{
    string n = "!@^&*";
    string b = "!@^&*";
    cout << n << endl;
    succ_alien(n, b);
    cout << n << endl;
}