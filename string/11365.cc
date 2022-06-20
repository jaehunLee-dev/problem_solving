#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while (1){
        getline(cin,s);
        if (s == "END")
            break;
        for(int i=1; i<=s.length(); i++)
            cout << s[s.length()-i];      
        cout << '\n';  
    }    
    return 0;
}