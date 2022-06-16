#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){    
    if (a.second == b.second)
        return a.first < b.first;
    return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp1, tmp2;
    int ans = 0;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i=0; i<N; i++){
        cin >> tmp1 >> tmp2;
        v.push_back({tmp1,tmp2});
    }
    sort(v.begin(),v.end(),compare);
    int prv_end = 0;
    for (auto& i:v){
        //cout << i.first << ", " << i.second << '\n';
        if (i.first >= prv_end){
            prv_end = i.second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}