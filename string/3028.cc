#include <iostream>
#include <string>
using namespace std;
bool ans[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    int idx = 0;
    cin >> s;
    ans[idx] = true;
    bool tmp = false;
    for (int i=0; i<s.length(); i++){
        switch(s[i]){
            case 'A':
                tmp = ans[0];
                ans[0] = ans[1];
                ans[1] = tmp;
                break;
            case 'B':
                tmp = ans[1];
                ans[1] = ans[2];
                ans[2] = tmp;
                break;
            case 'C':
                tmp = ans[0];
                ans[0] = ans[2];
                ans[2] = tmp;
                break;
        }
    }
    for(int i=0; i<3; i++){
        if (ans[i])
            cout << i+1;
    }

    return 0;
}