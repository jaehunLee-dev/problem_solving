#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        int tmp = i; int div = 10;
        int now = i;
        while (tmp>0){
            now += tmp%10;
            tmp/=10;
        }
        if (now == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}