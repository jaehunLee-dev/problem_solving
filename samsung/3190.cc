#include <iostream>
#include <vector>
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
        board[y][x] = 1;    //사과:1, 뱀:2
    }        
    cin >> L;
    pair<int,int> *cmd = new pair<int,int>[L+1];
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
    dir = 0;    //처음 : 오른쪽    
    vector<pair<int,int>> snake;
    snake.push_back(make_pair(1,1));    //처음 뱀 위치
    board[1][1] = 2;
    int cmd_idx = 0;
    int sec = 0;
    while(++sec){        
        int head_y = snake.front().first;
        int head_x = snake.front().second;
        int ny = head_y + dy[dir];
        int nx = head_x + dx[dir];
        if (ny<=0 || nx<=0 || ny > N || nx > N)    //벽 충돌
            break;
        if (board[ny][nx] == 2)     //뱀의 몸 충돌
            break;                
        if (board[ny][nx] == 1){      //사과 먹음   -> 몸 이동할 필요없이 머리만 추가하면 됨            
            snake.insert(snake.begin(),make_pair(ny,nx));   //snake[0]으로 헤드 삽입
        }
        else{   //사과 못먹음 -> 이동
            board[snake.back().first][snake.back().second] = 0;
            for (int idx = snake.size() - 1; idx>0; idx--)
                snake[idx] = snake[idx-1];            
            snake[0].first = ny;
            snake[0].second = nx;
        }
        board[ny][nx] = 2;
        if (sec == cmd[cmd_idx].first){     //방향 전환 시간                            
            dir = dir + cmd[cmd_idx].second;  //1 : 왼쪽, -1 : 오른쪽
            if (dir == 4) dir = 0;
            else if (dir == -1) dir = 3;
            cmd_idx++;
        }
    }
    cout << sec;
    return 0;
}

/*뱀의 위치: pair<int,int> 형 벡터 snake
뱀 머리 : snake[0]
이동 시 머리만 옮기고, 그 뒤 부분은 이전 위치로 옮긴다. (eg. snake[4] = snake[3], snake[3] = snake[2], ... , snake[0] = newdir)
길이 연장 시 헤드만 추가 (젤 앞에)
*/
