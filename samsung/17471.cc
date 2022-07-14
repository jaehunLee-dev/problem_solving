#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
bool visited[11];       //같은 area인지 판단
bool dfs_visited[11];   //dfs에서 방문했는지 판단
int popular[11];
int sum;
int area_sum;
int num;
int ans = 10000;
bool area;  
void dfs(int node){    
    for(auto& i:graph[node]){
        if (!dfs_visited[i] && (visited[i] == area)){     //인접 노드 중 아직 방문하지 않았고, 같은 area인 경우 dfs                                    
            num++;
            dfs_visited[i] = true;        
            area_sum += popular[i];
            //cout << "area_sum: " << area_sum << '\n';
            dfs(i);            
        }
    }  
    return;  
}

void comb(int n,int r, int idx, int total){    //조합 (1개~n/2개 뽑기) , nCr
    if (r == 0){        //다 뽑음 (total개 만큼 뽑음)
        bool area1 = false, area2 = false;
        int sum1 = 0 , sum2 = 0;
        for (int i=1; i<=n; i++){
            if (area1 && area2) break;  
            if (!area1 && visited[i]){  //true/false의 각 처음 노드로 dfs 수행
                area = true;
                dfs_visited[i] = true;
                num = 1, area_sum = popular[i];
                dfs(i);
                //cout << "area_sum: " << area_sum << '\n';
                if (num == total){      //dfs 성공
                    sum1 = area_sum;
                }
                for (int j=1; j<=n; j++)                                
                    dfs_visited[j] = false;
                area1 = true;
            }                
            else if (!area2 && !visited[i]){
                area = false;
                dfs_visited[i] = true;
                num = 1, area_sum = popular[i];
                dfs(i);
                if (num == n-total){
                    sum2 = area_sum;
                }                    
                for (int j=1; j<=n; j++)
                    dfs_visited[j] = false;
                area2 = true;
            }
        }     
        //cout << "sum1: " << sum1 << ", sum2: " << sum2 << '\n';
        if (sum1 !=0 && sum2 != 0 && abs(sum1-sum2) < ans)
            ans = abs(sum1-sum2);           
        return;
    }
    else if (idx == n+1)
        return;
    else{
        visited[idx] = true;
        comb(n,r-1,idx+1,total);
        visited[idx] = false;
        comb(n,r,idx+1,total);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    
    for (int i=1; i<=N; i++){
        cin >> popular[i];
        sum += popular[i];
    }    
    int tmp;    
    vector<int> _tmp;
    graph.push_back(_tmp);
    for (int i=1; i<=N; i++){
        vector<int> tmp_v;
        int itr;
        cin >> itr;
        for (int j=0; j<itr; j++){
            cin >> tmp;
            tmp_v.push_back(tmp);
        }
        graph.push_back(tmp_v);
    }
    for (int i=1; i<=N/2; i++){
        comb(N,i,1,i);
    }
    if (ans == 10000)
        ans = -1;
    cout << ans;
    return 0;
}