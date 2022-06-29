#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[100001];
int ans[100001];
int itr;
vector<vector<int>> graph;
void dfs(int src){
    visited[src] = true;
    ans[src] = ++itr;
    for (auto& i : graph[src]){        
        if (!visited[i])
            dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, r;
    cin >> n >> m >> r;    
    for (int i=0; i<n+1; i++){
        vector<int> v;
        graph.push_back(v);                
    }        
    for (int i=0; i<m; i++){
        int src, dst;
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    for (int i=0; i<n+1; i++){
        sort(graph[i].begin(),graph[i].end(), greater<int>());        
    }
    dfs(r);
    for (int i=1; i<n+1; i++)
        cout << ans[i] << '\n';        
    return 0;
}