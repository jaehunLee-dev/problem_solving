#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n; cin >> t;
    int t_org = t;
    int dx[4] = {0,1,0,-1}; //위,오른쪽,아래,왼쪽
    int dy[4] = {-1,0,1,0};
    while(t--){
        cin >> n;
        int ans = 1;
        int** table = new int*[n];
        for (int i=0; i<n; i++)
            table[i] = new int[n];
        int high = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> table[i][j];
                if (table[i][j] > high)
                    high = table[i][j];
            }
        }
        while(high--){      //1년 지남
            queue<pair<int,int>> q; //y좌표,x좌표
            int tmp_ans = 0;
            bool** visited = new bool*[n];
            for (int i=0; i<n; i++)
                visited[i] = new bool[n]{};        
            for (int i=0; i<n; i++){    //1년 지남
                for (int j=0; j<n; j++)
                    table[i][j]--;     
            }                               
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (table[i][j] > 0 && !visited[i][j]){
                        tmp_ans++;
                        q.push(make_pair(i,j));
                        while (!q.empty()){                            
                            int y = q.front().first;
                            int x = q.front().second;
                            q.pop();
                            for (int dir = 0; dir<4; dir++){
                                int ny = y+dy[dir];
                                int nx = x+dx[dir];
                                if (ny >= 0 && ny < n && nx >= 0 && nx < n){
                                    if (table[ny][nx] > 0 && !visited[ny][nx]){
                                        visited[ny][nx] = true;
                                        q.push(make_pair(ny,nx));
                                    }
                                }
                            }
                        }
                    }                
                }            
            }
            if (tmp_ans > ans)
                ans = tmp_ans;
        }
        cout << '#' << t_org-t << ' ' << ans << '\n';
    }
    return 0;
}