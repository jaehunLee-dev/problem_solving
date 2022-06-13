#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);        
    string s;
    cin >> s;
    bool able = false;
    int len = s.size();
    int* num = new int[len];
    for (int i=0; i<len; i++){
        num[i] = s[i] - '0';
        if (num[i] == 0)
            able = true;
    }    
    if (able == false){
        cout << -1;
        return 0;
    }
    int sum = 0;
    for (int i=0; i<len; i++)
        sum += num[i];
    if (sum%3 != 0){
        cout << -1;
        return 0;
    }

    sort(num,num+len);

    for (int i=len-1; i>=0; i--)
        cout << num[i];
    return 0;
}