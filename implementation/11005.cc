#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, b;
    char ans_tmp;
    cin >> n >> b;
    string ans;
    while (n>0){
        if (n%b>9)
            ans_tmp = n%b + 55;
        else ans_tmp = n%b + '0';
        ans = ans_tmp + ans;
        n/=b;
    }
    cout << ans;
    return 0;
}