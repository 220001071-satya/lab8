#include <bits/stdc++.h>
using namespace std;

int Find(int u, vector<int>& parent){
    if(u == parent[u]) return u;
    parent[u] = Find(parent[u], parent);
    return parent[u];
}
bool Union(int u, int v, vector<int>& parent, vector<int>& rank){
    int x = Find(u, parent);
    int y = Find(v, parent);
    if(x == y) return false;
    if(rank[x] > rank[y]) parent[y] = x;
    else if(rank[y] > rank[x]) parent[x] = y;
    else {
        parent[y] = x;
        rank[x]++;
    }
    return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(m), rank(m, 0);
    for(int i = 0; i < m; i++) parent[i] = i;
    vector<vector<int>> edges(n, vector<int> (3)), ans;
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    int val = 0, count = 0;
    sort(edges.begin(), edges.end());
    for(auto edge : edges){
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];
        if(Union(u, v, parent, rank)) {
            val += w;
            ans.push_back({u, v});
            count++;
            if(count > m - 1) break;
        }
    }
    cout << val <<endl;
    for(auto edge : ans){
        cout << edge[0] << " " << edge[1] << endl;
    }

}