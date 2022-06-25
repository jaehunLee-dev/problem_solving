#include <iostream>
using namespace std;
int num[26];
int main(){
    int max = 0;
    char ans = ' ';
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++){
        s[i] = tolower(s[i]);
        int idx = s[i] - 'a';
        if (++(num[idx]) > max){
            ans = s[i];
            max = num[idx];
        }
        else if (num[idx] == max)
            ans = '?';
    }
    cout << char(toupper(ans));
    return 0;
}