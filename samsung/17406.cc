#include <iostream>
using namespace std;
int n,m,k;
int** tmp_arr;
bool visited[6];
int tmp_min = 50000;


void rotate(int** arr, int r, int c, int s){        //배열 회전
    for (int i=1; i<=s; i++){       //1~s거리까지 회전
        int first = arr[r-i][c-i];      //복사 각 줄마다 2번,4번,6번,..
        for (int itr = 0; itr < i*2; itr++)
            arr[r-i+itr][c-i] = arr[r-i+itr+1][c-i];      //왼쪽 선 : 위로 옮기기
        for (int itr = 0; itr < i*2; itr++)
            arr[r+i][c-i+itr] = arr[r+i][c-i+itr+1];      //아래 선 : 왼쪽으로 옮기기
        for (int itr = 0; itr < i*2; itr++)
            arr[r+i-itr][c+i] = arr[r+i-itr-1][c+i];      //오른쪽 선 : 아래로 옮기기
        for (int itr = 0; itr < i*2; itr++)
            arr[r-i][c+i-itr] = arr[r-i][c+i-itr-1];      //위 선 : 오른쪽으로 옮기기
        arr[r-i][c-i+1] = first;
    }
}

void dfs(int len, int* seq, int** arr, int* r, int* c, int* s){
    if (len == k){      //순열 완성
        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++)
                tmp_arr[i][j] = arr[i][j];
        }
        for (int i=0; i<k; i++){        //순열순서로 회전 명령 전부 수행
            int idx = seq[i];
            rotate(tmp_arr,r[idx],c[idx],s[idx]);
        }        
        for (int i=1; i<n+1; i++){
            int row_sum = 0;
            for (int j=1; j<m+1; j++){
                row_sum+= tmp_arr[i][j];
            }
            if (row_sum < tmp_min)
                tmp_min = row_sum;
        }
    }
    for (int i=0; i<k; i++){
        if (!visited[i]){
            visited[i] = true;
            seq[len] = i;
            dfs(len+1,seq,arr,r,c,s);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n  >> m >> k;
    int** arr = new int*[n+1];
    tmp_arr = new int*[n+1];
    for (int i=1; i<n+1; i++){
        arr[i] = new int[m+1];
        tmp_arr[i] = new int[m+1];
    }
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++)
            cin >> arr[i][j];
    }
    int* r = new int[k];
    int* c = new int[k];
    int* s = new int[k];
    int* seq = new int[k];  //회전 연산 순서
    for (int i=0; i<k; i++)
        cin >> r[i] >> c[i] >> s[i];
    dfs(0,seq,arr,r,c,s);
    cout << tmp_min;
    return 0;
}