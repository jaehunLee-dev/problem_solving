#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, L;
    cin >> N >> L;
    int** arr = new int*[N];
    for (int i=0; i<N; i++)
        arr[i] = new int[N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cin >> arr[i][j];
    }
    vector<vector<int>> way;
    for (int i=0; i<N; i++){
        vector<int> tmp;
        vector<int> tmp2;
        for (int j=0; j<N; j++){
            tmp.push_back(arr[j][i]);
            tmp2.push_back(arr[i][j]);
        }
        way.push_back(tmp);
        way.push_back(tmp2);
    }
    int ans = 0;
    for (int i=0; i<2*N; i++){
        bool *bridge = new bool[N]();   //다리 있으면 true, 없으면 false
        for (int j=0; j<N-1; j++){
            if (abs(way[i][j] - way[i][j+1]) > 1)
                break;
            if (way[i][j] < way[i][j+1]){   //뒤가 더 높음 -> j부터 j-L+1까지 다리 건설해야함
                if (j<L-1) break;
                bool out = false;          
                if (bridge[j] == true) break;
                for (int k=j-L+1; k<j; k++){
                    if (way[i][k] != way[i][k+1] || bridge[k] == true){
                        out = true;
                        break;
                    }                    
                }
                if (out) break;
                else{
                    for (int k=j-L+1; k<=j; k++){
                        bridge[k] = true;
                    }
                }
            }
            else if (way[i][j] > way[i][j+1]){  //뒤가 더 낮음  -> j+1부터 j+L까지 다리 건설
                if (j+L >= N) break;
                bool out = false;
                for (int k=j+1; k<j+L; k++){
                    if (way[i][k] != way[i][k+1]){
                        out = true;
                        break;
                    }
                }
                if (out) break;
                else{
                    for (int k=j+1; k<j+L+1; k++)
                        bridge[k] = true;
                }
            }
            if (j == N-2){
                ans++;                
            } 
        }
    }
    cout << ans;
    return 0;
}