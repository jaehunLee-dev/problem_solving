#include <iostream>
#include <vector>
using namespace std;
int ans;
vector<pair<int,int>> v;
void hanoi(int n, int src,int dst){    
    if (n == 1){
        v.push_back(make_pair(src,dst));
        ans++;
        return;
    }
    int new_dst = 6 - src - dst;    
    hanoi(n-1,src,new_dst);
    ans++;
    v.push_back(make_pair(src,dst));
    hanoi(n-1,new_dst,dst);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    hanoi(n,1,3);
    cout << ans << '\n';
    for (auto& i:v){
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}