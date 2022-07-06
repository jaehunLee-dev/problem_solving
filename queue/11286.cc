#include <iostream>
#include <queue>
using namespace std;
struct comp{
    bool operator() (int a, int b){
        if (a+b == 0){
            return a>b;
        }
        a = abs(a);
        b = abs(b);        
        return a>b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    priority_queue< int, vector<int>, comp > pq;
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