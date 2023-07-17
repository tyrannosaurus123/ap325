#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
using ll = long long;
ll eval()
{
    string s;
    cin >> s;
    if (s[0] == 'f')
    {
        int x = eval();
        return 2 * x - 3;
    }
    else if (s[0] == 'g')
    {
        int x = eval();
        int y = eval();
        return 2 * x + y - 7;
    }
    else if (s[0] == 'h')
    {
        int x = eval();
        int y = eval();
        int z = eval();
        return 3 * x - 2 * y + z;
    }
    else
    {
        return stoll(s);
    }
}
int main()
{
    io;
    cout << eval();
    return 0;
}