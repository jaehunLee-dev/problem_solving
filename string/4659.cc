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
        if (s == "end")
            break;
        for (int i=0; i<5; i++){
            if (s.find(mo[i]) != string::npos)
                break;
            if (i == 4){
                cout << '<' << s  << '>' <<"is not acceptable.\n";
                out = true;
            }
        }
        if (out)    continue;
        for (int i=2; i<s.length(); i++){
            for (int j=0; j<3; j++){
                if (find(mo,mo+5,str[i-j]) == mo+5){       //모음 하나도 없는 경우 -> 3번 자음 연속
                    break;
                }
                if (j == 2){
                                        
                }
            }
        }
    }
    return 0;    
}