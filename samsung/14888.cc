#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int N;
int* num;
int* op_num;
bool* visited;
int min_ans = INT_MAX;
int max_ans = INT_MIN;
vector<char> op;
void seq(int idx){     //총 N-1개 골라야함
    if (idx == N-1){
        int tmp_ans = num[0];
        for (int i=0; i<N-1; i++){
            int op_idx = op_num[i];
            char cur_op = op[op_idx];
            switch (cur_op)
            {
            case '+':
                tmp_ans = tmp_ans + num[i+1];
                break;
            case '-':
                tmp_ans = tmp_ans - num[i+1];
                break;
            case '*':
                tmp_ans = tmp_ans * num[i+1];
                break;
            case '/':
                tmp_ans = tmp_ans / num[i+1];
                break;
            default:
                break;
            }
        }
        if (tmp_ans > max_ans)
            max_ans = tmp_ans;
        if (tmp_ans < min_ans)
            min_ans = tmp_ans;
    }
    for (int i=0; i<N-1; i++){
        if (!visited[i]){
            visited[i] = true;
            op_num[idx] = i;
            seq(idx+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;
    num = new int[N]();
    op_num = new int[N-1]();
    visited = new bool[N-1]();
    for (int i=0; i<N; i++)
        cin >> num[i];
    char oprt[4] = {'+','-','*','/'};
    for (int i=0; i<4; i++){
        int tmp;
        cin >> tmp;
        while(tmp--){
            op.push_back(oprt[i]);
        }
    }
    seq(0);
    cout << max_ans << '\n' << min_ans;
    return 0;
}