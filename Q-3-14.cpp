// 參考 https://hackmd.io/@leo361288/HyAvZAxQY

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define Min -1e9 + 9
#define Max 1e9 + 9
vector<double> intersection;
double intersect(double a, double b, double a1, double b1)
{
    return (b1 - b) / (a - a1);
}
signed main()
{
    int m, n;
    cin >> m >> n;
    vector<pii> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        k.push_back({a, b});
    }
    sort(k.begin(), k.end());
    vector<pii> line;        // store the line of max value function
    int LineNumber = 1;      // number of line in vector "line"
    line.push_back(k[0]);
    intersection.push_back(Min);
    for (int i = 1; i < m; i++)
    {
        while (1)
        {
            pii top = line.back();
            double a = top.first, b = top.second;
            double a1 = k[i].first, b1 = k[i].second;
            if (a == a1)               // if two line are parallel
            {
                if (b < b1)            // compare the y coordinate
                {
                    line.pop_back();
                    intersection.pop_back();
                    LineNumber--;
                }
                else
                    break;
            }
            else
            {
                double result = intersect(a, b, a1, b1);     // find intersection
                if (result <= intersection.back())           // if the x cooridinate of intersection is less than last one
                {                                            
                    line.pop_back();
                    intersection.pop_back();
                    LineNumber--;
                }
                else
                {
                    line.push_back(k[i]);
                    intersection.push_back(result);
                    LineNumber++;
                    break;
                }
            }
        }
    }
    intersection.push_back(Max);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        int pos = upper_bound(intersection.begin(), intersection.end(), t) - intersection.begin();
        ans += line[pos - 1].first * (int)t + line[pos - 1].second;
    }
    cout << ans << endl;
    return 0;
}