#include <iostream>
using namespace std;
class Fish{
public:
    int num = -1;
    int dir = -1;
};

int dy[8] = {-1,-1,0,1,1,1,0,-1}; //위부터 반시계
int dx[8] = {0,-1,-1,-1,0,1,1,1};
Fish fish[4][4];
bool visited[17]; //visited를 이걸로 하면 안되고 물고기로 해야함, 즉 물고기 번호로
int ans;
pair<int,int> fish_idx[17]; //1~16까지 물고기의 좌표

void dfs(int s_r, int s_c, int eat){   //상어의 좌표
    //물고기 이동
    for (int i=1; i<=16; i++){
        if (fish_idx[i].first != -1){   //아직 안먹힌 물고기만 이동
            int y = fish_idx[i].first;
            int x = fish_idx[i].second;
            int fish_n = fish[y][x].num;
            int dir = fish[y][x].dir;
            for (int j=0; j<8; j++){
                int nd = (dir+j)%8;    //반시계방향으로 한칸씩 움직이며 확인
                int ny = y + dy[nd];
                int nx = x + dx[nd];
                
                if (ny<4 && nx<4 && ny>=0 && nx>=0 && (ny!=s_r || nx!=s_c)){  //벽 또는 상어가 아니라면 이동 및 교체
                    fish[y][x].dir = fish[ny][nx].dir;
                    fish[y][x].num = fish[ny][nx].num;
                    fish_idx[i].first = ny;
                    fish_idx[i].second = nx;
                    if (fish_idx[fish[ny][nx].num].first != -1){
                        fish_idx[fish[ny][nx].num].first = y;
                        fish_idx[fish[ny][nx].num].second = x;
                    }
                    fish[ny][nx].num = i;
                    fish[ny][nx].dir = nd;
                    break;
                }
            }
        }
    }
        
    //상어가 물고기 먹기
    int d = fish[s_r][s_c].dir;
    int ny = s_r, nx = s_c;
    bool able = false;
    
    while(true){
        ny += dy[d];
        nx += dx[d];
        if (ny>=4 || nx >=4 || ny<0 || nx<0)    //범위 벗어나면 break
            break;
        else if (visited[fish[ny][nx].num]) continue; //이미 먹은 곳은 못감
        else{
            able = true;    //먹을 수 있는게 있음
            Fish fish_cp[4][4];
            pair<int,int> idx_cp[17];
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++)
                    fish_cp[i][j] = fish[i][j];
            }
            for (int i=0; i<17; i++)
                idx_cp[i] = fish_idx[i];
            visited[fish[ny][nx].num] = true;
            fish_idx[fish[ny][nx].num].first = -1;
            dfs(ny,nx,eat+fish[ny][nx].num);
            visited[fish[ny][nx].num] = false;
            for (int i=0; i<4; i++){
                for (int j=0; j<4; j++)
                    fish[i][j] = fish_cp[i][j];
            }
            for (int i=0; i<17; i++)
                fish_idx[i] = idx_cp[i];
        }
    }
    if (!able){ //못먹음 -> 상어 이동 끝, 이때까지 먹은 것 계산
        if (eat > ans) ans = eat;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tmp;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            int t_num;
            cin >> t_num;
            fish[i][j].num = t_num;
            fish_idx[t_num].first = i;
            fish_idx[t_num].second = j;
            cin >> tmp;
            fish[i][j].dir = tmp -1;
        }
    }
    int eaten = fish[0][0].num;
    visited[eaten] = true;
    fish_idx[fish[0][0].num].first = -1;
    fish_idx[fish[0][0].num].second = -1;    //이미 먹힌 고기의 좌표: -1,-1
    dfs(0,0,eaten);
    cout << ans;
    return 0;
}