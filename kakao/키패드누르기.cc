#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_idx = 10, r_idx = 12, l_dist = 0, r_dist =0;
    for (int i=0; i<numbers.size(); i++){
        if (numbers[i] == 0)
            numbers[i] = 11;
    }
    for (int i=0; i<numbers.size(); i++){
        l_dist = 0, r_dist = 0;
        int now = numbers[i];
        switch(now){
            case 1:
            case 4:
            case 7: 
                answer+="L";
                l_idx = now;
                break;
            case 3:
            case 6:
            case 9: 
                answer+="R";
                r_idx = now;
                break;
            default:
                int l_tmp = l_idx, r_tmp = r_idx;
                if(l_idx%3 == 1){      //왼손왼쪽에있는상태
                    l_dist++;
                    l_tmp++;
                }
                if(r_idx!=0 && r_idx%3 == 0){      //왼손왼쪽에있는상태
                    r_dist++;
                    r_tmp--;
                }
                l_dist+=abs(l_tmp-now)/3;
                r_dist+=abs(r_tmp-now)/3;
                if (l_dist<r_dist){
                    answer+="L";
                    l_idx = now;
                }
                else if (l_dist>r_dist){
                    answer+="R";
                    r_idx = now;
                }
                else{
                    if (hand == "right"){
                        answer+="R";
                        r_idx = now;
                    }
                    else{
                        answer+="L";
                        l_idx = now;
                    }
                }                        
                break;
        }
    }
    return answer;
}

int main(){
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string hand = "right";
    cout << solution(num,hand);
}