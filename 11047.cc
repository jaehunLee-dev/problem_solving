#include <iostream>
using namespace std;
int money[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int ans = 0;
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> money[i];
    }
    for (int i=N-1; i>=0; i--){
        if (money[i] == 0 || money[i] > K)
            continue;
        else{
            ans += K/money[i];
            K = K%money[i];
        }
    }
    cout << ans;
    return 0;
}