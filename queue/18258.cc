#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    queue<int> q;   
    string tmp; getline(cin,tmp);
    for (int i=0; i<n; i++){
        string s;
        getline(cin,s);        
        if (s.find("push") != string::npos){
            string idx = s.substr(5,-1);  
            q.push(stoi(idx));                               
        }        
        else if (s.find("pop") != string::npos){
            if (q.empty()) cout << "-1\n";
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (s.find("size") != string::npos)
            cout << q.size() << '\n';        
        else if (s.find("empty") != string::npos){
            if (q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s.find("front") != string::npos){
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';                
        }
        else{
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
    }
    return 0;
}