# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 100010
const int maxn=1e18+1;
signed main(){
    int n,l,i, c[N],h[N];
    int total=0, high=0;
    stack<int> S;
    scanf("%lld %lld",&n,&l);
    c[0]=0;
    h[0]=maxn;
    c[n+1]=l;
    h[n+1]=maxn;
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&h[i]);
    }
    S.push(0);
    for(int i=1;i<=n;i++){
        if(c[i]-h[i]>=c[S.top()] || c[i]+h[i]<=c[i+1]){
            total++;
            high = max(high, h[i]);
            while (c[S.top()]+h[S.top()]<=c[i+1]) {
                total++; 
                high = max(high, h[S.top()]);
                S.pop();
            }
        }
        else S.push(i);
    }
    printf("%lld\n%lld\n", total,high);
    return 0;
}