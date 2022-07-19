//비트마스킹, 비트연산

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{	
        int N;
        cin >> N;
        int now = 0, cmp = 0, ans = 0;
        while(1){            
            now += N;
            cmp = now;
            while (cmp > 0){
                int tmp = cmp%10;
                cmp/=10;
                int i = 1 << tmp;
                ans = ans|i;
            }
            if (ans == 1023)
                break;            
        }
        cout << '#' << test_case << ' ' << now << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}