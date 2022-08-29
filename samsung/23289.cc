#include <iostream>
#include <vector>
using namespace std;
int R, C, K;
int** temp;
int** cp_temp;
bool*** wall;    //wall[0]: 해당칸의 윗쪽벽, 1: 오른쪽벽, 2: 아래쪽벽, 3: 왼쪽벽
int eat;
int dy[4] = {-1,0,1,0}; //위오아왼
int dx[4] = {0,1,0,-1}; //위오아왼
vector<pair<pair<int,int>, int>> heater;    //히터의 위치와 방향
vector<pair<int,int>> test;                 //검사해야하는 칸
bool** visited; //온풍기로 이미 온도가 올랐는지 검사
void init_visited(){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++)
            visited[i][j] = false;
    }
}
void copy_temp(){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++)
            cp_temp[i][j] = temp[i][j];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    temp = new int*[R];
    cp_temp = new int*[R];
    wall = new bool**[R];
    visited = new bool*[R];
    int ht;
    for (int i=0; i<R; i++){
        temp[i] = new int[C]();
        cp_temp[i] = new int[C]();
        wall[i] = new bool*[C];
        for (int j=0; j<C; j++)
            wall[i][j] = new bool[4]();
        visited[i] = new bool[C]();
        for (int j=0; j<C; j++){
            cin >> ht;
            if (ht == 5) test.push_back(make_pair(i, j));
            else if (ht > 0){
                switch (ht) {
                    case 2:
                        ht = 3;
                        break;
                    case 3:
                        ht = 0;
                        break;
                    case 4:
                        ht = 2;
                        break;
                    default:
                        break;
                }
                heater.push_back(make_pair(make_pair(i, j), ht));
            }
        }
    }
    int W; cin >> W;
    while(W--){
        int y, x, d;
        cin >> y >> x >> d;
        y--; x--;
        if (d == 0){
            wall[y][x][0] = true;
            if (y>0) wall[y-1][x][2] = true;
        }
        else{
            wall[y][x][1] = true;
            if (x<C-1) wall[y][x+1][3] = true;
        }
    }
    while(true){
        for (auto& itr:heater){
            init_visited();
            int y = itr.first.first;
            int x = itr.first.second;
            int dir = itr.second;
            int start_x = x+dx[dir], end_x = x+dx[dir], start_y = y+dy[dir], end_y = y+dy[dir];
            temp[start_y][start_x]+=5;
            visited[start_y][start_x] = true;
            for (int inc = 4; inc>0; inc--){    //inc: 온도가 얼마나 오를지
                int min_y = 22, min_x = 22, max_y = -1, max_x = -1;
                for (int i=start_y; i<=end_y; i++){
                    for (int j = start_x; j<=end_x; j++){
                        if (visited[i][j]){ //온도가 올랐던 칸일경우 온도 전파
                            int ny = i + dy[dir] + dy[(dir+3)%4];
                            int nx = j + dx[dir] + dx[(dir+3)%4];
                            if (ny>=0 && nx>=0 && ny<R && nx<C && !visited[ny][nx] && !wall[i][j][(dir+3)%4] && !wall[ny][nx][(dir+2)%4]){
                                temp[ny][nx]+=inc;
                                visited[ny][nx] = true;
                                if (ny < min_y) min_y = ny;
                                if (nx < min_x) min_x = nx;
                                if (ny > max_y) max_y = ny;
                                if (nx > max_x) max_x = nx;
                            }   //y,x -> y-1,x+1
                            ny = i + dy[dir];
                            nx = j + dx[dir];
                            if (ny>=0 && nx>=0 && ny<R && nx<C && !visited[ny][nx] && !wall[i][j][dir]){
                                temp[ny][nx]+=inc;
                                visited[ny][nx] = true;
                                if (ny < min_y) min_y = ny;
                                if (nx < min_x) min_x = nx;
                                if (ny > max_y) max_y = ny;
                                if (nx > max_x) max_x = nx;
                            }   //y,x -> y,x+1
                            ny = i + dy[dir] + dy[(dir+1)%4];
                            nx = j + dx[dir] + dx[(dir+1)%4];
                            if (ny>=0 && nx>=0 && ny<R && nx<C && !visited[ny][nx] && !wall[i][j][(dir+1)%4] && !wall[ny][nx][(dir+2)%4]){
                                temp[ny][nx]+=inc;
                                visited[ny][nx] = true;
                                if (ny < min_y) min_y = ny;
                                if (nx < min_x) min_x = nx;
                                if (ny > max_y) max_y = ny;
                                if (nx > max_x) max_x = nx;
                            }   //y,x -> y+1,x+1
                        }
                    }
                }
                start_y = min_y; start_x = min_x;
                end_y = max_y; end_x = max_x;
            }
        }
        copy_temp();
        for (int i=0; i<R; i++){
            for (int j=0; j<C; j++){
                int tmp = cp_temp[i][j];
                if (tmp < 4) continue;
                for (int dir=0; dir<4; dir++){
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny>=0 && nx>=0 && ny<R && nx<C &&!wall[i][j][dir]&&(cp_temp[ny][nx] < tmp)){
                        int q_tmp = (tmp - cp_temp[ny][nx])/4;
                        temp[ny][nx] += q_tmp;
                        temp[i][j] -= q_tmp;
                    }
                }
            }
        }
        for (int i=0; i<R; i++){
            if (temp[i][0] > 0) temp[i][0]--;
            if (temp[i][C-1] > 0) temp[i][C-1]--;
        }
        for (int i=1; i<C-1; i++){
            if (temp[0][i] > 0) temp[0][i]--;
            if (temp[R-1][i] > 0) temp[R-1][i]--;
        }
        if(++eat > 100) break;
        bool fin = true;
        for (auto& itr:test){
            int y = itr.first;
            int x = itr.second;
            if (temp[y][x] < K){
                fin = false;
                break;
            }
        }
        if (fin) break;
    }
    cout << eat;
    return 0;
}