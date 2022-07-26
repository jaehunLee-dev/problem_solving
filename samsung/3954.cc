#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int test_case; cin >> test_case;
    while (test_case--){
        int s_m, s_c, s_i;
        int ch_ptr = 0;
        cin >> s_m >> s_c >> s_i;
        int* num = new int[s_m]();
        char* input = new char[s_i];
        string cmd;        
        cin >> cmd; 
        stack<int> s;
        int* jump_ptr = new int[s_c](); 
        bool loop = false;       
        for (int i=0; i<s_c; i++){
            if (cmd[i] == '['){
                s.push(i);
            }
            if (cmd[i] == ']'){
                int tmp = s.top();
                s.pop();
                jump_ptr[tmp] = i+1;
                jump_ptr[i] = tmp+1;
            }
        }
        int ptr = 0;
        for (int i=0; i<s_i; i++)
            cin >> input[i];
        int cmd_ptr = 0;
        int cmd_cnt = 0;
        while (true) {            
            if (cmd_ptr == s_c){
                cout << "Terminates\n";
                break;
            }         
            if (cmd_cnt >=50000000){
                loop = true;                
                break;
            }
            cmd_cnt++;   
            switch (cmd[cmd_ptr])
            {
            case '-':
                num[ptr] = (num[ptr]-1);
                if (num[ptr] == -1)
                    num[ptr] = 255;
                cmd_ptr++;
                break;

            case '+':
                num[ptr] = (num[ptr]+1)%256;                
                cmd_ptr++;
                break;
            
            case '<':
                ptr=ptr-1;
                if (ptr == -1)
                    ptr = s_m-1;
                cmd_ptr++;
                break;
            
            case '>':
                ptr=ptr+1;
                if (ptr == s_m)
                    ptr = 0;
                cmd_ptr++;            
                break;

            case '[':            
                if (num[ptr] == 0)
                    cmd_ptr = jump_ptr[cmd_ptr];
                else cmd_ptr++;
                break;
            
            case ']':
                if (num[ptr] != 0)
                    cmd_ptr = jump_ptr[cmd_ptr];
                else cmd_ptr++;
                break;

            case '.':
                cmd_ptr++;
                break;
            
            case ',':
                if (s_i > ch_ptr)
                    num[ptr] = input[ch_ptr++];
                else num[ptr] = 255;
                cmd_ptr++;
                break;
            default:
                break;
            }
        }
        if (loop){
            int min_idx = s_c;
            int max_idx = 0;
            cmd_cnt = 0;
            while (true) {                                
                if (cmd_cnt >=50000000){                    
                    cout << "Loops " << min_idx-1 << ' ' << max_idx << "\n";
                    break;
                }
                cmd_cnt++;
                if (min_idx > cmd_ptr)
                    min_idx = cmd_ptr;
                if (max_idx < cmd_ptr)
                    max_idx = cmd_ptr;
                switch (cmd[cmd_ptr])
                {
                case '-':
                    num[ptr] = (num[ptr]-1);
                    if (num[ptr] == -1)
                        num[ptr] = 255;
                    cmd_ptr++;
                    break;

                case '+':
                    num[ptr] = (num[ptr]+1)%256;                
                    cmd_ptr++;
                    break;
                
                case '<':
                    ptr=ptr-1;
                    if (ptr == -1)
                        ptr = s_m-1;
                    cmd_ptr++;
                    break;
                
                case '>':
                    ptr=ptr+1;
                    if (ptr == s_m)
                        ptr = 0;
                    cmd_ptr++;            
                    break;

                case '[':            
                    if (num[ptr] == 0)
                        cmd_ptr = jump_ptr[cmd_ptr];
                    else cmd_ptr++;
                    break;
                
                case ']':
                    if (num[ptr] != 0)
                        cmd_ptr = jump_ptr[cmd_ptr];
                    else cmd_ptr++;
                    break;

                case '.':
                    cmd_ptr++;
                    break;
                
                case ',':
                    if (s_i > ch_ptr)
                        num[ptr] = input[ch_ptr++];
                    else num[ptr] = 255;
                    cmd_ptr++;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return 0;
}