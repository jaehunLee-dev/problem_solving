#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; int n;
    cin >> s >> n;
    int mul = 1, ans = 0;
    int tmp = 0;
    for (int i=s.length()-1; i>=0; i--){
        if (s[i] <= '9' && s[i] >= '0')
            tmp = s[i] - '0';
        else tmp = s[i] - 'A' + 10;
        ans += mul*tmp;
        mul*=n;
    }
    cout << ans;
    return 0;
}