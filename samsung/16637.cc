#include <iostream>
#include <string>
#include <limits>
using namespace std;
int max_num = numeric_limits<int>::min();
int calculate(int a, char op, int b){
    switch (op)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;

    case '*':
        return a*b;
        break;

    default:
        cout << op;
        cout << "error\n";        
        break;
    }
}
void dfs(int* num, char* op, int idx, int now, int num_len){      //괄호 묶으면 바로 다음다음 숫자로
    if (idx >= num_len - 1){        //끝까지 다 본거
        if (idx == num_len-1)
            now = calculate(now,op[idx-1],num[idx]);
        if (max_num < now){
            max_num = now;                 
        }
        return;
    }
    
    else{   //괄호 시작, 또는 괄호 없기
        int new_now = calculate(num[idx], op[idx], num[idx+1]);     //괄호묶기
        new_now = calculate(now,op[idx-1],new_now);
        dfs(num,op,idx+2,new_now,num_len);
        new_now = calculate(now,op[idx-1],num[idx]);
        dfs(num,op,idx+1,new_now,num_len);        
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;    
    int* num = new int[n/2+1];
    char* op = new char[n/2];    
    for (int i=0; i<n; i++){
        if (i%2 == 0)  //숫자
            num[i/2] = s[i] - '0';
        else
            op[i/2] = s[i]; 
    }    
    dfs(num,op,1,num[0],n/2+1);
    cout << max_num;
    return 0;
}