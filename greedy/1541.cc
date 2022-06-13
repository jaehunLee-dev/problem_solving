#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int* L = new int[n];
    for (int i=0; i<n; i++)
        cin >> L[i];
    int max_idx = max_element(L,L+n)-L;
    int ans = L[max_idx]*(n-1);
    for (int i=0; i<n; i++){
        if (i == max_idx) continue;
        ans += L[i];
    }
    cout << ans;
    return 0;
}