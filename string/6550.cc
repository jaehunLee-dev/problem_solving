#include <iostream>
#include <string>
using namespace std;
int main(){    
    string s, t;
    while (cin >> s >> t){                 
        int idx = 0;
        for (int i=0; i<t.length(); i++){
            if (t[i] == s[idx])
                idx+=1;
        }
        if (idx == s.length())
            cout << "Yes\n";
        else
            cout << "No\n";        
    }    
    return 0;    
}