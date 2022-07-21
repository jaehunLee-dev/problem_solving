#include<iostream>
#include <stdio.h>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T = 10;
    int tmp;
    int x,y;
    //freopen("input.txt", "r", stdin);	   
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        list<int> ls;        
        for (int i=0; i<N; i++){
            cin >> tmp;
            ls.push_back(tmp);
        }            
        int M;
        cin >> M;
        for (int i=0; i<M; i++){
            char cmd;
            cin >> cmd;
            switch (cmd)
            {
            case 'I': {      //insert                
                cin >> x >> y;
                list<int>::iterator iter = ls.begin();                
                while (x--)
                    iter++;
                for (int i=0; i<y; i++){
                    cin >> tmp;
                    ls.insert(iter,tmp);                    
                }
                break;
            }
            case 'D':{
                cin >> x >> y;
                list<int>::iterator iter = ls.begin();
                while (x--)
                    iter++;

                while(y--)
                    iter = ls.erase(iter);
                break;
            }
            case 'A':{
                cin >> y;
                while(y--){
                    cin >> tmp;
                    ls.push_back(tmp);
                }
                break;
            }
            default:{
                break;
            }
            }
        }        
        cout << '#' << test_case << ' ';
        int print_num = 0;
        for (auto& i:ls){
            cout << i << ' ';
            print_num++;
            if (print_num == 10)
                break;
        }
        cout << '\n';
	}
	return 0;
}