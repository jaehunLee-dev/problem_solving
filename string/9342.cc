#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main(){
    int T;
    cin >> T;
    string s;
    regex  re("[A-F]?A+F+C+[A-F]?");
    for (int i=0; i<T; i++){
        cin >> s;
        if(regex_match(s,re))
            cout << "Infected!\n";
        else cout << "Good\n";
    }
    return 0;    
}