#include <iostream>
using namespace std;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int N;
int** board;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    board = new int*[N+1];
    for (int i=1; i<=N; i++)
        board[i] = new int[N+1]();  //빈 자리: 0
    int student;
    int** favorite = new int*[N*N+1];
    for (int i=1; i<=N*N+1; i++)
        favorite[i] = new int[4];
    for (int i=1; i<=N*N; i++){
        cin >> student;
        for (int j=0; j<4; j++)
            cin >> favorite[student][j];
        int fav_num = -1, blank_num = -1;
        int ans_y = -1, ans_x = -1;
        for (int y=1; y<=N; y++){ //빈 칸 확인
            for (int x=1; x<=N; x++){
                if (board[y][x] != 0) continue;
                int tmp_fav = 0;
                int tmp_blank = 0;
                for (int dir=0; dir<4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny>0 && nx>0 && ny<=N && nx<=N){
                        for (int j=0; j<4; j++){
                            if (board[ny][nx] == favorite[student][j])
                                tmp_fav++;
                            else if (board[ny][nx] == 0)
                                tmp_blank++;
                        }
                    }
                }
                if (tmp_fav > fav_num){
                    fav_num = tmp_fav;
                    blank_num = tmp_blank;
                    ans_y = y;
                    ans_x = x;
                }
                else if (tmp_fav == fav_num){   //좋아하는 학생 수 같으면->빈칸 더 많은걸로
                    if (tmp_blank > blank_num){
                        blank_num = tmp_blank;
                        ans_y = y;
                        ans_x = x;
                    }
                    else if (tmp_blank == blank_num){   //빈칸 수도 같으면 -> 행번호, 열번호 작은걸로
                        if (y < ans_y){
                            ans_y = y;
                            ans_x = x;
                        }
                        else if (y == ans_y && x < ans_x)
                            ans_x = x;
                    }
                }
            }
        }
        board[ans_y][ans_x] = student;
    }
    int ans = 0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            int tmp = 0;
            int stu = board[i][j];
            for (int dir=0; dir<4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (ny>0 && nx>0 && ny<=N && nx<=N){
                    for (int k=0; k<4; k++){
                        if (board[ny][nx] == favorite[stu][k]){
                            tmp++;
                            break;
                        }
                    }
                }
            }
            switch (tmp) {
                case 1:
                    ans+=1;
                    break;
                
                case 2:
                    ans+=10;
                    break;
                
                case 3:
                    ans+=100;
                    break;
                    
                case 4:
                    ans+=1000;
                    break;
                    
                default:
                    break;
            }
        }
    }
    cout << ans;
    return 0;
}
