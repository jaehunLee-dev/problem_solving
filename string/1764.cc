#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(string s1, string s2){
    return s1<s2;
}
int main(){
    int N, M, ans=0;
    cin >> N >> M;
    string* dud = new string[N];
    string* bo = new string[M];
    for (int i=0; i<N; i++)
        cin >> dud[i];
    for (int i=0; i<M; i++)
        cin >> bo[i];
    sort(dud,dud+N,compare);
    sort(bo,bo+M,compare);
    vector<string> anstr;
    for (int i=0; i<M; i++){
        if(binary_search(dud,dud+N,bo[i])){
            ans++;
            anstr.push_back(bo[i]);
        }
    }
    cout << ans << '\n';
    for (auto& i:anstr)
        cout << i << '\n';
    return 0;    
}