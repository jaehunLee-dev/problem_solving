#include <iostream>
using namespace std;
int N, K;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    int up_idx = 1; //올리는 위치의 벨트 번호
    int* A = new int[2*N+1];     //1~2N까지의 벨트 내구도
    bool* exist = new bool[N+1]();    //위치 위 로봇 유무 배열 (벨트번호가 아니라 위치 번호)
    for (int i=1; i<=2*N; i++)
        cin >> A[i];
    int turn = 0;
    while(++turn){
        for (int i=N; i>1; i--)
            exist[i] = exist[i-1];
        exist[1] = false;
        exist[N] = false;   //무조건 N자리는 내림
        if (--up_idx == 0) up_idx = 2*N;
        for (int i=N-1; i>1; i--){  //로봇 i->i+1번째 칸으로 이동하기
            int n_idx = up_idx+i;   //도착지 index
            if (n_idx > 2*N){   //index범위 벗어났을때
                n_idx-=2*N;
            }
            if (exist[i] && !exist[i+1] && A[n_idx] >= 1){  //로봇이 있고, 다음 칸에 로봇이 없고, 다음칸의 내구도 1이상
                A[n_idx]--;
                if (A[n_idx] == 0) K--;
                exist[i+1] = true;
                exist[i] = false;
            }
        }
        if (exist[N]) exist[N] = false;
        if (A[up_idx] > 0){
            A[up_idx]--;
            if (A[up_idx] == 0) K--;
            exist[1] = true;
        }
        if (K<=0) break;
    }
    cout << turn;
    return 0;
}
//올리는 위치: 1, 내리는 위치: N