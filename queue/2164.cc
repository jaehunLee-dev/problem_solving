#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i=1; i<=n; i++)
        q.push(i);
    bool pop = true;
    while(q.size() > 1){
        if (pop){
            q.pop();        
            pop = false;
        }
        else{
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            pop = true;
        }
    }
    cout << q.front();
    return 0;
}