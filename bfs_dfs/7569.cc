#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int dx[6] = {0,0,1,-1,0,0}; //위,아래,우,좌,세로위,세로아래
    int dy[6] = {0,0,0,0,-1,1};
    int dz[6] = {-1,1,0,0,0,0};
    int m,n,h;    
    cin >> m >> n >> h;
    vector<vector<vector<int>>> v(h,vector<vector<int>>(n,vector<int>(m)));
    for (int i=0;i<h;i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<m; k++)
                cin >> v[i][j][k];
        }
    }
    int ans = 1;
    queue<tuple<int,int,int>> q;        
    for (int i=0;i<h;i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                if (v[i][j][k] == 1){                    
                    q.push(make_tuple(i,j,k));                    
                }
            }
        }
    }
    while (!q.empty()){
        tuple<int,int,int> tmp = q.front();
        q.pop();
        int tmp_x = get<2>(tmp);
        int tmp_y = get<1>(tmp);
        int tmp_z = get<0>(tmp);
        for (int itr = 0; itr<6; itr++){
            int nx = tmp_x + dx[itr];
            int ny = tmp_y + dy[itr];
            int nz = tmp_z + dz[itr];
            if (nx>=0 && nx<m && ny>=0 && ny<n && nz>=0 && nz<h){
                if (v[nz][ny][nx] == 0){
                    v[nz][ny][nx] = v[tmp_z][tmp_y][tmp_x]+1;
                    q.push(make_tuple(nz,ny,nx));
                }                                
            }
        }
    }                    
    bool out = false;
    for (int i=0;i<h;i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                if (v[i][j][k] == 0){
                    ans = 0;
                    out = true;
                    break;
                }       
                else if (v[i][j][k] > ans)  {
                    ans = v[i][j][k];
                }                     
            }
            if (out)      break;
        }
        if (out)      break;
    }
    cout << ans - 1;
    return 0;
}