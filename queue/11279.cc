#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v;
    while(n--){
        int tmp; cin >> tmp;
        if (tmp == 0){
            if (v.empty()){
                cout << "0\n";
            }            
            else{
                pop_heap(v.begin(),v.end());
                cout << v.back() << '\n';
                v.pop_back();
            }                
        }
        else{
            v.push_back(tmp);
            push_heap(v.begin(),v.end());
        }
    }
    return 0;
}