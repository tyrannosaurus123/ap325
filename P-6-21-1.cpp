# include <bits/stdc++.h>
using namespace std;
# define int long long
int arr[30][30];
int memo[30][30][30][30];  // record the best for each rectangle
// rectangle= [left, top, right, bottom]
int cost(int l,int t,int r,int b){
    if(memo[l][t][r][b]>=0) return memo[l][t][r][b];
    int mcost,n0,n1,tmp;
    n0=n1=0;  // numbers of 0 and 1
    // top row
    for(int i=l;i<=r;i++){
        if(arr[t][i]==0) n0++;
        else n1++; 
    }
    mcost=cost(l,t+1,r,b)+min(n1,n0);
    // bottom row
    n0=n1=0;
    for(int i=l;i<=r;i++){
        if(arr[b][i]==0) n0++;
        else n1++; 
    }
    tmp=cost(l,t,r,b-1)+min(n1,n0);
    mcost=min(mcost,tmp);
    //  left row
    n0=n1=0;
    for(int i=t;i<=b;i++){
        if(arr[i][l]==0) n0++;
        else n1++; 
    }
    tmp=cost(l+1,t,r,b)+min(n1,n0);
    mcost=min(mcost,tmp);
    // right row
    n0=n1=0;
    for(int i=t;i<=b;i++){
        if(arr[i][r]==0) n0++;
        else n1++; 
    }
    tmp=cost(l,t,r-1,b)+min(n1,n0);
    mcost=min(mcost,tmp);
    memo[l][t][r][b] = mcost;
    return mcost;
}
signed main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int l=0;l<n;l++){  //left
        for(int r=l;r<n;r++){  //right
            for(int t=0;t<m;t++){  //top
                for(int b=t;b<m;b++){  // bottom
                    memo[l][t][r][b]= (r==l || b==t) ? 0 : -1;
                }
            }
        }
    }
    cout<<cost(0,0,n-1,m-1)<<endl;
    return 0;
}