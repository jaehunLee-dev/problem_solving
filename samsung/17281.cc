#include <iostream>
using namespace std;
int n, ans;
bool visited[10];
int seq[10];
void simulation(int** score){
    int now = 0;
    int tmp_score = 0;
    for (int i=1; i<=n; i++){       //n회 진행
        int out = 0;
        int base[4]{};   //1루,2루,3루,홈       매 회 base 초기화
        while(1){        
            if (out == 3)
                break;    
            now = now%9+1;
            if (score[i][seq[now]] == 0)             //아웃
                out++;
            else if (score[i][seq[now]] == 1){       //1루타
                for (int i=3; i>0; i--)
                    base[i] = base[i-1];
                base[0] = 1;
            }
            else if (score[i][seq[now]] == 2){       //2루타
                base[3] = base[2] + base[1];      //홈 인 : 2루, 3루
                base[2] = base[0];  //1루 있으면 3루로
                base[1] = 1;        //2루 한명
                base[0] = 0;
            }
            else if (score[i][seq[now]] == 3){       //3루타
                base[3] = base[2] + base[1] + base[0];  //홈 인 : 1루, 2루, 3루
                base[0] = base[1] = 0;
                base[2] = 1;
            }
            else if (score[i][seq[now]] == 4){       //홈런
                base[3] = base[0] + base[1] + base[2] + 1;
                base[0] = base[1] = base[2] = 0;
            }
            if (base[3] > 0){
                tmp_score += base[3];
                base[3] = 0;
            }                
        }        
    }
    if (tmp_score > ans)
        ans = tmp_score;           
}
void dfs(int len, int** score){
    if (len == 10){     
        simulation(score);
        return;
    }
    if (len == 4){
        seq[len] = 1;
        visited[1] = true;
        dfs(len+1,score);
    }
    else{
        for (int i=2; i<10; i++){
            if (!visited[i]){
                visited[i] = true;
                seq[len] = i;
                dfs(len+1,score);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;            
    int** score = new int*[n+1];
    for (int i=1; i<n+1; i++)       //1회~n회
        score[i] = new int[10];     //1번타자~9번타자
    for (int i=1; i<n+1; i++){
        for (int j=1; j<=9; j++)
            cin >> score[i][j];
    }
    dfs(1,score);    
    cout << ans;
    return 0;
}