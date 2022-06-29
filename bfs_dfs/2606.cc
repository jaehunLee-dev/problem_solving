#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> graph;
bool visited[101];
void bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;
    while(!q.empty()){
        int src = q.front();
        q.pop();
        for (auto& i: graph[src]){
            if (!visited[i]){                            
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int com, cpl; cin >> com >> cpl;
    vector<int> v;
    for (int i=0; i<com+1; i++)
        graph.push_back(v);
    for (int i=0; i<cpl; i++){
        int src, dst; cin >> src >> dst;
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    bfs(1);
    int ans = 0;
    for (int i=0; i<com+1; i++){
        if (visited[i])
            ans++;
    }
    cout << ans-1;
    return 0;
}