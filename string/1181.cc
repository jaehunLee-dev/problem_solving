#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string s1, string s2){
    if (s1.length() == s2.length())
        return s1<s2;
    return s1.length()<s2.length();
}
int main(){
    int N; cin >> N; 
    string* s = new string[N];   
    vector<string> ans;
    for (int i=0; i<N; i++)
        cin >> s[i];
    ans.push_back(s[0]);
    for (int i=1; i<N; i++){
        for (auto& v:ans){
            if (v == s[i]){
                break;
            }
            if (&v == &ans[ans.size()-1]){
                ans.push_back(s[i]);                
            }
        }        
    }        
    sort(ans.begin(),ans.end(),compare);
    for (auto& v: ans)
        cout << v << '\n';
    return 0;    
}