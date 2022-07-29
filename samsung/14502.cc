#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> wall;
int N, M;
int tmp;
int** map;
int** copy_map;
bool* sel;
int ans;
void bfs(){
    queue<pair<int,int>> q;    
    int dy[4] = {0,1,0,-1};
    int dx[4] = {1,0,-1,0};
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (copy_map[i][j] == 2){    //바이러스 발견                
                copy_map[i][j] = 2;
                q.push(make_pair(i,j));
            }
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (int k=0; k<4; k++){
                    int ny = y+dy[k];
                    int nx = x+dx[k];
                    if (ny<N && nx<M && ny>=0 && nx>=0){
                        if (copy_map[ny][nx] == 0){
                            copy_map[ny][nx] = 2;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
            }
        }
    }
    int tmp_ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (copy_map[i][j] == 0)
                tmp_ans++;
        }
    }
    if (tmp_ans > ans)
        ans = tmp_ans;
}

void comb(int selected, int idx){
    if (selected == 3){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++)
                copy_map[i][j] = map[i][j];
        }
        for (int i=0; i<tmp; i++){
            if (sel[i]){
                int y = wall[i].first;
                int x = wall[i].second;
                copy_map[y][x] = 1;
            }                    
        }
        bfs();
        return;
    }
    if (idx == tmp)
        return;    
    sel[idx] = true;
    comb(selected+1,idx+1);
    sel[idx] = false;
    comb(selected,idx+1);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    map = new int*[N];
    copy_map = new int*[N];
    for (int i=0; i<N; i++){
        map[i] = new int[M];
        copy_map[i] = new int[M];
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> map[i][j];   //0 빈칸, 1 벽, 2 바이러스
            if (map[i][j] == 0){    //벽 설치 가능한 빈칸 저장
                wall.push_back(make_pair(i,j));
                tmp++;            
            }            
        }
    }    
    sel = new bool[tmp]();
    comb(0,0);
    cout << ans;
    return 0;
}