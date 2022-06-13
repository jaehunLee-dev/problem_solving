#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int* rope = new int[N];    
    for (int i=0; i<N; i++)
        cin >> rope[i];
    sort(rope,rope+N,greater<int>());
    int ans = 0;    
    for (int idx = 0; idx < N; idx++){
        if (rope[idx]*(idx+1) >= ans)
            ans = rope[idx]*(idx+1);      
    }        
    cout << ans;
    return 0;
}