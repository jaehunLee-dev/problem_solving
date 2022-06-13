#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;    
    while (1){
        if (K == 0){
            int ans = 0;
            if (N/2 >= M)
                ans = M;
            else
                ans = N/2;
            cout << ans;
            break;
        }         
        if (N/2 >= M){
            N-=1;
            K-=1;
        }
        else if (N/2 < M){
            M-=1;
            K-=1;
        }           
    }
    return 0;
}