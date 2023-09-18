// 參考https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/

# include <bits/stdc++.h>
using namespace std;
# define int long long
# define Max 100000
int d[20][20];
int memo[20][1<<17];
int m,n;
int func(int i,int mask){
    if(mask==((1<<i) | 1)){
        return d[0][i];
    }
    else if(memo[i][mask]!=0){
        return memo[i][mask];
    }
    int res=Max;

    // we have to travel all nodes j in mask and end the
    // path at ith node so for every node j in mask,
    // recursively calculate cost of travelling all nodes in
    // mask except i and then travel back from node j to
    // node i taking the shortest path take the minimum of
    // all possible j nodes
    
    for(int j=0;j<m;j++){
        if((mask & (1<<j)) && (j!=i) && (j!=0)){    // 0 will always be kept
            res=min(res,func(j,mask & (~(1<<i)))+d[j][i]);
        }
    }
    return memo[i][mask]=res;
}
signed main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    int ans=Max;
    for(int i=1;i<m;i++){
        ans=min(ans,func(i,(1<<m)-1)+d[i][0]); 
    }
    cout<<ans<<endl;
    return 0;
}