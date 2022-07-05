#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    priority_queue< int, vector<int>, greater<int> > pq;
    while(n--){
        int tmp; cin >> tmp;
        if (tmp == 0){
            if (pq.empty()){
                cout << "0\n";
            }            
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }                
        }
        else
            pq.push(tmp);        
    }
    return 0;
}