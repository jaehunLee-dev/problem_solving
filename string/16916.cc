#include <iostream>     
#include <string>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if (s2.length() > s1.length()){
        cout << 0;
        return 0;
    }
    
    int* pi = new int[s2.length()];
    for (int i=0; i<s1.length();){
        for (int j=0; j<s2.length(); j++){
            if (s2[j])
        }
    }

    return 0;
}