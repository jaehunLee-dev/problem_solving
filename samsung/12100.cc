#include <iostream>
#include <vector>
using namespace std;
int N;
int** board;
int** cp_board;
int ans;
void dfs(int len, string cmd){
    if (len == 5){        
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++)
                board[i][j] = cp_board[i][j];
        }        

        for (int cmd_i=0; cmd_i<5; cmd_i++){            
            switch (cmd[cmd_i])
            {
            case 'U':       //위로 올리기 -> 위부터 확인
                for (int i=0; i<N; i++){
                    vector<int> v;
                    for (int j=0; j<N; j++){
                        if (board[j][i] == 0)   continue;   //빈칸일 경우, pass
                        int prv = board[j][i];
                        j++;
                        while (j !=N && board[j][i] == 0){
                            j++;
                        }
                        if (j == N)
                            v.push_back(prv);
                        else if (prv == board[j][i])  //합치기
                            v.push_back(2*board[j][i]);                                                                                
                        else {
                            v.push_back(prv);
                            j--;                                                      
                        }
                    }
                    for (int k=0; k<v.size(); k++)
                        board[k][i] = v[k];
                    for (int k=v.size(); k<N; k++)
                        board[k][i] = 0;
                }
                break;
            
            case 'D':       //아래로 내리기 -> 아래부터 확인
                for (int i=0; i<N; i++){
                    vector<int> v;
                    for (int j=N-1; j>=0; j--){
                        if (board[j][i] == 0)   continue;   //빈칸일 경우, pass
                        int prv = board[j][i];
                        j--;
                        while (j!=-1 && board[j][i] == 0){
                            j--;
                        }
                        if (j == -1){
                            v.push_back(prv);
                        }
                        else if (prv == board[j][i])
                            v.push_back(2*board[j][i]);                                                    
                        else {
                            v.push_back(prv);
                            j++;
                        }
                    }
                    int tmp = N-v.size();
                    for (int k=N-1; k >= tmp; k--){                    
                        board[k][i] = v[N-1-k];                        
                    }
                    for (int k=tmp-1; k>=0; k--)
                        board[k][i] = 0;
                }
                break;

            case 'R':       //오른쪽으로 옮기기-> 오른쪽부터 확인
                for (int i=0; i<N; i++){
                    vector<int> v;
                    for (int j=N-1; j>=0; j--){   
                        if (board[i][j] == 0)   continue;   //빈칸일 경우, pass
                        int prv = board[i][j];
                        j--;
                        while (j!=-1 && board[i][j] == 0){
                            j--;
                        }
                        if (j == -1)
                            v.push_back(prv);                     
                        else if (prv == board[i][j])  //합치기
                            v.push_back(2*board[i][j]);                                                    
                        else{   //다를 때
                            v.push_back(prv);
                            j++;
                        } 
                    }
                    int tmp = N-v.size();
                    for (int k=N-1; k>=tmp; k--)
                        board[i][k] = v[N-1-k];
                    for (int k=tmp-1; k>=0; k--)
                        board[i][k] = 0;                    
                }
                break;

            case 'L':       //왼쪽으로 옮기기-> 왼쪽부터 확인
                for (int i=0; i<N; i++){
                    vector<int> v;
                    for (int j=0; j<N; j++){
                        if (board[i][j] == 0)   continue;   //빈칸일 경우, pass
                        int prv = board[i][j];
                        j++;
                        while (j!=N && board[i][j] == 0){
                            j++;
                        }
                        if (j == N)
                            v.push_back(prv);         
                        else if (prv == board[i][j])  //합치기
                            v.push_back(2*board[i][j]);                            
                        
                        else {
                            v.push_back(prv);
                            j--;
                        }
                    }
                    for (int k=0; k<v.size(); k++)
                        board[i][k] = v[k];
                    for (int k=v.size(); k<N; k++)
                        board[i][k] = 0;
                }
                break;
            default:
                break;
            }            
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (board[i][j] > ans)
                    ans = board[i][j];
            }
        }
        return;
    }
    dfs(len+1,cmd+"U");
    dfs(len+1,cmd+"D");
    dfs(len+1,cmd+"L");
    dfs(len+1,cmd+"R");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    board = new int*[N];
    cp_board = new int*[N];
    for (int i=0; i<N; i++){
        board[i] = new int[N];
        cp_board[i] = new int[N];
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cin >> cp_board[i][j];
    }
    dfs(0,"");
    cout << ans;
    return 0;
}