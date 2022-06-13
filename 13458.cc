#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N=0, B=0, C=0;
    cin >> N;
    long long* A = new long long[N];
    for (int i=0; i<N; i++)
        cin >> A[i];
    cin >> B >> C;    
    long long ans = N;
    for (int i=0; i<N; i++){
        A[i] -=B;
        if (A[i] > 0){
            if (A[i]%C == 0)
                ans += A[i]/C;
            else
                ans += A[i]/C + 1;
        }
    }
    cout << ans;
    return 0;
}