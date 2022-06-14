#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    string expr="";
    vector<string> subexpr;
    bool first = true;
    int minus_idx = -1;
    getline(cin,expr);
    expr.erase(remove(expr.begin(), expr.end(), ' '),expr.end());    

    for (int i=0; i<expr.length(); i++){
        if (expr[i] == '-' || i == expr.length()-1){
            if (first){
                first = false;
                subexpr.push_back(expr.substr(0,i+1));        //최초의 - 전의 식 넣기     (a+b+c-)  이런식으로 넣기
                minus_idx = i+1;
            }
            else{
                subexpr.push_back(expr.substr(minus_idx,i+1-minus_idx));
                minus_idx = i+1;
            }
        }        
    }
    int sub_idx = 0, tmp =0;
    for (auto& i:subexpr){
        sub_idx = 0;
        for (int j=0; j<i.length(); j++){
            if (i[j] == '+' || i[j] == '-'){                                        
                tmp = stoi(i.substr(sub_idx,j-sub_idx));
                sub_idx = j+1;
                if (i == subexpr[0]){
                    ans += tmp;
                }
                else{
                    ans -= tmp;
                }
            }
            else if (j == i.length()-1){
                tmp = stoi(i.substr(sub_idx,j-sub_idx+1));
                if (i == subexpr[0]){
                    ans += tmp;
                }
                else{                               
                    ans -= tmp;
                }                
            }
        }     
    }
    cout << ans;
    return 0;
}