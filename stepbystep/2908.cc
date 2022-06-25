#include <iostream>
using namespace std;
int main(){
    string first, second;
    cin >> first >> second;        
    for (int i=2; i>=0; i--){
        if (first[i] > second[i]){
            cout << first[2] << first[1] << first[0];
            break;
        }
        else if (first[i] < second[i]){
            cout << second[2] << second[1] << second[0];
            break;
        }
    }
    return 0;
}