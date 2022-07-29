#include <iostream>
using namespace std;
int N, M, x, y, K;
int** map;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    
    cin >> N >> M >> y >> x >> K;
    map = new int*[N];
    int dice[6] = {0};
    for (int i=0; i<N; i++)
        map[i] = new int[M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    }
    int cmd;
    //y,x : 지도에서의 주사위의 y좌표, x좌표
    
    for (int i=0; i<K; i++){
        cin >> cmd;
        switch (cmd)
        {
        case 1: //동쪽
            if (x != M-1){
                x++;
                int tmp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[2];
                dice[2] = tmp;
                if (map[y][x] == 0)
                    map[y][x] = dice[5];                
                else{
                    dice[5] = map[y][x];
                    map[y][x] = 0;
                }
                cout << dice[0] << '\n';
            }
            break;
        
        case 2: //서쪽
            if (x != 0){
                x--;
                int tmp = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[0];
                dice[0] = dice[2];
                dice[2] = tmp;
                if (map[y][x] == 0)
                    map[y][x] = dice[5];                
                else{
                    dice[5] = map[y][x];
                    map[y][x] = 0;
                }
                cout << dice[0] << '\n';
            }
            break;

        case 3: //북쪽
            if (y != 0){
                y--;
                int tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[1];
                dice[1] = tmp;
                if (map[y][x] == 0)
                    map[y][x] = dice[5];                
                else{
                    dice[5] = map[y][x];
                    map[y][x] = 0;
                }
                cout << dice[0] << '\n';
            }
            break;

        case 4: //남쪽
            if (y != N-1){
                y++;
                int tmp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[4];
                dice[4] = tmp;
                if (map[y][x] == 0)
                    map[y][x] = dice[5];
                else{
                    dice[5] = map[y][x];
                    map[y][x] = 0;
                }
                cout << dice[0] << '\n';
            }            
            break;
        
        default:
            break;
        }
    }    
    return 0;
}

    /*
      1
    3 0 2
      4
      5
    아랫면 : dice[5]
    윗 면 : dice[0]
    */