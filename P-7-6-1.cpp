//P-7-6 longest and shortest path on dag O(m+n), non-recursive
#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define oo 1000000000
signed main(){
    vector<pair<int,int>> adj[N]; // (neighbor, length)
    int indeg[N]={0};
    int n, m, source, goal;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &source, &goal);
    for (int i=0; i<m; i++) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        adj[from].push_back({to,w});
        indeg[to]++;
    }
    queue<int> Q;
    int d[N], p[N], cnt=0; // min and max distance
    for (int i=0;i<n;i++) d[i] = oo;
    for (int i=0;i<n;i++) p[i] = -oo;
    d[source] = p[source] = 0;
    // push all indeg==0
    for (int i=0;i<n;i++)
    if (indeg[i]==0) Q.push(i);
    while (!Q.empty()) { // until queue is empty
        int v=Q.front();
        Q.pop(); cnt++;
        // check if dag, so disable the following two lines
        //if (d[v]==oo) continue; // useless
        //if (v==goal) break;
        for (auto e: adj[v]) {
            if(d[v]<oo){
                d[e.first] = min(d[e.first], d[v] + e.second);
                p[e.first] = max(p[e.first], p[v] + e.second);
            }
            if (--indeg[e.first] ==0)
            Q.push(e.first);
        }
    }
    // output
    if (cnt!=n) fprintf(stderr, "Not a dag, %d < %d\n", cnt, n);
    if (d[goal]==oo) printf("No path\nNo path\n");
    else printf("%d\n%d\n", d[goal], p[goal]);
    return 0;
}