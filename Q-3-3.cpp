#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> num;
    stack<char> op;
    num.push(s[0] - '0');
    for (int i = 1; i < s.size(); i += 2)
    {
        char k = s[i];
        int t = s[i + 1] - '0';
        if (k == '*')
        {
            int tmp = num.top();
            num.pop();
            num.push(tmp * t);
        }
        else if (k == '/')
        {
            int tmp = num.top();
            num.pop();
            num.push(tmp / t);
        }
        else if (k == '+' || k == '-')
        {
            if (op.empty())
            {
                op.push(k);
                num.push(t);
            }
            else
            {
                char top = op.top();
                op.pop();
                int num2 = num.top();
                num.pop();
                int num1 = num.top();
                num.pop();
                if (top == '+')
                {
                    num.push(num1 + num2);
                }
                else
                    num.push(num1 - num2);
                op.push(k);
                num.push(t);
            }
        }
    }
    while (!op.empty())
    {
        char top = op.top();
        op.pop();
        int num2 = num.top();
        num.pop();
        int num1 = num.top();
        num.pop();
        if (top == '+')
        {
            num.push(num1 + num2);
        }
        else
            num.push(num1 - num2);
    }
    cout << num.top() << endl;
    return 0;
}