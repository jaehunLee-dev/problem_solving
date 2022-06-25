#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] <= 'O')
            ans += (s[i]-'A')/3 + 3;
        else if (s[i]<= 'S')
            ans += 8;
        else if (s[i] <= 'V')
            ans += 9;
        else ans += 10;
    }
    cout << ans;
    return 0;
}