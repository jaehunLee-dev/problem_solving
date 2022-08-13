#include <iostream>
#include <climits>
using namespace std;
int N;
int** A;
int ans = INT_MAX;
void check(int& popular, int& min, int& max){
    if (popular > max) max = popular;
    if (popular < min) min = popular;
    popular = 0;    //다음 영역 계산을 위해 초기화
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    A = new int*[N];
    for (int i=0; i<N; i++){
        A[i] = new int[N];
        for (int j=0; j<N; j++)
            cin >> A[i][j];
    }
    for (int r=0; r<N; r++){
        for (int c=0; c<N; c++){
            for (int d1=1; d1<N-1; d1++){
                for (int d2=1; d2<N-1; d2++){
                    if (r+d1+d2 > N-1 || d1 > c || d2 > N-1-c)
                        break;
                    int tmp_popular = 0;
                    int max_popular = INT_MIN;
                    int min_popular = INT_MAX;
                    //5번 지역 인구 -> 높이를 낮춰가면서
                    int start_idx = c;
                    int end_idx = c;
                    //각 조합에서 인구 계산 시작
                    // 5번 영역계산
                    for (int high = 0; high<=d1+d2; high++){
                        for (int idx = start_idx; idx <= end_idx; idx++){
                            tmp_popular+= A[r+high][idx];
                        }
                        if (high < d1)
                            start_idx--;
                        else start_idx++;
                        if (high < d2)
                            end_idx++;
                        else end_idx--;
                    }
                    check(tmp_popular,min_popular,max_popular);
                    // 1번 영역 계산
                    for (int i = 0; i<=r-1; i++){  //r,c 윗부분까지 계산
                        for (int j = 0; j<=c; j++)
                            tmp_popular+=A[i][j];
                    }
                    end_idx = c;
                    for (int high = r; high<r+d1; high++){
                        end_idx--;
                        for (int idx = 0; idx<=end_idx; idx++){
                            tmp_popular+=A[high][idx];
                        }
                    }
                    
                    check(tmp_popular,min_popular,max_popular);
                    //3번 영역 계산
                    end_idx = c - d1 - 1;
                    for (int high = r+d1; high<=r+d1+d2; high++){ //수정
                        for (int idx = 0; idx<=end_idx; idx++){
                            tmp_popular+=A[high][idx];
                        }
                        end_idx++;
                    }
                    for (int high = r+d1+d2+1; high<N; high++){
                        for (int idx = 0; idx<end_idx; idx++)
                            tmp_popular+=A[high][idx];
                    }
                    check(tmp_popular,min_popular,max_popular);
                    //2번 영역 계산
                    start_idx = c+1;
                    for (int high = 0; high<=r; high++){
                        for (int idx=start_idx; idx<N; idx++)
                            tmp_popular+=A[high][idx];
                    }
                    for (int high = r+1; high<=r+d2; high++){
                        start_idx++;
                        for (int idx = start_idx; idx<N; idx++)
                            tmp_popular+=A[high][idx];
                    }
                    check(tmp_popular,min_popular,max_popular);
                    //4번 영역 계산
                    start_idx = c+d2;
                    for (int high = r+d2+1; high<=r+d1+d2; high++){
                        for (int idx = start_idx; idx<N; idx++){
                            tmp_popular+=A[high][idx];
                        }
                        start_idx--;
                    }
                    for (int high = r+d1+d2+1; high<N; high++){
                        for (int idx = start_idx; idx<N; idx++)
                            tmp_popular+=A[high][idx];
                    }
                    check(tmp_popular,min_popular,max_popular);
                    tmp_popular = max_popular - min_popular;
                    if (tmp_popular < ans)
                        ans = tmp_popular;
                }
            }
        }
    }
    cout << ans;
    return 0;
}