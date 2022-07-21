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

    Student tmp{ mId,mGrade,gen,mScore };
    v.push_back(tmp);
    int max_score = -1, max_id = 0;
    for (auto& i : v) {
        if (i.grade == mGrade && i.gender == gen) {
            if (i.score > max_score) {
                max_score = i.score;
                max_id = i.id;
            }
            else if (i.score == max_score) {
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
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (iter->id == mId) {
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
    for (auto& i : v) {
        if (i.grade == r_grade && i.gender == r_gender) {
            if (i.score < min_score) {
                min_score = i.score;
                min_id = i.id;
            }
            else if (i.score == min_score) {
                if (i.id < min_id)
                    min_id = i.id;
            }
        }
    }
    return min_id;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    int rtn_score = 300001, rtn_id = 0;
    bool exist = false;
    for (auto& itr : v) {
        //printf("score: %d,", itr.score);
        //if (itr.gender) printf(" male\n");
        //else printf(" female\n");
        bool in_group = false;
        for (int i = 0; i < mGradeCnt; i++) {
            if (itr.grade == mGrade[i]) {       //같은 학년 그룹
                //printf("same grade!\n");
                for (int j = 0; j < mGenderCnt; j++) {
                    bool tmp_gender = true;
                    if (mGender[j][0] == 'f')
                        tmp_gender = false;
                    if (itr.gender == tmp_gender) {     //같은 성별 그룹
                        //printf("same gender!\n");
                        in_group = true;        //같은 학년, 그룹 확인 -> break
                        break;
                    }
                }
                if (in_group)
                    break;
            }
        }
        if (in_group) {
            //printf("find!\n");
            if (itr.score >= mScore && itr.score < rtn_score) {
                rtn_score = itr.score;
                rtn_id = itr.id;
                exist = true;
            }
            else if (itr.score >= mScore && itr.score == rtn_score) {
                if (rtn_id > itr.id) {
                    rtn_id = itr.id;
                }
            }
        }        
    }
    if (!exist) {
        //printf("id: %d, score: %d\n", rtn_id, rtn_score);
        return 0;
    }
    //printf("id: %d, score: %d\n", rtn_id, rtn_score);
    return rtn_id;
}