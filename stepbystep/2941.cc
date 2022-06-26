#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans = 0, idx = 0;
    while (1){        
        if (s.find("dz=") == string::npos)
            break;        
        s.erase(find(s.begin(), s.end(),"dz="));
        ans++;
        cout << s;
    }
    cout << s;
    return 0;
}