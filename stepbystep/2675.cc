#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        string s; cin >> s;
        for (int k=0; k<s.length(); k++){
            for (int j=0;j<t;j++){
                cout << s[k];
            }
        }        
        cout << '\n';
    }
    return 0;
}