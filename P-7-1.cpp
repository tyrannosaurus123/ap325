# include <bits/stdc++.h>
using namespace std;
# define int long long

vector <int> k[101];
int d[101]={0};
bool visit[101]={false};
signed main(){
    int n,m;
    int v;
    cin>>n>>m>>v;
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        k[s].push_back(t);
    }
    queue <int> vertice;
    vertice.push(v);
    int go=0;
    int sum=0;
    visit[v]=true;
    while(!vertice.empty()){
        int now=vertice.front();
        vertice.pop();
        for(int i=0;i<k[now].size();i++){
            int v1=k[now][i];
            if(visit[v1]) continue;
            visit[v1]=true;
            vertice.push(v1);
            d[v1]=d[now]+1;
            sum+=d[v1];
            go++;
        }
    }
    cout<<go<<endl<<sum<<endl;
    return 0;
}