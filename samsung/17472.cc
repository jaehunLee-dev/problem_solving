#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int** map;  //지도
int** graph;    //거리
bool visited[10][10];
int N, M;
int dx[4] = {0,1,0,-1}; //위,오른쪽,아래,왼쪽
int dy[4] = {-1,0,1,0};

int num_isl(){
    int rtn = 0;
    queue<pair<int,int>> q;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){            
            if (map[i][j] == 1 && !visited[i][j]){                
                rtn++;                
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    map[y][x] = rtn;        //섬 번호 붙이기                    
                    q.pop();
                    visited[y][x] = true;
                    for (int dir=0; dir<4; dir++){
                        int ny = y+dy[dir];
                        int nx = x+dx[dir];
                        if (ny < N && ny >= 0 && nx < M && nx >=0){
                            if (map[ny][nx] == 1 && !visited[ny][nx]){                                
                                visited[ny][nx] = true;
                                q.push(make_pair(ny,nx));
                            }
                        }
                    }
                }                
            }
        }
    }
    return rtn;
}

void calc_dist(){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){            
            if (map[i][j] != 0){
                int start_isl = map[i][j];
                for (int k=0; k<4; k++){
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if (ny == N || nx == M || ny == -1 || nx == -1)
                        continue;
                    if (map[ny][nx] == 0){      //바다
                        int dist = 0; 
                        bool out_range = false;                       
                        while (map[ny][nx] != 0){       //땅 만날 때까지 같은 방향으로 이동
                            ny = ny+dy[k];
                            nx = nx+dx[k];
                            dist++;
                            if (ny == N || nx == M || ny == -1 || nx == -1){
                                out_range = true;
                                break;
                            }                        
                        }
                        if (out_range || dist<2)  continue; //최소 거리 2 또는 땅 발견 못함
                        if (map[ny][nx] != start_isl){      //다른 섬 도착
                            int dst_isl = map[ny][nx];
                            if (graph[start_isl][dst_isl] == -1 || graph[start_isl][dst_isl] > dist)
                                graph[start_isl][dst_isl] = dist;   // 2 이상의 최소길이 다리만 저장.
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    cin >> N >> M;
    map = new int*[N];
    for (int i=0; i<N; i++){
        map[i] = new int[M];        
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cin >> map[i][j];
    }        
    int island_num = num_isl();
    cout << island_num << '\n';
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
    graph = new int*[island_num+1];     //graph[i][j] : i섬에서 j섬까지의 거리
    for (int i=0; i<island_num+1; i++)
        graph[i] = new int[island_num+1];
    for (int i=0; i<island_num+1; i++){
        for (int j=0; j<island_num+1; j++)
            graph[i][j] = -1;
    }                
    calc_dist();
    for (int i=1; i<=island_num; i++){
        for (int j=1; j<=island_num; j++)
            cout << graph[i][j] << ' ';
        cout << '\n';
    }  
    bool* isl_visited = new bool[island_num+1]();
    //1번 섬부터 출발, prim 알고리즘
    isl_visited[1] = true;
    for (int i=0; i<island_num-1; i++){
        int min_dis = 10;
        int isl_ver = -1;
        int from = -1;
        for (int j=1; j<=island_num; j++){
            if (isl_visited[j]){        //이미 방문한 섬에서 가장 짧은 edge 선택
                cout << "possible: " << j << '\n';
                for (int k=1; k<=island_num; k++){
                    if (!isl_visited[k] && graph[j][k] != -1 && graph[j][k] < min_dis){      //아직 방문안한 섬, 연결되있고, 가장짧은 edge
                        min_dis = graph[j][k];
                        isl_ver = k;
                        from = j;
                    }
                }
            }
        }
        isl_visited[isl_ver] = true;
        cout << from << " connect to " << isl_ver << ",length: "<< min_dis << '\n';
        ans+=min_dis;
    }
    cout << ans;
    return 0;
}

/*
섬이 무조건 직사각형이 아니기떄문에 거리계산 다시해야함.
*/