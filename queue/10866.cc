#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    deque<int> dq;   
    string tmp; getline(cin,tmp);
    for (int i=0; i<n; i++){
        string s;
        getline(cin,s);        
        if (s.find("push_back") != string::npos){
            string idx = s.substr(10,-1);  
            dq.push_back(stoi(idx));                               
        } 
        else if (s.find("push_front") != string::npos){
            string idx = s.substr(11,-1);  
            dq.push_front(stoi(idx));                               
        }        
        else if (s.find("pop_front") != string::npos){
            if (dq.empty()) cout << "-1\n";
            else{
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (s.find("pop_back") != string::npos){
            if (dq.empty()) cout << "-1\n";
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (s.find("size") != string::npos)
            cout << dq.size() << '\n';        
        else if (s.find("empty") != string::npos){
            if (dq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s.find("front") != string::npos){
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';                
        }
        else{
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
    }
    return 0;
}