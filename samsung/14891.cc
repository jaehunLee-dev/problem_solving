#include <iostream>
using namespace std;
int main(){
    int gear[5][8];            
    int ptr[6];
    ptr[0] = 2;
    ptr[1] = 6;
    ptr[2] = 2;
    ptr[3] = 6;
    ptr[4] = 2;
    ptr[5] = 6;
    for (int i=1; i<=4; i++){
        for (int j=0; j<8; j++)
            scanf("%1d", &gear[i][j]);
    }    
    int K; cin >> K;
    bool rotate[5] = {false};
    int dir[5];
    for (int i=0; i<K; i++){
        int gear_num;
        for (int j=1; j<=4; j++)
            rotate[j] = false;
        cin >> gear_num >> dir[gear_num];        
        for (int j=0; j<3; j++){
            dir[(gear_num+j)%4+1] = dir[(gear_num+j-1)%4+1] * -1;
        }
        rotate[gear_num] = true;
        switch (gear_num)
        {
        case 1:
            if (gear[1][ptr[0]] != gear[2][ptr[1]]){
                rotate[2] = true;
                if (gear[2][ptr[2]] != gear[3][ptr[3]]){
                    rotate[3] = true;
                    if (gear[3][ptr[4]] != gear[4][ptr[5]]){
                        rotate[4] = true;
                    }
                }
            }
            break;
        
        case 2:
            if (gear[1][ptr[0]] != gear[2][ptr[1]])
                rotate[1] = true;
            if (gear[2][ptr[2]] != gear[3][ptr[3]]){
                rotate[3] = true;
                if (gear[3][ptr[4]] != gear[4][ptr[5]]){
                    rotate[4] = true;
                }
            }            
            break;

        case 3:
            if (gear[3][ptr[4]] != gear[4][ptr[5]])
                rotate[4] = true;
            if (gear[3][ptr[3]] != gear[2][ptr[2]]){
                rotate[2] = true;
                if (gear[2][ptr[1]] != gear[1][ptr[0]]){
                    rotate[1] = true;
                }
            }            
            break;

        case 4:
            if (gear[4][ptr[5]] != gear[3][ptr[4]]){
                rotate[3] = true;
                if (gear[2][ptr[2]] != gear[3][ptr[3]]){
                    rotate[2] = true;
                    if (gear[2][ptr[1]] != gear[1][ptr[0]]){
                        rotate[1] = true;
                    }
                }
            }
            break;

        default:
            break;
        }
        if (rotate[1]){
            if (dir[1] == 1){
                ptr[0] = ptr[0]-1;
                if (ptr[0] < 0)
                    ptr[0] = 7;                
            }
            else{
                ptr[0] = (ptr[0]+1)%8;
            }
        }
        if (rotate[2]){
            if (dir[2] == 1){
                ptr[1] = ptr[1]-1;
                if (ptr[1] < 0)
                    ptr[1] = 7;
                ptr[2] = ptr[2]-1;
                if (ptr[2] < 0)
                    ptr[2] = 7;
            }
            else{
                ptr[1] = (ptr[1]+1)%8;
                ptr[2] = (ptr[2]+1)%8;
            }
        }
        if (rotate[3]){
            if (dir[3] == 1){
                ptr[3] = ptr[3]-1;
                if (ptr[3] < 0)
                    ptr[3] = 7;
                ptr[4] = ptr[4]-1;
                if (ptr[4] < 0)
                    ptr[4] = 7;
            }
            else{
                ptr[3] = (ptr[3]+1)%8;
                ptr[4] = (ptr[4]+1)%8;
            }
        }
        if (rotate[4]){
            if (dir[4] == 1){
                ptr[5] = ptr[5]-1;
                if (ptr[5] < 0)
                    ptr[5] = 7;                
            }
            else{
                ptr[5] = (ptr[5]+1)%8;
            }
        }        
    }
    int ans = 0;
    int g_top = (ptr[0]+6)%8;
    if (gear[1][g_top]) 
        ans+=1;
    g_top = (ptr[2]+6)%8;
    if (gear[2][g_top])
        ans+=2;
    g_top = (ptr[4]+6)%8;
    if (gear[3][g_top])
        ans+=4;
    g_top = (ptr[5]+2)%8;
    if (gear[4][g_top])
        ans+=8;    
    cout << ans;
    return 0;
}