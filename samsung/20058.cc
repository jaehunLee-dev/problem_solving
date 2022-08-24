#include <iostream>
#include <queue>
using namespace std;
int N, Q, t_n;
int** board;
int** cp_board;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
void b_copy(){
    for (int i=0; i<t_n; i++){
        for (int j=0; j<t_n; j++)
            cp_board[i][j] = board[i][j];
    }
}
void simulation(int l){
    b_copy();
    int start_i = 0, start_j = 0;
    while(1){       //회전하기
        for (int i=0; i<l; i++){
            for (int j=0; j<l; j++){
                board[start_i+i][start_j+j] = cp_board[start_i+l-1-j][start_j+i];
            }
        }
        start_i += l;
        if (start_i == t_n){
            start_i = 0;
            start_j += l;
        }
        if (start_j >= t_n) break;
    }
    b_copy();
    for(int i=0; i<t_n; i++){
        for (int j=0; j<t_n; j++){
            if (board[i][j] == 0) continue;
            int no_adj = 0;
            for (int dir=0; dir<4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (ny>=0 && nx>=0 && ny<t_n && nx<t_n){
                    if (cp_board[ny][nx] == 0)
                        no_adj++;
                }
                else no_adj++;      //칸이 없으면 인접한곳에 얼음도 없음
                if (no_adj > 1){
                    board[i][j]--;
                    break;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    t_n = 1<<N;
    board = new int*[t_n];
    cp_board = new int*[t_n];
    for (int i=0; i<t_n; i++){
        board[i] = new int[t_n];
        cp_board[i] = new int[t_n];
        for (int j=0; j<t_n; j++)
            cin >> board[i][j];
    }
    while(Q--){
        int L; cin >> L;
        int l = 1<<L;
        simulation(l);
    }
    int ans1 = 0, ans2 = 0;
    for (int i=0; i<t_n; i++){
        for (int j=0; j<t_n; j++)
            ans1+=board[i][j];
    }
    queue<pair<int,int>> q;
    for (int i=0; i<t_n; i++){
        for (int j=0; j<t_n; j++){
            if (board[i][j] > 0){
                int tmp_ans = 1;
                q.push(make_pair(i, j));
                board[i][j] = 0;
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int dir=0; dir<4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if (ny>=0 && nx>=0 && ny<t_n && nx<t_n && board[ny][nx] > 0){
                            board[ny][nx] = 0;
                            q.push(make_pair(ny, nx));
                            tmp_ans++;
                        }
                    }
                }
                if (tmp_ans > ans2) ans2 = tmp_ans;
            }
        }
    }
    cout << ans1 << '\n' << ans2;
    return 0;
}
//파이어스톰 시전 마다 보드 복사 후, 범위에 따라 나눴다는 가정으로 회전하기, 그 후 모든 칸 돌면서 인접 확인 후 양 줄이기
