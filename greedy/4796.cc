#include <iostream>
using namespace std;
int main(){    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L, P, V = 1;
    int ans = 0, idx = 0;    
    while (1){        
        cin >> L >> P >> V;
        if (L == 0 && P ==0 && V==0)
            break;        
        ans = (V/P)*L;
        V%=P;        
        ans += (L>V)?V:L;
        cout << "Case "<< ++idx <<": " << ans << "\n";        
    }       
    return 0;
}