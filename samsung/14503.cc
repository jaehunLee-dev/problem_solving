#include <iostream>
using namespace std;
int N, M;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
    cin >> N >> M;
    int r, c, d;
    int** board = new int*[N];    
    for (int i=0; i<N; i++)
        board[i] = new int[M];
    cin >> r >> c >> d;    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }    
    int ans = 0;
    //0: 북, 1: 동, 2: 남, 3:서 (위,오른쪽,아래,왼쪽)
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};
    while(++ans){
        board[r][c] = 2;
        for (int i=0; i<4; i++){
            d--;
            if (d < 0) d = 3;
            int ny = r + dy[d];
            int nx = c + dx[d];
            if (ny<N && nx<M && ny>=0 && nx>=0){
                if (board[ny][nx] == 0){
                    r = ny;
                    c = nx;
                    break;
                }                
            }
            if (i == 3){
                ny = r - dy[d];
                nx = c - dx[d];
                if (ny<N && nx<M && ny>=0 && nx>=0 && board[ny][nx] != 1){                    
                    r = ny;
                    c = nx;
                    ans--;  //청소 못하고 후진
                    break;                                    
                }
                else{
                    cout << ans;
                    return 0;
                }
            }
        }
    }
    return 0;
}