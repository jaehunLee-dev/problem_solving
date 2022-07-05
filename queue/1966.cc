#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t; cin >> t;
    for (int i=0; i<t; i++){
        int imp, ans = 0;        
        int n, m; cin >> n >> m;
        queue<pair<int,bool>> q;
        priority_queue<int> pq;
        for (int j=0; j<n; j++){
            cin >> imp;
            pq.push(imp);
            if (j == m) q.push(make_pair(imp,true));
            else q.push(make_pair(imp,false));
        }
        while(1){            
            int turn = pq.top();
            int tmp = q.front().first;
            bool tmp_b = q.front().second;
            q.pop();
            if(tmp == turn){    //뽑아야할 차례
                ans++;
                pq.pop();
                if (tmp_b){
                    cout << ans << '\n';
                    break;
                }                
            }
            else    
                q.push(make_pair(tmp,tmp_b));
        }
    }
    return 0;
}