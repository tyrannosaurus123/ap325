# include <bits/stdc++.h>
using namespace std;
# define int long long
int broad[15][15];    // 1 base
int p[15]={0};    // 1 base
int rec(int n,int maxn,int k){
    if(k>n) return maxn;
    bool valid[n+1];
    int cmp=0;
    cmp=max(rec(n,maxn,k+1),cmp);   // no queen be put in this row , continues to reccursion
    for(int i=1;i<=n;i++) valid[i]=true;    //  else a queen be put in this row
    for(int i=1;i<k;i++){
        if(!p[i]) continue;
        valid[p[i]]=false;           // the same column
        int cmp1=k-i+p[i];
        if(cmp1<=n) valid[cmp1]=false;    // k-i  ≠ abs(p[k]-p[i]) where p[k]=cmp1、cmp2
        int cmp2=p[i]-k+i;
        if(cmp2>=1) valid[cmp2]=false;
    }
    for(int i=1;i<=n;i++){
        if(valid[i]){
            p[k]=i;
            cmp=max(rec(n,maxn+broad[k][i],k+1),cmp);
            p[k]=0;   // p[k] return to 0
        }
    }
    return cmp;
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>broad[i][j];
        }
    }
    cout<<rec(n,0,1);
    return 0;
}