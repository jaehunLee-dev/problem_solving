#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, target;    
    cin >> N >> target;
    if (N == 1){
        cout << "1\n1 1";
        return 0;
    }
    int** num = new int*[N];    
    for (int i=0; i<N; i++){
        num[i] = new int[N];
    }
    int itr = 1;
    int idx_sero = N/2, idx_garo = N/2; 
    
    int mode[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};     //위,오른쪽,아래,왼쪽
    int mode_num = -1;
    int ans_sero = idx_sero, ans_garo = idx_garo;
    num[idx_sero][idx_garo] = 1;
    int val = 1;
    while (val<=N*N){     
        for (int k=0; k<2; k++){
            mode_num = (mode_num+1)%4;
            for (int j=0; j<itr; j++ ){                
                idx_sero+=mode[mode_num][0];
                idx_garo+=mode[mode_num][1];
                num[idx_sero][idx_garo] = ++val;
                if (val == target){
                    ans_sero = idx_sero;
                    ans_garo = idx_garo;
                }
                if (val == N*N) break;
            }
            if (val == N*N) break;
        }       
        itr++;     
        if (val == N*N) break;
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cout << num[i][j] << ' ';
        cout << '\n';
    }
    cout << ans_sero+1 << ' ' << ans_garo+1;
    return 0;
}