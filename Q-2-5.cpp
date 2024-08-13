#include <bits/stdc++.h>
using namespace std;
#define io cin.tie(0), ios::sync_with_stdio(0);
#define int long long
int p = 1000000007;
int k[2][2] = {{1, 1}, {1, 0}}, ans[2][2] = {0};

void func(int n) {
    int tmp[2][2] = {0};
    if (n == 1) {
        ans[0][0] = 1;
        ans[0][1] = 1;
        ans[1][0] = 1;
        ans[1][1] = 0;
    } else if (n & 1) {
        func(n - 1);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int m = 0; m < 2; m++) {
                    tmp[i][j] += k[i][m] * ans[m][j];
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 00; j < 2; j++) {
                ans[i][j] = tmp[i][j] % p;
            }
        }
    } else {
        func(n / 2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int m = 0; m < 2; m++) {
                    tmp[i][j] += ans[i][m] * ans[m][j];
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 00; j < 2; j++) {
                ans[i][j] = tmp[i][j] % p;
            }
        }
    }
}
signed main() {
    int a;
    while (cin >> a) {
        if (a == -1)
            break;
        if (a == 0)
            cout << 0;
        else if (a == 1 || a == 2)
            cout << 1;
        else {
            func(a - 1);
            cout << ans[0][0];
        }
        cout << endl;
    }
    return 0;
}
