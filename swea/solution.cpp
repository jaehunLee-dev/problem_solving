#include <vector>
using namespace std;
struct Student
{
    int id;
    int grade;
    bool gender;        //true:male, false:female
    int score;
};

vector<Student> v;

void init() {
    v.clear();
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    bool gen = false;      
    if (mGender[0] == 'm')
        gen = true;    
    
    struct tmp{mId,mGrade,gen,mScore};
    v.push_back(tmp);
    int max_score = -1, max_id = 0;
    for (auto& i:v){
        if (i.grade == mGrade && i.gender == gen){
            if (i.score>max_score){
                max_score = i.score;
                max_id = i.id;
            }
            else if (i.score == max_score){
                if (i.id > max_id)
                    max_id = i.id;
            }
        }
    }
	return max_id;
}

int remove(int mId) {
    bool exist = false;
    int r_grade = 0;
    bool r_gender = false;
    for(auto iter = v.begin(); iter != v.end(); iter++){
        if (iter->id == id){
            r_grade = iter->grade;
            r_gender = iter->gender;
            iter = v.erase(iter);
            exist = true;            
            break;
        }            
    }
    if (!exist)
        return 0;
    int min_score = 300001, min_id = 0;
    for (auto& i: v){
        if (i.grade == r_grade && i.gender == r_gender){
            if (i.score < min_score){
                min_score = i.score;
                min_id = i.id;            
            }
            else if (i.score == min_score){
                if (i.id < min_id)
                    min_id = i.id;
            }
        }        
    }
    return min_id;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	return 0;
}