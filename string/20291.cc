#include <iostream>
#include <string>
#include <map>
using namespace std;
bool compare(){

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    string* str = new string[N];
    map<string,int> ans;
    for (int i=0; i<N; i++){
        cin >> str[i];
        str[i] = str[i].substr(str[i].find('.')+1);        
    }        
    for (int i=0; i<N; i++){
        if (ans.find(str[i]) != ans.end())
            ans[str[i]] += 1;
        else
            ans.insert({str[i],1});
    }
    for (auto& i:ans){
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;    
}