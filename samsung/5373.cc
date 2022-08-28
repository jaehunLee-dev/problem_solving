#include <iostream>
using namespace std;
char cube[6][3][3]; //위 아래 앞 뒤 왼 오
//윗면, 밑면 다 제일 위쪽이 0,0. (즉, 윗면은 뒷면과 가까운게, 밑면은 앞면과 가까운게)
char color[6] = {'w','y','r','o','g','b'};
char cp_side[3][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--){
        for (int i=0; i<6; i++){
            for (int j=0; j<3; j++){
                for (int k=0; k<3; k++)
                    cube[i][j][k] = color[i];
            }
        }
        int n; cin >> n;
        while(n--){
            char side, dir;
            char tmp[3];
            cin >> side >> dir;
            switch (side) {
                case 'U':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[0][i][j];
                        }
                    }
                    
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[2][0][i];
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[2][0][i] = cube[5][0][i];
                            cube[5][0][i] = cube[3][0][i];
                            cube[3][0][i] = cube[4][0][i];
                            cube[4][0][i] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[0][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[2][0][i] = cube[4][0][i];
                            cube[4][0][i] = cube[3][0][i];
                            cube[3][0][i] = cube[5][0][i];
                            cube[5][0][i] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[0][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;
                    
                case 'D':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[1][i][j];
                        }
                    }
                    
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[2][2][i];
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[2][2][i] = cube[4][2][i];
                            cube[4][2][i] = cube[3][2][i];
                            cube[3][2][i] = cube[5][2][i];
                            cube[5][2][i] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[1][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[2][2][i] = cube[5][2][i];
                            cube[5][2][i] = cube[3][2][i];
                            cube[3][2][i] = cube[4][2][i];
                            cube[4][2][i] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[1][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;
                    
                case 'F':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[2][i][j];
                        }
                    }
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[0][2][i];
                    
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[0][2][i] = cube[4][2-i][2];
                            cube[4][2-i][2] = cube[1][0][2-i];
                            cube[1][0][2-i] = cube[5][i][0];
                            cube[5][i][0] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[2][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[0][2][i] = cube[5][i][0];
                            cube[5][i][0] = cube[1][0][2-i];
                            cube[1][0][2-i] = cube[4][2-i][2];
                            cube[4][2-i][2] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[2][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;
                                        
                case 'B':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[3][i][j];
                        }
                    }
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[0][0][i]; //윗면의 (뒤랑가까운)윗부분
                    
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[0][0][i] = cube[5][i][2];
                            cube[5][i][2] = cube[1][2][2-i];
                            cube[1][2][2-i] = cube[4][2-i][0];
                            cube[4][2-i][0] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[3][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[0][0][i] = cube[4][2-i][0];
                            cube[4][2-i][0] = cube[1][2][2-i];
                            cube[1][2][2-i] = cube[5][i][2];
                            cube[5][i][2] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[3][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;
                    
                case 'L':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[4][i][j];
                        }
                    }
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[2][i][0]; //앞면
                    
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[2][i][0] = cube[0][i][0];
                            cube[0][i][0] = cube[3][2-i][2];
                            cube[3][2-i][2] = cube[1][i][0];
                            cube[1][i][0] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[4][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[2][i][0] = cube[1][i][0];
                            cube[1][i][0] = cube[3][2-i][2];
                            cube[3][2-i][2] = cube[0][i][0];
                            cube[0][i][0] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[4][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;                    
                case 'R':
                    for (int i=0; i<3; i++){
                        for (int j=0; j<3; j++){
                            cp_side[i][j] = cube[5][i][j];
                        }
                    }
                    for (int i=0; i<3; i++)
                        tmp[i] = cube[2][i][2]; //앞면
                    
                    if (dir == '+'){
                        for (int i=0; i<3; i++){
                            cube[2][i][2] = cube[1][i][2];
                            cube[1][i][2] = cube[3][2-i][0];
                            cube[3][2-i][0] = cube[0][i][2];
                            cube[0][i][2] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[5][i][j] = cp_side[2-j][i];
                        }
                    }
                    else{
                        for (int i=0; i<3; i++){
                            cube[2][i][2] = cube[0][i][2];
                            cube[0][i][2] = cube[3][2-i][0];
                            cube[3][2-i][0] = cube[1][i][2];
                            cube[1][i][2] = tmp[i];
                        }
                        for (int i=0; i<3; i++){
                            for (int j=0; j<3; j++)
                                cube[5][i][j] = cp_side[j][2-i];
                        }
                    }
                    break;
                    
                default:
                    break;
            }
        }
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++)
                cout << cube[0][i][j];
            cout << '\n';
        }
    }
    return 0;
}
