#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    for (char i = 'a'; i<='z'; i++){
        int idx = s.find(i);
        if (idx!=string::npos)
            cout << idx << ' ';
        else
            cout << "-1 ";
    }
    return 0;
}