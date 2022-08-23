#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
class Fireball{
public:
    int mass = 0;
    int speed = 0;
    int dir = -1;
    int num = 0;    //파이어볼의 갯수
    bool diff = false;  //false : 0,2,4,6 true: 1,3,5,7(이미 다른거 생김)
};
Fireball** board;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    board = new Fireball*[N+1];
    Fireball** cp_board = new Fireball*[N+1];
    for (int i=1; i<=N; i++){
        board[i] = new Fireball[N+1]();
        cp_board[i] = new Fireball[N+1]();
    }
        
    vector<pair<int,int>> v;    //파이어볼의 위치 벡터
    while(M--){
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].mass = m;
        board[r][c].speed = s;
        board[r][c].dir = d;
        board[r][c].num = 1;
        v.push_back(make_pair(r, c));
    }
    while(K--){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                cp_board[i][j] = board[i][j];
                board[i][j].mass = 0;
                board[i][j].speed = 0;
                board[i][j].dir = -1;
                board[i][j].num = 0;
                board[i][j].diff = false;
            }
        }
        for (auto& itr : v){
            int y = itr.first;
            int x = itr.second;
            Fireball f = cp_board[y][x];
            if (f.num == 4){ //파이어볼 4개
                int dir_idx = 0;
                if (f.diff) dir_idx = 1;
                for (int i=0; i<4; i++){    //4방향 이동
                    int ny = y + f.speed * dy[dir_idx];
                    int nx = x + f.speed * dx[dir_idx];
                    if (ny <= 0) ny += ((ny*-1)/N+1)*N;
                    else if (ny > N) ny = ny%N;
                    if (ny == 0) ny = N;
                    if (nx <= 0) nx += ((nx*-1)/N+1)*N;
                    else if (nx > N) nx = nx%N;
                    if (nx == 0) nx = N;
                    board[ny][nx].num++;
                    board[ny][nx].speed += f.speed;
                    board[ny][nx].mass += f.mass;
                    if (board[ny][nx].dir == -1)
                        board[ny][nx].dir = dir_idx;
                    else if (!board[ny][nx].diff && (board[ny][nx].dir % 2 != dir_idx % 2))    //아직 다른거 없고 다른게 생기면
                        board[ny][nx].diff = true;
                    dir_idx+=2;
                }
            }
            else if (f.num == 1){   //파이어볼 1개
                int ny = y + f.speed * dy[f.dir];
                int nx = x + f.speed * dx[f.dir];
                if (ny <= 0) ny += ((ny*-1)/N+1)*N;
                else if (ny > N) ny = ny%N;
                if (ny == 0) ny = N;
                if (nx <= 0) nx += ((nx*-1)/N+1)*N;
                else if (nx > N) nx = nx%N;
                if (nx == 0) nx = N;
                board[ny][nx].num++;
                board[ny][nx].speed += f.speed;
                board[ny][nx].mass += f.mass;
                if (board[ny][nx].dir == -1)
                    board[ny][nx].dir = f.dir;
                else if (!board[ny][nx].diff && (board[ny][nx].dir % 2 != f.dir % 2))    //아직 다른거 없고 다른게 생기면
                    board[ny][nx].diff = true;
            }
        }
        v.clear();
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                if (board[i][j].num > 0){
                    if (board[i][j].num > 1){   //파이어볼 여러개-> 합쳐서 4개로 나누기
                        board[i][j].mass/=5;
                        board[i][j].speed/=board[i][j].num;
                        board[i][j].num = 4;
                        if (board[i][j].mass == 0){
                            board[i][j].speed = 0;
                            board[i][j].dir = -1;
                            board[i][j].num = 0;
                            board[i][j].diff = false;
                            continue;
                        }
                    }
                    v.push_back(make_pair(i, j));
                }
            }
        }
    }
    int ans = 0;
    for (auto& i: v){
        int y = i.first;
        int x = i.second;
        ans += board[y][x].num * board[y][x].mass;
    }
    cout << ans;
    return 0;
}
