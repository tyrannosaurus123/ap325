# include <bits/stdc++.h>
using namespace std;
# define int long long
# define io cin.tie(0),ios::sync_with_stdio(0)
int num[200010];
signed main(){
    io;
    int n;
    cin>>n;
    vector <int> lis(n,1);
    for(int i=0;i<n;i++){
        cin>>num[i];
        for(int j=0;j<i;j++){
            if(num[i]>num[j]){
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    cout<<*max_element(lis.begin(),lis.end())<<endl;
    return 0;
}