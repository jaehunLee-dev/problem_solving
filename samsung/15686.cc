#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<pair<int,int>> house;        //집의 주소 저장
vector<pair<int,int>> ch_house;     //치킨집의 주소 저장
int N, M;
bool* select;
int** city;
int chicken;    //현재 치킨 갯수
int ans = INT_MAX;
void comb(int idx, int total){
    if (total == M){        //치킨집 선택 완료        
        vector<pair<int,int>> tmp;
        for (int i=0; i<chicken; i++){
            if (select[i]){
                tmp.push_back(ch_house[i]);
            }                
        }        
        //tmp의 치킨집 주소로 거리 계산
        int tmp_ans = 0;
        for (int i=0; i<house.size(); i++){
            int min = INT_MAX;
            for (int j=0; j<tmp.size(); j++){
                int dist = abs(house[i].first - tmp[j].first) + abs(house[i].second - tmp[j].second);
                if (dist < min)
                    min = dist;
            }
            tmp_ans+=min;
        }
        if (tmp_ans < ans)
            ans = tmp_ans;
        return;
    }    
    if (idx == chicken)
        return;
    select[idx] = true;
    comb(idx+1,total+1);
    select[idx] = false;
    comb(idx+1,total);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    city = new int*[N+1];    
    for (int i=1; i<=N; i++)
        city[i] = new int[N+1];
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> city[i][j];      //1: 집, 2: 치킨집
            if (city[i][j] == 1)
                house.push_back(make_pair(i,j));
            else if (city[i][j] == 2){
                chicken++;
                ch_house.push_back(make_pair(i,j));
            }
        }
    }    
    select = new bool[chicken]();
    comb(0,0);
    cout << ans;
    return 0;
}