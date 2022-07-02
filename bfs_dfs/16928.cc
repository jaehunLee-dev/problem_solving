#include <iostream>
#include <queue>
using namespace std;
int ans[101];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin>>n>>m;
    int board[101];        
    for (int i=0; i<101; i++)
        board[i] = i;
    for (int i=0; i<n+m; i++){
        int cur, next;
        cin >> cur >> next;
        board[cur] = next;
    }
    queue<int> q;
    q.push(1);
    bool out = false;
    while (!q.empty()){
        int cur = q.front();
        q.pop();        
        for (int i=1; i<=6; i++){
            if (ans[board[cur+i]] == 0){
                ans[board[cur+i]] = ans[cur]+1;
                q.push(board[cur+i]);
                if (board[cur+i] == 100){
                    out = true;
                    break;
                }
            }
        }
        if (out) break;
    }
    cout << ans[100];
    return 0;
}