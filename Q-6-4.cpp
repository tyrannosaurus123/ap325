# include <bits/stdc++.h>
using namespace std;
int ans[100001][2];
int main(){
    int m,n;
    cin>>m>>n;
    int a,b;
    cin>>a>>b;
    ans[0][0]=abs(a-n);
    ans[0][1]=abs(b-n);
    for(int i=1;i<m;i++){
        int a1,b1;
        cin>>a1>>b1;
        ans[i][0]=min(ans[i-1][0]+abs(a1-a),ans[i-1][1]+abs(a1-b));
        ans[i][1]=min(ans[i-1][0]+abs(b1-a),ans[i-1][1]+abs(b1-b));
        a=a1; b=b1;
    }
    if(!m) cout<<n<<endl;
    else cout<<min(ans[m-1][1],ans[m-1][0])<<endl;
    return 0;
}