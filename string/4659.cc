#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    char mo[5] = {'a','e','i','o','u'};
    string s;
    bool out = false;
    while (1){
        cin >> s;
        out = false;
        int ja = 0;
        if (s == "end")
            break;
        for (int i=0; i<5; i++){
            if (s.find(mo[i]) != string::npos)
                break;
            if (i == 4){
                cout << '<' << s  << '>' <<" is not acceptable.\n";
                out = true;
            }
        }
        if (out)    continue;
        for (int i=2; i<s.length(); i++){
            ja = 0;
            for (int j=0; j<3; j++){
                if (find(mo,mo+5,s[i-j]) == mo+5) //자음
                    ja++;                                
            }            
            if (ja == 0 || ja == 3) {    //모두 자음 또는 모두 모음
                cout << '<' << s  << '>' <<" is not acceptable.\n";
                out = true;
                break;
            }
        }
        if (out)    continue;        
        for (int i=1; i<s.length(); i++){
            if (s[i] == s[i-1] && s[i]!='e' && s[i] != 'o'){
                cout << '<' << s  << '>' <<" is not acceptable.\n";         
                out = true;
                break;                
            }
        }
        if (out)    continue;

        cout << '<' << s  << '>' <<" is acceptable.\n";         
    }
    return 0;    
}