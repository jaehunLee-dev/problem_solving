#include <iostream>
using namespace std;
int N, M, x, y, K;
int** map;
int* cmd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
    cin >> N >> M >> x >> y >> K;
    map = new int*[N];
    for (int i=0; i<N; i++)
        map[i] = new int[M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    }
    cmd = new int[K];
    for (int i=0; i<K; i++)
        cin >> cmd[i];
    return 0;
}