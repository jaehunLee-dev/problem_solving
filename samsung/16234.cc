#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, L, R;
    int ans = 0;
    cin >> N >> L >> R;
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int** A = new int*[N];
    bool** visited = new bool*[N];
    for (int i=0; i<N; i++){
        A[i] = new int[N];
        visited[i] = new bool[N]();
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cin >> A[i][j];        
    }
    queue<pair<int,int>> q;
    while(++ans){    
        bool end = true;;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                int avg = 0;
                int div = 1;
                vector<pair<int,int>> v;
                if (!visited[i][j]){
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    avg = A[i][j];
                }
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    v.push_back(make_pair(y,x));
                    q.pop();
                    for (int dir=0; dir<4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if (nx>=0 && ny >=0 && nx<N && ny<N){
                            if (!visited[ny][nx] && abs(A[ny][nx] - A[y][x]) >= L && abs(A[ny][nx] - A[y][x]) <= R ){
                                visited[ny][nx] = true;
                                q.push(make_pair(ny,nx));
                                div+=1;
                                avg += A[ny][nx];
                                v.push_back(make_pair(ny,nx));
                                end = false;
                            }
                        }
                    }
                }
                avg/=div;
                for(auto& itr : v){
                    A[itr.first][itr.second] = avg;
                }
            }
        }
        if (end)
            break;
    }
    cout << ans-1;
    return 0;
}