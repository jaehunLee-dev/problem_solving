#include <iostream>
#include <string>
using namespace std;
int main(){    
    string s;
    getline(cin,s);
    int ans = 0;
    bool start = false;
    for (int i=0; i<s.length(); i++){
        if (s[i] != ' ')
            start = true;
        else{
            if (start)
                ans++;
        }                    
        
    }
    if (s[s.length()-1] != ' ')
        ans++;
    cout << ans;
    return 0;
}