#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int N, M, len;
int ans = -1;
bool* active;
int** lab;
int dst;    //총 감염시켜야할 양
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>> virus;
void bfs(){
    queue<pair<pair<int,int>,int>> q;   //좌표, day
    int now = 0;    //감염시킨 양
    bool** visited = new bool*[N];
    for (int i=0; i<N; i++)
        visited[i] = new bool[N]();
    for (int i=0; i<len; i++){
        if (active[i]){
            int y = virus[i].first;
            int x = virus[i].second;
            visited[y][x] = true;
            q.push(make_pair(make_pair(y, x), 0));
        }
    }
        
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int day = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny>=0 && nx>=0 && ny<N && nx<N){
                if (visited[ny][nx] || lab[ny][nx] == 1) continue;
                visited[ny][nx] = true;
                if (lab[ny][nx] == 0) now++;
                if (now == dst){    //전부 감염
                    int tmp_ans = day+1;
                    if (tmp_ans < ans || ans == -1)
                        ans = tmp_ans;
                    return;
                }
                q.push(make_pair(make_pair(ny, nx), day+1));
            }
        }
    }
    
}
void comb(int sel, int idx){
    if (sel == M){    //M개 선택 완료
        bfs();
        return;
    }
    if (idx >= len) return;
    active[idx] = true;
    comb(sel+1,idx+1);
    active[idx] = false;
    comb(sel,idx+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    lab = new int*[N];
    for (int i=0; i<N; i++)
        lab[i] = new int[N];
    for (int i=0; i<N; i++){
        for (int j=0;j<N; j++){
            cin >> lab[i][j];
            if (lab[i][j] == 2){
                virus.push_back(make_pair(i,j));
                len++;
            }
            else if (lab[i][j] == 0)
                dst++;
        }
    }
    if (!dst){
        cout << 0;
        return 0;
    }
    active = new bool[len]();
    comb(0,0);
    cout << ans;
    return 0;
}
