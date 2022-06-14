#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int test=0; test<T; test++){
        int N;
        cin >> N;
        int* a = new int[N];    //서류
        int* b = new int[N];    //면접
        bool* pass = new bool[N];
        for (int i=0; i<N; i++)
            pass[i] = true;
        for (int vol = 0; vol < N; vol++)
            cin >> a[vol] >> b[vol];
        int a_best_idx = min_element(a,a+N) - a;
        int b_best_idx = min_element(b,b+N) - b;
        int b_limit = b[a_best_idx];
        int a_limit = a[b_best_idx];
        for (int i=0; i<N; i++){
            if (a[i]>a_limit)
                pass[i] = false;
            if (b[i]>b_limit)
                pass[i] = false;
        }        
        int ans = 0;
        for (int i=0; i<N; i++){
            if (pass[i] == true)
                ans++;
        }
        cout << ans;
        if (test != T-1)
            cout << '\n';
    }
    return 0;
}