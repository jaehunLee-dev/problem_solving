#include <iostream>
#include <vector>
using namespace std;
int R, C, M;
int ans;
class Shark{
public:
    int s=0, d=0, z=0, r=0, c=0;
};
Shark** board;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> M;
    board = new Shark*[R+1];
    for (int i=0; i<R+1; i++)
        board[i] = new Shark[C+1];
    int fisher = 0; //낚시 자리
    vector<Shark> v;
    while(M--){
        int r, c;
        cin >> r >> c;
        cin >> board[r][c].s >> board[r][c].d >> board[r][c].z;     //z==0 -> 상어 없음
        Shark tmp;
        tmp.s = board[r][c].s;
        tmp.r = r;
        tmp.c = c;
        tmp.d = board[r][c].d;
        tmp.z = board[r][c].z;
        v.push_back(tmp);
    }
    while(++fisher<=C){
        for (int i=1; i<R+1; i++){
            if (board[i][fisher].z != 0){   //상어 발견
                ans+=board[i][fisher].z;
                board[i][fisher].s = 0;
                board[i][fisher].d = 0;
                board[i][fisher].z = 0;
                break;
            }
        }
        vector<Shark> v2;
        for(auto& itr : v){
            int i = itr.r, j = itr.c;
            if (board[i][j].z != 0){    //상어 발견
                int dir = board[i][j].d;
                int ny, nx, dir_cg, mv;
                int speed = board[i][j].s;
                switch (dir) {
                    case 1: //위
                        nx = j;
                        ny = R;
                        speed += R-i;
                        dir_cg = speed / (R-1);
                        mv = speed % (R-1);
                        if (dir_cg%2 == 1){
                            dir = 2;    //아래로 방향 전환
                            ny = 1 + mv;
                        }
                        else ny = R - mv;
                        break;
                        
                    case 2: //아래
                        nx = j;
                        ny = 1;
                        speed += i-1;
                        dir_cg = speed / (R-1);
                        mv = speed % (R-1);
                        if (dir_cg%2 == 1){
                            dir = 1;    //위로 방향 전환
                            ny = R - mv;
                        }
                        else ny = 1 + mv;
                        break;

                    case 3: //오른쪽
                        ny = i;
                        nx = 1;
                        speed += j-1;
                        dir_cg = speed / (C-1);
                        mv = speed % (C-1);
                        if (dir_cg%2 == 1){
                            dir = 4;    //왼쪽으로 방향 전환
                            nx = C - mv;
                        }
                        else nx = 1 + mv;
                        break;
                        
                    case 4: //왼쪽
                        ny = i;
                        nx = C;
                        speed += C-j;
                        dir_cg = speed / (C-1);
                        mv = speed % (C-1);
                        if (dir_cg%2 == 1){
                            dir = 3;    //왼쪽으로 방향 전환
                            nx = 1 + mv;
                        }
                        else nx = C - mv;
                        break;
                        
                    default:
                        break;
                }
                Shark tmp;
                tmp.s = board[i][j].s;
                tmp.d = dir;
                tmp.z = board[i][j].z;
                tmp.r = ny; tmp.c = nx;
                v2.push_back(tmp);
                board[i][j].s = board[i][j].d = board[i][j].z = board[i][j].r = board[i][j].c = 0;
            }
        }
        for (auto& itr: v2){        //새로운 상어 위치
            int i = itr.r, j = itr.c;
            if (board[i][j].z == 0)
                board[i][j] = itr;
            else{   //상어 위치 겹칠 때 -> 더 큰게 더 작은거 먹기
                if (board[i][j].z > itr.z)
                    continue;
                else board[i][j] = itr;
            }
        }
        v.clear();
        for (int i=1; i<R+1; i++){
            for (int j=1; j<C+1; j++){
                if (board[i][j].z != 0)
                    v.push_back(board[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}