#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool visited[10000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    vector<string> ans; 
    for (int itr = 0; itr<T; itr++){ 
        memset(visited,false,sizeof(visited));        
        int src, dst;
        cin >> src >> dst;
        queue<pair<int,string>> q;     
        q.push(make_pair(src,""));
        visited[src] = true;
        while (!q.empty()){
            pair<int,string> tmp = q.front();
            q.pop();
            int result = tmp.first*2%10000;
            if (result == dst){
                ans.push_back(tmp.second + "D");
                break;
            }
            if (!visited[result]){
                visited[result] = true;                
                q.push(make_pair(result,tmp.second+"D"));
            }                
                    
            result = tmp.first-1;
            if (result == -1) result = 9999;                
            if (result == dst){
                ans.push_back(tmp.second+"S");
                break;
            }
            if (!visited[result]){
                visited[result] = true;                
                q.push(make_pair(result,tmp.second+"S"));
            }                
            
            
            result = tmp.first/1000 + (tmp.first%1000)*10;                
            if (result == dst){
                ans.push_back(tmp.second+"L");
                break;
            }
            if (!visited[result]){
                visited[result] = true;                
                q.push(make_pair(result,tmp.second+"L"));
            }       
                                         
            result = tmp.first%10*1000 + tmp.first/10;                
            if (result == dst){
                ans.push_back(tmp.second+"R");
                break;
            }
            if (!visited[result]){
                visited[result] = true;                
                q.push(make_pair(result,tmp.second+"R"));
            }                                    
        } 
    }
    for (auto& i:ans)
        cout << i << '\n';    
    return 0;
}