#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    //위,오른쪽,아래,왼쪽
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    for (int i = 0; i< T; i++){
        int ans = 0;
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> table(n,vector<int>(m,0));                
        for (int j=0; j<k; j++){
            int x, y; cin >> x >> y;
            table[y][x] = 1;            
        }        
        for (int j=0; j<n; j++){
            for (int l=0; l<m; l++){
                if (table[j][l] == 1){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(j,l));
                    table[j][l] = 0;
                    while (!q.empty()){                        
                        for (int dir = 0; dir<4; dir++){
                            int nx = q.front().second + dx[dir];
                            int ny = q.front().first + dy[dir];
                            if (ny >=0 && ny < n && nx >=0 && nx <m){
                                if (table[ny][nx] == 1){
                                    table[ny][nx] = 0;
                                    q.push(make_pair(ny,nx));
                                }
                            }
                        }
                        q.pop();
                    }                                        
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}