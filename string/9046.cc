#include <iostream>
#include <string>
using namespace std;
int ans[26];
int main(){
    int T;
    cin >> T;    
    string s;
    getline(cin,s);
    for (int i=0; i<T; i++){
        for (int j=0;j<26;j++)
            ans[j] = 0;
        getline(cin,s);
        for (int j=0; j<s.length(); j++){
            if (s[j] != ' '){
                ans[s[j]-'a']++;
            }
        }
        int max = 0;
        char max_ch;        
        for (int j=0; j<26; j++){
            if (ans[j]>max){
                max = ans[j];
                max_ch = j+'a';                
            }
            else if (ans[j] == max)
                max_ch = '?';
        }
        cout << max_ch << '\n';
    }
    return 0;    
}
