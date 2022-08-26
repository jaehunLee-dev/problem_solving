#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
int** board;
int dice[6] = {1,2,3,4,5,6};    //밑면: 5, 윗면: 0
int dy[4] = {0,1,0,-1};     //오아왼위
int dx[4] = {1,0,-1,0};     //오아왼위
int dir;
int score;
int y, x;
/*
    1
 3  0  2
    4
    5
 */
void get_score(){
    queue<pair<int,int>> q;
    bool** visited = new bool*[N];
    for (int i=0; i<N; i++)
        visited[i] = new bool[M]();
    int B = board[y][x];
    visited[y][x] = true;
    q.push(make_pair(y, x));
    int tmp_score = 0;
    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        tmp_score++;
        q.pop();
        for (int d = 0; d < 4; d++){
            int ny = qy + dy[d], nx = qx+dx[d];
            if (ny>=0 && nx>=0 && ny<N && nx<M && !visited[ny][nx] &&board[ny][nx] == B){
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    score += tmp_score*B;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    board = new int*[N];
    for (int i=0; i<N; i++){
        board[i] = new int[M];
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }
    while(K--){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny<0 || nx<0 || ny>=N || nx>=M){
            dir = (dir+2)%4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        y = ny;
        x = nx;
        get_score();
        int tmp;
        switch (dir) {
            case 0:
                tmp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[2];
                dice[2] = tmp;
                break;
            case 1:
                tmp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[4];
                dice[4] = tmp;
                break;
            case 2:
                tmp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[3];
                dice[3] = tmp;
                break;
            case 3:
                tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
                break;
                
            default:
                break;
        }
        if (dice[5] > board[y][x])
            dir = (dir+1)%4;
        else if (dice[5] < board[y][x]){
            if(--dir < 0)
                dir = 3;
        }
    }
    cout << score;
    return 0;
}