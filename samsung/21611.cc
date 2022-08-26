#include <iostream>
#include <queue>
using namespace std;
int N, M;
int** board;
pair<int, int>* num;
int dy[4] = {-1,1,0,0}; //↑, ↓, ←, →
int dx[4] = {0,0,-1,1}; //↑, ↓, ←, →
int dir[4] = {2,1,3,0};    //←, ↓, →, ↑
int ans;
void move(){
    for (int i=1; i<N*N; i++){
        int y = num[i].first;
        int x = num[i].second;
        if (board[y][x] == 0){  //빈칸
            int ni = i;
            int ny = y; int nx = x;
            while(board[ny][nx] == 0){
                ni++;
                if (ni == N*N) break;
                ny = num[ni].first;
                nx = num[ni].second;
            }
            if (ni == N*N) continue;
            int sub = ni - i;
            for (int j=i; j<N*N; j++){
                ny = num[j].first;
                nx = num[j].second;
                int nny, nnx;
                int tmp = 0;
                if (j + sub < N*N){
                    nny = num[j+sub].first;
                    nnx = num[j+sub].second;
                    tmp = board[nny][nnx];
                } 
                board[ny][nx] = tmp;
            }
        }
    }
}
void explode(){
    while(true){
        int seq = 1;    //연속 갯수
        int prv = -1;
        bool exist = false;
        for (int i=1; i<N*N; i++){
            int y = num[i].first;
            int x = num[i].second;
            if (board[y][x] == prv){
                seq++;
            }
            if (board[y][x] != prv || i == N*N-1){  //다른 거가 생겼거나 마지막에 도착할시
                if (seq >= 4){  //4개 이상 연속 -> 전부 삭제
                    ans += seq*prv;
                    exist = true;
                    if (i!= N*N-1){
                        for (int j=1; j<=seq; j++){
                            int ny = num[i-j].first;
                            int nx = num[i-j].second;
                            board[ny][nx] = 0;
                        }
                    }
                    else{
                        for (int j=0; j<seq; j++){
                            int ny = num[i-j].first;
                            int nx = num[i-j].second;
                            board[ny][nx] = 0;
                        }
                    }
                }
                seq = 1;
                prv = board[y][x];
            }
            if (board[y][x] == 0) break;
        }
        if(!exist) return;
        move();
    }
}
void change(){
    int seq = 1;
    int prv = board[N/2][N/2-1];
    if (prv == 0) return;
    queue<int> q;
    for (int i=2; i<N*N; i++){
        int y = num[i].first;
        int x = num[i].second;
        if (board[y][x] == prv){
            seq++;
        }
        if (board[y][x] != prv || board[y][x] == 0){
            q.push(seq);
            q.push(prv);
            seq = 1;
            prv = board[y][x];
        }
        if (board[y][x] == 0) break;
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            board[i][j] = 0;
    }
    for (int i=1; i<N*N; i++){
        int y = num[i].first;
        int x = num[i].second;
        board[y][x] = q.front();
        q.pop();
        if (q.empty()) break;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int shark_y = N/2, shark_x = N/2;
    board = new int*[N];
    num = new pair<int,int>[N*N];
    int y=N/2, x=N/2;
    int room_num = 1;
    int mv = 1, d=0;
    while(true){
        for (int itr=0; itr<2; itr++){      //mv만큼 2개의 방향으로 움직이기
            for (int i=0; i<mv; i++){
                y += dy[dir[d]];
                x += dx[dir[d]];
                num[room_num].first = y;
                num[room_num].second = x;
                room_num++;
                if (room_num == N*N) break;
            }
            if (room_num == N*N) break;
            d = (d+1)%4;
        }
        mv++;
        if (room_num == N*N) break;
    }
    for (int i=0; i<N; i++){
        board[i] = new int[N];
        for (int j=0; j<N; j++)
            cin >> board[i][j];
    }
    
    while(M--){
        int d, s;
        cin >> d >> s;
        d--;
        for (int i=1; i<=s; i++){
            int ny = shark_y + dy[d] * i;
            int nx = shark_x + dx[d] * i;
            if (ny>=N || nx>=N || ny<0 || nx<0)
                break;
            board[ny][nx] = 0;
        }
        move();
        explode();
        change();
    }
    cout << ans;
    return 0;
}
