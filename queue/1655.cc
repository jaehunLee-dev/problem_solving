#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    priority_queue<int> max_h;
    priority_queue<int,vector<int>,greater<int>> min_h;
    bool max_turn = true;    
    while(n--){        
        int tmp; cin >> tmp;
        if (max_turn)      
            max_h.push(tmp);        
        else
            min_h.push(tmp);                
        max_turn = !max_turn;
        if (!max_h.empty() && !min_h.empty() && max_h.top() > min_h.top()){
            int tmp1 = max_h.top(), tmp2 = min_h.top();
            max_h.pop(); min_h.pop();
            max_h.push(tmp2); min_h.push(tmp1);
        }        
        cout << max_h.top() << '\n';
    }
    return 0;
}