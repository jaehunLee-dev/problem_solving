#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;    
    for (int test=0; test<T; test++){
        int N;
        cin >> N;
        vector<pair<int,int>> v;                
        int tmp1, tmp2, ans=0;
        for (int vol = 0; vol < N; vol++){
            cin >> tmp1 >> tmp2;
            v.push_back({tmp1,tmp2});
        }                    
        sort(v.begin(),v.end(), compare);
        int last_pass = 100001;        
        for (auto &i:v){            
            if (i.second < last_pass){                
                last_pass = i.second;
                ans++;
            }
        }
        cout << ans << '\n';
    }    
    return 0;
}