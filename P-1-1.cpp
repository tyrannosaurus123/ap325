#include <bits/stdc++.h>
using namespace std;
#define int long long
int eval()
{
    string s;
    cin >> s;
    if (s[0] == 'f')
    {
        int x = eval();
        return 2 * x - 1;
    }
    else if (s[0] == 'g')
    {
        int x = eval();
        int y = eval();
        return x + 2 * y - 3;
    }
    else
        return stoll(s);
}
signed main()
{
    cout << eval() << endl;
    return 0;
}