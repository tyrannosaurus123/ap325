# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
signed main(){
    io;
    int n;
    cin>>n;
    vector <int> last(n,0);
    // last will be increasing
    int len=0;
    for(int i=0;i<n;i++){
        int t,r=0;
        cin>>t;
        while(r<len && t>last[r]){
            r++;
        }
        last[r]=t;
        if(r==len) len++;
    }
    cout<<len<<endl;
    return 0;
}