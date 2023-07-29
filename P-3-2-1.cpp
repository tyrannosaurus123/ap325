#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
int main()
{
    io
    string s;
    stack<int> k;
    while (cin >> s)
    {
        int flag = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                k.push(s[i]);
            }
            else if (s[i] == ')')
            {
                char m = k.top();
                if (m != '(')
                {
                    flag = 0;
                    cout << "no\n";
                }
                k.pop();
            }
            else if (s[i] == ']')
            {
                char m = k.top();
                if (m != '[')
                {
                    flag = 0;
                    cout << "no\n";
                }
                k.pop();
            }
            else if (s[i] == '}')
            {
                char m = k.top();
                if (m != '{')
                {
                    cout << "no\n";
                    flag = 0;
                }
                k.pop();
            }
        }
        if (flag)
            cout << "yes" << endl;
    }
    return 0;
}