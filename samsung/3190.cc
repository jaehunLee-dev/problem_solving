#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, K, L;
    int dy[4] = {0,-1,0,1};    //오른쪽,위,왼쪽,아래 (왼쪽,L 방향 회전)
    int dx[4] = {1,0,-1,0};
    cin >> N >> K;
    int** board = new int*[N+1];
    for (int i=1; i<=N; i++)
        board[i] = new int[N+1]();
    for (int i=0;i<K;i++){
        int y, x;
        cin >> y >> x;
    }
    cin >> L;
    pair<int,int> *cmd = new pair<int,int>[L];
    int dir;
    for (int i=0; i<L; i++){
        int X;
        char C;
        cin >> X >> C;
        if (C == 'L')   //왼쪽
            dir = 1;
        else dir = -1;  //오른쪽
        cmd[i].first = X;
        cmd[i].second = dir;
    }
    while(1){

    }
    return 0;
}