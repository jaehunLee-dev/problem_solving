#include <iostream>
#include <queue>
using namespace std;
int visited[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k; cin >> n >> k;
    int ans = 0;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (1){
        int tmp = q.front();
        q.pop();
        if (tmp == k){
            cout << visited[tmp] -1;
            break;
        }
        if (tmp-1 >=0 && visited[tmp-1] == 0){
            q.push(tmp-1);
            visited[tmp-1] = visited[tmp]+1;
        }
        if (tmp+1<=100000 && visited[tmp+1] == 0){
            q.push(tmp+1);
            visited[tmp+1] = visited[tmp]+1;
        }
        if (tmp*2<=100000 && visited[tmp*2] == 0){
            q.push(tmp*2);
            visited[tmp*2] = visited[tmp]+1;
        }        
    }
    return 0;
}