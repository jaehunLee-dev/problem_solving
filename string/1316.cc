#include <iostream>
#include <string>
using namespace std;
int grp[26];        //0->unvisited, 1->group, 2->not group
int main(){
    int N; cin >> N;
    string s;
    int ans = 0;
    for (int i=0; i<N; i++){
        cin >> s;
        for (int j=1; j<s.length(); j++){
            if (s[j] != s[j-1]){
                if (grp[s[j-1]-'a'] == 0)
                    grp[s[j-1]-'a'] = 1;
                else if (grp[s[j-1]-'a'] == 1)
                    grp[s[j-1]-'a'] = 2;            
            }            
            if (j == s.length() - 1){                
                if (grp[s[j]-'a'] == 0)
                    grp[s[j]-'a'] = 1;
                else if (grp[s[j]-'a'] == 1)
                    grp[s[j-1]-'a'] = 2;                                            
            }
        }
        for (int j=0; j<26; j++){
            if (grp[j] == 2)
                break;
            if (j == 25)
                ans++;
        }
        for (int j=0; j<26; j++){
            grp[j] = 0;
        }
    }
    cout << ans;
    return 0;    
}