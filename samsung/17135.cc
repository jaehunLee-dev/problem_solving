#include <iostream>
using namespace std;
int main(){
    int n,m,d;
    cin >> n >> m >> d;
    int** arr_org = new int*[n];        //궁수랑 거리 : n-y_idx + abs(x2 - x1)
    for (int i=0; i<n; i++)
        arr_org[i] = new int[m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            cin >> arr_org[i][j];
    }

    int** arr = new int*[n];
    for (int i=0; i<n; i++)
        arr[i] = new int[m];

    int ans = 0;    

    



    for (int i=0; i<m; i++){
        for (int j=i+1; j<m; j++){
            for (int k=j+1; k<m; k++){      //궁수 좌표 : (n,i), (n,j), (n,k) => 시뮬레이션 시작                                
                for (int itr1=0; itr1<n; itr1++){
                    for (int itr2=0; itr2<m; itr2++)
                        arr[itr1][itr2] = arr_org[itr1][itr2];
                }                                

                int tmp_ans = 0;
                for (int itr = 0; itr<n; itr++){        //적 1턴마다 전진
                    int i_min=d+1, j_min=d+1, k_min=d+1, i_x=m, j_x=m, k_x=m, i_y=n, j_y=n, k_y=n;
                    for (int height = n-1; height>=n-d; height--){
                        if (height <0 ) continue;
                        for (int width = 0; width<m; width++){                            
                            if (arr[height][width] == 1){   //적 발견                                
                                if (n-height + abs(i-width) <= d){
                                    if (n-height + abs(i-width) == i_min){
                                        if (i_x > width){
                                            i_x = width;
                                            i_y = height;
                                        }
                                    }
                                    else if (n-height + abs(i-width) < i_min){
                                        i_min = n-height + abs(i-width);
                                        //i가 죽일 적의 위치
                                        i_x = width;
                                        i_y = height;
                                    }                                    
                                }                                
                                if (n-height + abs(j-width) <= d){
                                    if (n-height + abs(j-width) == j_min){
                                        if (j_x > width){
                                            j_x = width;
                                            j_y = height;
                                        }
                                    }
                                    else if (n-height + abs(j-width) < j_min){
                                        j_min = n-height + abs(j-width);
                                        //j가 죽일 적의 위치
                                        j_x = width;
                                        j_y = height;
                                    }                                    
                                }                                
                                if (n-height + abs(k-width) <= d){
                                    if (n-height + abs(k-width) == k_min){
                                        if (k_x > width){
                                            k_x = width;
                                            k_y = height;
                                        }
                                    }
                                    else if (n-height + abs(k-width) < k_min){
                                        k_min = n-height + abs(k-width);
                                        //k가 죽일 적의 위치
                                        k_x = width;
                                        k_y = height;
                                    }                                                                                          
                                }
                                //각각의 궁수에서 적 선택 완료.
                            }
                        }
                    }
                    
                    if (i_y != n && arr[i_y][i_x] == 1){
                        arr[i_y][i_x] = 0;
                        tmp_ans++;
                    }
                    if (j_y != n && arr[j_y][j_x] == 1){
                        arr[j_y][j_x] = 0;
                        tmp_ans++;
                    }
                    if (k_y != n && arr[k_y][k_x] == 1){
                        arr[k_y][k_x] = 0;
                        tmp_ans++;
                    }
                    
                    //죽이기 완료, 적 전진 시작.
                    
                    for (int mv_y = n-1; mv_y > 0; mv_y--){
                        for (int mv_x = 0; mv_x<m; mv_x++)
                            arr[mv_y][mv_x] = arr[mv_y-1][mv_x];                        
                    }                
                    for (int mv_x = 0; mv_x<m; mv_x++)
                        arr[0][mv_x] = 0;               
                }                
                if (tmp_ans > ans)
                ans = tmp_ans;     
            }
        }
    }
    cout << ans;
    return 0;
}