#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){    
    if (a.first == b.first )
        return a.second < b.second;
    return a.first<b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp1, tmp2;
    //vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> ans;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i=0; i<N; i++){
        cin >> tmp1 >> tmp2;
        v.push_back({tmp1,tmp2});
    }
    sort(v.begin(),v.end(),compare);    
    for (auto& i:v){
        if (ans.size() == 0){                    
            ans.push(i.second);
            continue;
        }        
        //ans 벡터 정렬 (빨리 끝나는 순서로)    -> 시간 초과 (nlogn). 따라서 정렬이 아니라, 앞에거만 빼서 보는 우선순위 큐로 구현해야함
        //sort(ans.begin(),ans.end());
        if (i.first >= ans.top()){
            ans.pop();
            ans.push(i.second);            
        }
        else
            ans.push(i.second);
    }   
    cout << ans.size();
    return 0;
}