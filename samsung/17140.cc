#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
vector<vector<int>> A;  //문제에서는 1,1부터 시작이지만, 실제로는 0,0에서 시작으로 구현
int num[101];

void vec_clear(){
    for (int i=0; i<A.size(); i++)
        A[i].clear();
    A.clear();
}

bool cmp(int a, int b){
    if (num[a] == num[b])
        return a<b;
    return num[a] < num[b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> k;
    r--; c--;
    int t = 0;
    for (int i=0; i<3; i++){
        vector<int> tmp;
        for (int j=0; j<3; j++){
            int tmp2; cin >> tmp2;
            tmp.push_back(tmp2);
        }
        A.push_back(tmp);
    }
    while(t<101){
        if (A.size() > r && A[0].size() > c &&  A[r][c] == k)
            break;
        vector<vector<int>> v;  //계산 결과 벡터
        int r_len = A.size();
        int c_len = A[0].size();
        int max_len = 0;
        if (r_len >= c_len){    //R연산
            for (int i=0; i<r_len; i++){
                vector<int> v2;
                int tmp_len = 0;
                for (int j=0; j<A[i].size(); j++)
                    num[A[i][j]]++;
                sort(A[i].begin(), A[i].end(),cmp);
                for (int j=0; j<A[i].size(); j++){
                    if ((j>0 && A[i][j] == A[i][j-1]) || A[i][j] == 0) continue;   //같은수 또는 0 skip
                    tmp_len++;
                    v2.push_back(A[i][j]);
                    v2.push_back(num[A[i][j]]);
                    num[A[i][j]] = 0;
                }
                v.push_back(v2);
                tmp_len*=2;
                if (tmp_len > max_len)
                    max_len = tmp_len;
            }
            for (auto& itr : v){
                while(itr.size() < max_len)
                    itr.push_back(0);
            }
            vec_clear();
            for (int i=0; i<v.size(); i++){
                vector<int> tmp;
                for (int j=0; j<v[i].size(); j++)
                    tmp.push_back(v[i][j]);
                A.push_back(tmp);
            }
        }
        else{       //C연산
            int** A_cp = new int*[c_len];
            for (int i=0; i<c_len; i++)
                A_cp[i] = new int[r_len];   //A_cp : A 배열을 가로/세로 바꿔서 저장한것
            for (int i=0; i<c_len; i++){
                for (int j=0; j<r_len; j++){
                    A_cp[i][j] = A[j][i];
                }
            }
                        
            for (int i=0; i<c_len; i++){
                vector<int> v2;
                for (int j=0; j<r_len; j++)
                    num[A_cp[i][j]]++;
                sort(A_cp[i],A_cp[i]+r_len,cmp);
                int tmp_len = 0;
                for (int j=0; j<r_len; j++){
                    if ((j>0 && A_cp[i][j] == A_cp[i][j-1] ) || A_cp[i][j] == 0) continue;
                    tmp_len++;
                    v2.push_back(A_cp[i][j]);
                    v2.push_back(num[A_cp[i][j]]);
                    num[A_cp[i][j]] = 0;
                }
                v.push_back(v2);
                tmp_len*=2;
                if (tmp_len > max_len)
                    max_len = tmp_len;
            }
            for (auto& itr : v){
                while(itr.size() < max_len)
                    itr.push_back(0);
            }
            vec_clear();
            for (int i=0; i<v[0].size(); i++){
                vector<int> tmp;
                for (int j=0; j<v.size(); j++)
                    tmp.push_back(v[j][i]);
                A.push_back(tmp);
            }
        }
        t++;
    }
    if (t == 101) t = -1;
    cout << t;
    return 0;
}