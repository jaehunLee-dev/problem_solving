#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> q;
int R, C, T;
int** A;
int** spread;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> T;
    A = new int*[R];        //현재 먼지 배열
    spread = new int*[R];   //확산용 배열
    int air = 0;    //공기 청정기의 아래 위치
    for (int i=0; i<R; i++){
        A[i] = new int[C];
        spread[i] = new int[C]();
    }
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            cin >> A[i][j];
            if (A[i][j] == -1)
                air = i;
        }
    }
    while(T--){
        //먼지 이동 계산
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                if (A[i][j] > 0){   //먼지 있는 상태
                    int mv = A[i][j]/5;
                    for (int dir = 0; dir<4; dir++){
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (ny>=0 && nx>=0 && ny<R && nx<C && A[ny][nx] != -1){
                            spread[ny][nx] += mv;
                            A[i][j] -= mv;
                        }
                    }
                }
            }
        }
        //먼지 이동 시작
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                A[i][j] += spread[i][j];
                spread[i][j] = 0;
            }
        }
        //아래 공기 정화 시작
        for (int i = air+1; i<R-1; i++)
            A[i][0] = A[i+1][0];
        for (int i=0; i<C-1; i++)
            A[R-1][i] = A[R-1][i+1];
        for (int i=R-1; i>air; i--)
            A[i][C-1] = A[i-1][C-1];
        for (int i=C-1; i>1; i--)
            A[air][i] = A[air][i-1];
        A[air][1] = 0;
        air--;  //윗 공기 정화 시작
        for (int i=air-1; i>0; i--)
            A[i][0] = A[i-1][0];
        for (int i=0; i<C-1; i++)
            A[0][i] = A[0][i+1];
        for (int i=0; i<air; i++)
            A[i][C-1] = A[i+1][C-1];
        for (int i=C-1; i>1; i--)
            A[air][i] = A[air][i-1];
        A[air][1] = 0;
        air++;
    }
    int ans=0;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++)
            ans += A[i][j];
    }
    ans+=2;
    cout << ans;
    return 0;
}