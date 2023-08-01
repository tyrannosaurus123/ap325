# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 200010
# define io cin.tie(0),ios::sync_with_stdio(0);
int cnt[N]={0};
vector <int> k,c,d;
int func(int n,int len){    // max num of color of window size len
    if(len>n) return N;     // if len over n , return
    int left=0;
    int maxn=0,tmp=0;
    for(int i=0;i<len;i++){
        if(++cnt[k[i]]==1) tmp++;
    }
    maxn=tmp;
    for(int i=0,j=len;j<n;i++,j++){
        if(++cnt[k[j]]==1) tmp++;
        if(--cnt[k[i]]==0) tmp--;
        maxn=max(maxn,tmp);
    }
    memset(cnt,0,sizeof(cnt));
    return maxn;
}
signed main(){
    int n,sum=1;
    cin>>n;
    for(int i=0;i<n;i++){
        int t; cin>>t;
        k.push_back(t);
        c.push_back(t);
    }
    sort(c.begin(),c.end());
    d.push_back(c[0]);
    for(int i=1;i<n;i++){
        if(c[i]!=c[i-1]){
            d.push_back(c[i]);
            sum++;
        }
    }
    for(int i=0;i<n;i++){
        k[i]=lower_bound(d.begin(),d.end(),k[i])-d.begin();
    }
    if(sum==1) cout<<1<<endl;
    else{
        int length=1;
        for(int jump=n/2;jump>0;jump/=2){
            while(func(n,length+jump)<sum){   // length + jump may over n
                length+=jump;
            }
        }
        cout<<length+1<<endl;
    }
    return 0;
}