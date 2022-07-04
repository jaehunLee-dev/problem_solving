#include <iostream>
#include <stack>
using namespace std;
int main(){    
    string str;
    while (getline(cin,str)){
        if (str == ".") break;
        stack<char> s;
        bool out = false;
        for (int i=0; i<str.length(); i++){
            if (str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }
            else if (str[i] == ')'){
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    cout << "no\n";
                    out = true;
                    break;
                }                
            }
            else if (str[i] == ']'){
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else{
                    cout << "no\n";
                    out = true;
                    break;
                }
            }
        }
        if (!s.empty() && out == false){
            out = true;   
            cout << "no\n";
        }
        if (!out){
            cout << "yes\n";
        }
    }
    return 0;
}