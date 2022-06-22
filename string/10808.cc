#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string S;
    int ans[26] = {};
    cin >> S;
    for (int i=0; i<S.length(); i++){
        ans[S[i] - 'a']++;
    }
    for (int i=0; i<26; i++)
        cout << ans[i] << ' ';
    return 0;
}