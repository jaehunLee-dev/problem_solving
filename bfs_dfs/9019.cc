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
        char cmd[4] = {'D','S','L','R'};
        for (int i=0; i<4; i++){         
            string s; s=cmd[i];  
            q.push(make_pair(src,s));    
        }        
        visited[src] = true;
        while (!q.empty()){
            pair<int,string> tmp = q.front();
            q.pop();            
            char mode = tmp.second[tmp.second.length() -1];
            if (mode == 'D'){       //D할 때
                int result = tmp.first*2%10000;
                if (!visited[result]){
                    visited[result] = true;
                    if (result == dst){
                        ans.push_back(tmp.second);
                        break;
                    }
                    for (int i=0; i<4; i++)
                        q.push(make_pair(result,tmp.second+cmd[i]));
                }                            
            }
            else if (mode == 'S'){  //S할 때                
                int result = tmp.first-1;
                if (result == -1) result = 9999;
                if (!visited[result]){
                    visited[result] = true;
                    if (result == dst){
                        ans.push_back(tmp.second);
                        break;
                    }
                    for (int i=0; i<4; i++)
                        q.push(make_pair(result,tmp.second+cmd[i]));
                }                                
            }
            else if (mode == 'L'){  //L할 때
                int result = tmp.first/1000 + (tmp.first%1000)*10;
                if (!visited[result]){
                    visited[result] = true;
                    if (result == dst){
                        ans.push_back(tmp.second);
                        break;
                    }
                    for (int i=0; i<4; i++)
                        q.push(make_pair(result,tmp.second+cmd[i]));
                }                                
            }
            else if (mode == 'R'){                                   //R할 떄
                int result = tmp.first%10*1000 + tmp.first/10;
                if (!visited[result]){
                    visited[result] = true;
                    if (result == dst){
                        ans.push_back(tmp.second);
                        break;
                }
                for (int i=0; i<4; i++)
                    q.push(make_pair(result,tmp.second+cmd[i]));
                }                            
            }
            else cout << "error!\n";                  
        } 
    }
    for (auto& i:ans)
        cout << i << '\n';    
    return 0;
}