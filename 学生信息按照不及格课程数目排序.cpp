/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-26
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入学生信息，姓名，成绩（多门成绩）
    输出每个学生的姓名 和平均成绩 ，并且按照不及格的成绩的数目 从大到小排序输出，
    以及输出不及格课程数目超过2 的学生信息。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
struct Student{
    string name;
    float avg;
    int course_faild_cnt;
    bool operator<(const Student& b) const {
        return course_faild_cnt>b.course_faild_cnt;
    }
};
int main(){
    vector<Student> V;
    cout<<"请输入学生信息 exit结束"<<endl;
    string temp_line;
    while(getline(cin,temp_line)&&temp_line.size()){
        stringstream IN(temp_line);
        Student t;
        IN>>t.name;
        t.course_faild_cnt =0;
        int sum =0,getnum,count =0;
        while(IN>>getnum) {
            sum+=getnum;
            if(getnum<60) t.course_faild_cnt++;
            count++;
        }
        t.avg = sum*1.0/count;
        V.push_back(t);
    }
    sort(V.begin(),V.end());
    for(auto i:V){
        cout<<i.name<<" "<<i.avg<<"不及格科目"<<i.course_faild_cnt<<endl;
    }
    cout<<"不及格科目大于2 的学生信息"<<endl;
    for(auto i:V){
        if(i.course_faild_cnt>=2)
            cout<<i.name<<" "<<i.avg<<"不及格科目"<<i.course_faild_cnt<<endl;
    }
    
    return 0;
}

