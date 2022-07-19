#include<iostream>
using namespace std;

int len;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{        
        string s;
        cin >> s;
        len = s.length();
        long long ans = 0;
        for (long long i=1; i<(1<<(4*len)); i++){     //0000....001 ~ 1111....111
            long long now = i;
            long long prv = 1; //처음 열쇠 : A (0001)
            bool fail = false;            
            for (int j=0; j<len; j++){
                long long tmp = (now & 15);   //16으로 나눈 나머지 (현재 수열)                
                if (!tmp){       //0000인 경우 -> 적어도 한명은 참여해야해서 break
                    fail = true;                    
                    break;
                }
                long long mv = 1 << (s[j] - 'A'); //A: 0001, B: 0010, C: 0100, D: 1000                
                if (!(tmp & mv)){      //현재 책임자 포함 안돼서 break
                    fail = true;
                    break;         
                }       
                if (!(tmp & prv)){ //이전 참가자와 아무도 안겹쳐서 (열쇠없음) break
                    fail = true;                    
                    break;
                }
                now = now >> 4;     //16으로 나누기
                prv = tmp;  //현재 수열 prv(이전 수열)로 설정                
            }            
            if (!fail)                
                ans++;            

            if (ans == 1000000007)
                ans = 0;
        }
        cout << '#' << test_case << ' ' << ans << '\n';
	}    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}