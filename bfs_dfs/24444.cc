#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> graph;
int ans[100001];
bool visited[100001];
int itr;
void bfs(int r){
    queue<int> q;
    q.push(r);    
    visited[r] = true;
    ans[r] = ++itr;
    while(!q.empty()){
        int src = q.front();
        q.pop();                              
        for (auto& i : graph[src]){
            if (!visited[i]){
                visited[i] = true;
                ans[i] = ++itr;
                q.push(i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, r;
    cin >> n >> m >> r;    
    vector<int> v;
    for (int i=0; i<n+1; i++)
        graph.push_back(v);
    for (int i=0; i<m; i++){
        int src, dst; cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }    
    for (int i=0; i<n+1; i++){
        sort(graph[i].begin(),graph[i].end(), greater<int>());
    }
    bfs(r);
    for (int i=1; i<n+1; i++)
        cout << ans[i] << '\n';
    return 0;
}