#include <iostream>
#include <queue>
using namespace std;
int N;
int sz = 2; //상어 크기
int dy[4] = {-1,0,0,1}; //위,왼,오,아
int dx[4] = {0,-1,1,0};
int** board;
bool** visited;
int t;  //시간
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    board = new int*[N];
    visited = new bool*[N];
    for (int i=0; i<N; i++){
        board[i] = new int[N];
        visited[i] = new bool[N]();
    }
    queue<pair<pair<int,int>,int>> q;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> board[i][j];
            if (board[i][j] == 9){
                q.push(make_pair(make_pair(i,j), 0));
                board[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    int eat = 0;
    int tmp_dst = -1;
    int tmp_y = -1, tmp_x = -1;
    while(!q.empty() || tmp_dst!=-1){      //만약 먹이 찾으면 해당 위치로 이동, 즉 기존의 q 전부 비워야함
        if (q.empty()){
            board[tmp_y][tmp_x] = 0;
            t += tmp_dst;
            tmp_dst = -1;
            q.push(make_pair(make_pair(tmp_y,tmp_x), 0));
            for (int j=0; j<N; j++){
                for (int k=0; k<N; k++)
                    visited[j][k] = false;
            }
            visited[tmp_y][tmp_x] = true;
            if (++eat == sz){
                sz++;
                eat = 0;
            }
            tmp_dst = tmp_y = tmp_x = -1;
        }
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second;
        q.pop();            //또한, 바로 먹는게 아니라, 같은 level의 모든 값들 봐야함?...
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny>=0 && nx>=0 && ny<N && nx<N) {
                if (visited[ny][nx] || (tmp_dst!=-1 && dist+1 >tmp_dst)) continue;
                if (board[ny][nx] < sz && board[ny][nx] > 0){    //가깝고 더 작은 먹이 발견 -> 이동
                    if (tmp_dst == -1 || ny < tmp_y || (ny == tmp_y && nx < tmp_x)){
                        tmp_dst = dist+1;
                        tmp_y = ny;
                        tmp_x = nx;
                        //q.push(make_pair(make_pair(ny, nx), tmp_dst));
                    }
                }
                else if (board[ny][nx]==0 || board[ny][nx] == sz){   //먹을 수 없지만 이동 가능
                    if (tmp_dst == -1 || dist+1 < tmp_dst){
                        visited[ny][nx] = true;
                        q.push(make_pair(make_pair(ny,nx), dist+1));
                    }
                }
            }
        }
    }
    cout << t;
    return 0;
}