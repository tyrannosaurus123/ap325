# include <bits/stdc++.h>
using namespace std;
# define int long long
# define N 300
# define Max 100000000

int memo[N][N];
vector <int> num;
int min_num(int i,int j){
    if(memo[i][j]>=0) return memo[i][j];
    else if(j-i==1) return 0;
    int cost=Max;
    for(int k=i+1;k<j;k++){
        int sum=min_num(i,k)+min_num(k,j);
        sum+=num[i]*num[k]*num[j];
        cost=min(cost,sum);
    }
    return memo[i][j]=cost;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n+1;i++){
        int t;
        cin>>t;
        num.push_back(t);
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            memo[i][j]=-1;
        }
    }
    cout<<min_num(0,n)<<endl;
    return 0;
}