#include <iostream>
using namespace std;
/*
    a와 b 그래프 구성후, 각 그래프가 가능한지, 즉 dfs로 이어져있는지 확인.
    => a와 b에 들어갈 노드를 조합을 통해 선택해야한다.

    그 후 sum_a와 sum_b의 차이를 구해서 최솟값을 브루트포스로 계산
*/
int n, sum;
int ans = -1;
int visited[11];
int g_size[11];
int popular[11];
char area[11];

int dfs(int** graph, int g_len, int idx, int num);
void comb(int** graph, int len){
    if (len == n+1){        //조합 완성
        int idx_a = -1, idx_b = -1;
        int num_a = 0, num_b = 0;
        for (int i=1; i<len; i++){
            if (area[i] == 'a'){
                num_a++;          
                if (idx_a == -1)
                    idx_a = i;
            }
            else {
                num_b++;
                if (idx_b == -1)
                    idx_b = i;
            }
        }        
        if (idx_a == -1 || idx_b == -1)
            return;                     //모든 지역의 구역이 같으면 return

        /*      본 조합으로 dfs 시작
        for (int i=1; i<len; i++)
            cout << area[i];
        cout << '\n';        
        */
        sum = popular[idx_a];
        int sum_a = dfs(graph,g_size[idx_a],idx_a,num_a);      //a,b에 대해 각각 dfs 수행
        sum = popular[idx_b];
        int sum_b = dfs(graph,g_size[idx_b],idx_b,num_b);
        if (sum_a != -1 && sum_b != -1){
            int sub = abs(sum_a - sum_b);
            if (ans == -1 || sub<ans){
                ans = sub;
                cout << sum_a << ' ' << sum_b << '\n';
            }
        }
        return;
    }
    area[len] = 'a';    
    comb(graph,len+1);
    area[len] = 'b';
    comb(graph,len+1);    
}

int dfs(int** graph, int g_len, int idx, int num){      //불가하면 -1, 그 외에는 dfs 탐색 노드들의 합
    if (num == 0){                  //num == 0 => dfs 성공
        return sum;
    }
    //실패: 노드에서 이미 주변 노드를 모두 방문했을때 => -1 return. 모두 방문하기 전에 sum값 리턴받음 => 성공, sum 그대로 return
    for (int i=0; i<g_len; i++){
        int node = graph[idx][i];
        if (area[node] == area[idx] && !visited[node]){     //같은 색, 아직 방문 안한 노드
            visited[node] = true;
            sum+=popular[node];
            if (dfs(graph,g_size[node],node,num-1) != -1)
                return sum;
            visited[node] = false;
            sum-=popular[node];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;    
    for (int i=1; i<n+1; i++)
        cin >> popular[i];
    int** graph = new int*[n+1];
    for (int i=1; i<n+1; i++){
        cin >> g_size[i];
        graph[i] = new int[g_size[i]];
        for (int j=0; j<g_size[i]; j++){
            cin >> graph[i][j];            
        }
    }
    comb(graph,1);    
    cout << ans;
    return 0;    
}