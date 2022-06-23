#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline(cin,s);    
    int len = s.length();
    if (len<5 || len%5!=0 || len>2500){
        cout << -1;
        return 0;
    }
    int done = 0, total = 0, now = -1;
    int idx[5];
    int* duck = new int[len];
    bool* check = new bool[len]();    
    for (int i=0; i<len; i++){
        switch (s[i])
        {
        case 'q':
            duck[i] = 0;
            break;
        case 'u':
            duck[i] = 1;
            break;
        case 'a':
            duck[i] = 2;
            break;
        case 'c':
            duck[i] = 3;
            break;
        case 'k':
            duck[i] = 4;
            break;
        default:
            cout << -1;
            return 0;
            break;
        }
    }
    while (true){
        int prv_done = done;
        now = -1;
        for (int i=0; i<len; i++){
            if (check[i]) continue;
            if (duck[i] == (now+1)%5){
                now=duck[i];
                idx[now] = i;
                if (now == 4){
                    for (int j=0; j<5; j++){
                        check[ idx[j] ] = true;
                    }
                    done+=5;
                }
            }                        
        }
        if (done == prv_done)
            break;                
        total++;
    }    
    if (done != len) cout << -1;
    else cout << total;
    return 0;
}