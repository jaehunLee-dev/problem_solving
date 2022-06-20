#include <iostream>
#include <string>
using namespace std;
int main(){
    int num[26] = {3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0; i<s.length(); i++){        
        ans+=num[s[i]-'A'];
    }    
    ans%=10;
    if (ans%2 == 0)
        cout << "You're the winner?";
    else
        cout << "I'm a winner!";
    return 0;    
}