#include <deque>
#include <iostream>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    deque<int> dq;
    for (int i=1; i<=n; i++)
        dq.push_back(i);
    int ans = 0;
    while(m--){
        int tmp; cin >> tmp;
        int idx;
        for (int i=0; i<dq.size(); i++){
            if (dq[i] == tmp){
                idx = i;
                break;
            }
        }
        if (idx <= dq.size()/2){ //앞이랑 가까움
            while (dq.front() != tmp){
                int chg = dq.front();
                dq.pop_front();
                dq.push_back(chg);
                ans++;
            }            
            dq.pop_front();
        }
        else{
            while (dq.front() != tmp){
                int chg = dq.back();
                dq.pop_back();
                dq.push_front(chg);
                ans++;
            }
            dq.pop_front();
        }
    }
    cout << ans;
    return 0;
}