#include <iostream>
#include <deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--){
        string p; cin >> p;
        int num; cin >> num;
        string exp; cin >> exp;
        int len = 0;
        deque<int> dq;
        for (int i=1; i<exp.length(); i++){
            if (exp[i] == ',' || exp[i] == ']'){
                if (exp[i-1] == '[')
                    break;
                int mul = 1, tmp = 0;
                for (int j=1; j<=len; j++){
                    tmp+=mul*(exp[i-j] - '0');
                    mul*=10;
                }
                dq.push_back(tmp);
                len = 0;
            }            
            else    len++;   //숫자
        }
        bool reverse = false, out = false;
        for (int i=0; i<p.length(); i++){
            if (p[i] == 'R'){
                reverse = !reverse;
            }
            else{
                if (dq.empty()){
                    cout << "error\n";
                    out = true;
                    break;
                }
                if (!reverse){  //정방향
                    dq.pop_front();
                }
                else{       //역방향
                    dq.pop_back();
                }
            }
        }

        if (out) continue;
        if (dq.empty()){
            cout << "[]\n";
            continue;
        }        
        cout << '[';
        if (!reverse){  //정방향
            while(!dq.empty()){
                cout << dq.front();
                if (dq.size() > 1)
                    cout << ',';
                else cout << "]\n";
                dq.pop_front();                
            }
        }
        else{       //역방향
            while(!dq.empty()){
                cout << dq.back();
                if (dq.size() > 1)
                    cout << ',';
                else cout << "]\n";
                dq.pop_back();                
            }
        }        
    }
    return 0;
}