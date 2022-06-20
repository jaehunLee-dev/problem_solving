#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){
    string s, k;
    cin >> s >> k;
    s = regex_replace(s,regex("[0-9]"),"");
    if (s.find(k) != string::npos)
        cout << 1;
    else    cout << 0;
    return 0;    
}