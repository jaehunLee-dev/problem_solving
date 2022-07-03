#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    int i=1;    
    while(1){
        string str = to_string(i);
        if(str.find("666") != string::npos){
            n--;
            if (n == 0){
                cout << str;
                return 0;
            }
        }
        i+=1;
    }
    return 0;
}