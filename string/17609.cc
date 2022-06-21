#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    string s, tmp1, tmp2;
    cin >> T;
    for (int i=0; i<T; i++){
        bool out = false;
        int pseudo = 0;
        cin >> s;
        int restart = 0;
        for (int j=0; j<s.length()/2;j++){
            if (s[j] != s[s.length()-1-j]){     //불일치
                pseudo++;
                tmp1 = tmp2 = s;
                tmp1.erase(j,1);
                tmp2.erase(s.length()-1-j);
                restart = j;
                break;
            }
        }
        if (pseudo){       //일단 회문 아님            
            for (int j=restart; j<tmp1.length(); j++){
                if (tmp1[j] != tmp1[tmp1.length()-1-j]){
                    out = true;        //다름
                    break;
                }
            }
            if (out){            
                for (int j=restart; j<tmp2.length(); j++){
                    if (tmp2[j] != tmp2[tmp1.length()-1-j]){
                        pseudo++;
                        break;
                    }
                }
            }
        }
        cout << pseudo << '\n';
    }
    return 0;    
}