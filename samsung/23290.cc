#include <iostream>
#include <vector>
using namespace std;
int M, S;
int s_y, s_x;
vector<int> board[5][5];    //1,1 ~ 4,4 물고기의 방향을 저장함
vector<int> cp_board[5][5];
vector<int> mv_board[5][5];
int smell[5][5];
int dy[8] = {0,-1,-1,-1,0,1,1,1};     //←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[8] = {-1,-1,0,1,1,1,0,-1};
void copy(){
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++)
            cp_board[i][j] = board[i][j];
    }
}
void move(){
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++)
            mv_board[i][j] = board[i][j];
    }
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++)
            board[i][j].clear();
    }
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++){
            for (auto& itr:mv_board[i][j]){
                bool exist = false;
                for (int dir = 0; dir<8; dir++){
                    int ny = i + dy[(itr-dir+8)%8];
                    int nx = j + dx[(itr-dir+8)%8];
                    if (ny>0 && nx>0 && ny<=4 && nx<=4 && smell[ny][nx] == 0 && (ny!=s_y || nx != s_x)){
                        board[ny][nx].push_back((itr-dir+8)%8);
                        exist = true;
                        break;
                    }
                }
                if (!exist) board[i][j].push_back(itr);
            }
        }
    }
}
void shark_move(){
    int sdy[4] = {-1,0,1,0};    //상좌하우
    int sdx[4] = {0,-1,0,1};    //상좌하우
    int max_eat = -1;
    int max_dir[3];
    for (int i=0; i<4; i++){
        int tmp_eat = 0;
        int nsy = s_y + sdy[i];
        int nsx = s_x + sdx[i];
        if (nsy <1 || nsx<1 || nsy>4 || nsx>4) continue;
        for (int j=0; j<4; j++){
            int nnsy = nsy + sdy[j];
            int nnsx = nsx + sdx[j];
            if (nnsy <1 || nnsx<1 || nnsy>4 || nnsx>4) continue;
            for (int k=0; k<4; k++){
                int nnnsy = nnsy + sdy[k];
                int nnnsx = nnsx + sdx[k];
                if (nnnsy <1 || nnnsx<1 || nnnsy>4 || nnnsx>4) continue;
                tmp_eat = board[nsy][nsx].size() + board[nnsy][nnsx].size() + board[nnnsy][nnnsx].size();
                if (nsy == nnnsy && nsx == nnnsx) tmp_eat -= board[nsy][nsx].size();
                if (tmp_eat > max_eat){
                    max_eat = tmp_eat;
                    max_dir[0] = i; max_dir[1] = j; max_dir[2] = k;
                }
            }
        }
    }
    for (int i=0; i<3; i++){
        s_y += sdy[max_dir[i]];
        s_x += sdx[max_dir[i]];
        if (board[s_y][s_x].size() > 0){
            board[s_y][s_x].clear();
            smell[s_y][s_x] = 3;        //이거 확인 필요
        }
    }
}
void del_smell(){
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++){
            if (smell[i][j] >0)
                smell[i][j]--;
        }
    }
}

void copy_done(){
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++){
            for (auto& itr: cp_board[i][j]){
                board[i][j].push_back(itr);
            }
            cp_board[i][j].clear();
        }
    }
}
int count_fish(){
    int ans = 0;
    for (int i=1; i<=4; i++){
        for (int j=1; j<=4; j++)
            ans+=board[i][j].size();
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> S;
    while(M--){
        int y, x, d;
        cin >> y >> x >> d;
        d--;
        board[y][x].push_back(d);
    }
    cin >>s_y>>s_x;
    while(S--){
        copy();
        move();
        shark_move();
        del_smell();
        copy_done();
    }
    cout << count_fish();
    return 0;
}

//우선순위: 상좌하우
//브루트포스로 64가지 방향 다 해보면서, 만약 먹을 수 있는 수 더 많으면 그걸로 tmp_ans 저장하고, 같으면 우선순위 비교해서 저장하기
