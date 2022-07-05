#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    int n,k; cin >> n >> k;
    for (int i=1; i<=n; i++)
        q.push(i);    
    cout << '<';
    while (!q.empty()){
        for (int i=0; i<k-1; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);            
        }
        cout << q.front(); q.pop();
        if (!q.empty())
             cout << ", ";
    }
    cout << '>';
    return 0;
}