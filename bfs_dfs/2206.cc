#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    if (m == 1 && n == 1){
        cout << 1;
        return 0;
    }
    vector<vector<int>> v(n,vector<int>(m,0));        
    vector<vector<bool>> no_brk(n,vector<bool>(m,false));//visit check for no brk
    vector<vector<bool>> brk(n,vector<bool>(m,false));   //visit check for brk
    int dx[4] = {0,1,0,-1}; //위,우,아래,좌
    int dy[4] = {-1,0,1,0};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%1d",&v[i][j]);
        }            
    }
    queue<tuple<int,int,bool,int>> q;   //bool for breaking possible (x,y,brk,num_of_blk)
    q.push(make_tuple(0,0,true,1));
    no_brk[0][0] = true;
    while (!q.empty()){        
        tuple<int,int,bool,int> tmp = q.front();
        q.pop();                
        int nx = get<0>(tmp);
        int ny = get<1>(tmp);
        bool brk_tmp = get<2>(tmp);
        int num = get<3>(tmp);
        for (int i=0;i<4;i++){
            int nnx, nny;
            nnx = nx + dx[i];
            nny = ny + dy[i];
            if (nnx == m-1 && nny == n-1){
                cout << num+1;
                return 0;
            }
            if (nnx>=0 && nnx<m && nny>=0 && nny<n){            
                if (brk_tmp){   //1번 부수기 가능
                    if (no_brk[nny][nnx]) continue;
                    no_brk[nny][nnx] = true;
                    if (v[nny][nnx] == 0){
                        q.push(make_tuple(nnx,nny,true,num+1));
                    }
                    else if (v[nny][nnx] == 1){ //벽인 상태 -> 부숴야함                        
                        q.push(make_tuple(nnx,nny,false,num+1));
                    }
                }
                else{   //이미 1번 부숨 (불가)
                    if (brk[nny][nnx]) continue;
                    brk[nny][nnx] = true;
                    if (v[nny][nnx] == 0){    //벽 없는 경우만 가능
                        q.push(make_tuple(nnx,nny,false,num+1));
                    }
                }
            }
        }
    }     
    
    cout << -1;               
    return 0;
}