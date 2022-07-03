#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int ans = 0;
    while (s.find("dz=")!=string::npos){
        int idx = s.find("dz=");
        s = s.substr(0,idx) + '!' + s.substr(idx+3,-1);
    }
    while (s.find("lj")!=string::npos){
        int idx = s.find("lj");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("nj")!=string::npos){
        int idx = s.find("nj");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("c=")!=string::npos){
        int idx = s.find("c=");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("c-")!=string::npos){
        int idx = s.find("c-");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("d-")!=string::npos){
        int idx = s.find("d-");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("s=")!=string::npos){
        int idx = s.find("s=");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    while (s.find("z=")!=string::npos){
        int idx = s.find("z=");
        s = s.substr(0,idx) + '!' + s.substr(idx+2,-1);
    }
    cout << s.length();
    return 0;
}