#include <iostream>
#include <queue>
using namespace std;
int ans = 11;
int N, M;
pair<int,int> r_idx;
pair<int,int> b_idx;
//아래,오른,위,왼
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
char** board;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    queue< pair < pair< int, int > , int > > red_q;    //좌표, 횟수
    queue< pair < pair< int, int > , int > > blue_q;    //좌표, 횟수
    board = new char*[N];
    for (int i=0; i<N; i++)
        board[i] = new char[M];    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 'R'){
                r_idx.first = i;
                r_idx.second = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B'){
                b_idx.first = i;
                b_idx.second = j;
                board[i][j] = '.';
            }                
        }
    }
    red_q.push(make_pair(r_idx,0));
    blue_q.push(make_pair(b_idx,0));
    while(!red_q.empty()){                
        int y = red_q.front().first.first;
        int x = red_q.front().first.second;
        int num = red_q.front().second;
        red_q.pop();
        int blue_y = blue_q.front().first.first;
        int blue_x = blue_q.front().first.second;
        
        blue_q.pop();
        if (board[blue_y][blue_x] == 'O' || num>=10) continue;        
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int bny = blue_y + dy[i];
            int bnx = blue_x + dx[i];            
            if (board[ny][nx] != '#'){
                while(board[ny][nx] == '.'){
                    ny += dy[i];
                    nx += dx[i];                        
                }                               
                if (board[bny][bnx] != '#'){
                    while(board[bny][bnx] == '.'){
                        bny += dy[i];
                        bnx += dx[i];
                    }
                    if (board[bny][bnx] == '#'){
                        bny -= dy[i];
                        bnx -= dx[i];                                
                    }
                }
                else {
                    bny = blue_y;
                    bnx = blue_x;
                }                

                if (board[ny][nx] == '#'){
                    ny -= dy[i];
                    nx -= dx[i];
                    if (ny == bny && nx == bnx){
                        int r_abs = abs(y - ny) + abs(x-nx);
                        int b_abs = abs(blue_y - bny) + abs(blue_x - bnx);
                        if (r_abs > b_abs){
                            ny -= dy[i];
                            nx -= dx[i];
                        }
                        else{
                            bny -= dy[i];
                            bnx -= dx[i];
                        }                            
                    }
                    if (board[bny][bnx] == 'O')
                        continue;
                    pair<int,int> idx;
                    idx.first = ny; 
                    idx.second = nx;                        
                    red_q.push(make_pair(idx,num+1));                        
                    idx.first = bny;
                    idx.second = bnx;
                    blue_q.push(make_pair(idx,num+1));
                }
                else if (board[ny][nx] == 'O'){
                    if (board[bny][bnx] != 'O'){    //red가 먼저 들어감
                        cout << num+1;
                        exit(0);
                    }                        
                }
            }         
            
            else if (board[bny][bnx] != '#'){
                //red 불가, blue만 가능한 경우
                while(board[bny][bnx] == '.'){
                    bny += dy[i];
                    bnx += dx[i];
                }
                if (board[bny][bnx] == '#'){
                    bny -= dy[i];
                    bnx -= dx[i];                                
                }
                if (bny == y && bnx == x){
                    bny -= dy[i];
                    bnx -= dx[i];
                }            
                if (board[bny][bnx] == 'O')
                    continue;
                pair<int,int> idx;
                idx.first = y;
                idx.second = x;
                red_q.push(make_pair(idx,num+1));
                idx.first = bny;
                idx.second = bnx;
                blue_q.push(make_pair(idx,num+1));
            } 
            
        }
    }
    if (ans > 10) ans = -1;    
    cout << ans;
    return 0;
}