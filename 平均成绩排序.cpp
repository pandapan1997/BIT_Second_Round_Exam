/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-27
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
            输入学生个数以及每个学生的姓名和3门课程成绩：输出不及格学生的信息；按平均成绩排序，从高到低输出学生信息。
输入示例：
5
zhaoyi 70 80 91
zhanger 68 40 90
zhangsan 60 70 80
lisi 70 80 90
wangwu 52 70 100

输出示例：
[0]name:zhaoyi score:70 80 91
[1]name:lisi score:70 80 90
[2]name:wangwu score:52 70 100
[3]name:zhangsan score:60 70 80
[4]name:zhanger score:68 40 90
*/
#include <iostream> 
#include <vector>   
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
struct node{
    string name;
    double avg;
    vector<int> scores;
    bool operator<(const node&b)const {
        return avg>b.avg;
    }
};
int main(){
    vector<node> V;
    int cnt;
    cout<<"输入学生信息条数";
    cin>>cnt;
    for(int i=0;i<cnt;++i){
        cout<<"请输入第"<<i<<"哥学生的信息";
        string temp_line;
        while(getline(cin,temp_line)&&temp_line.size()==0);
        istringstream IS(temp_line);
        node temp_node;
        IS>>temp_node.name;
        int sum =0,count =0,temp_num;
        while(IS>>temp_num){
            if(temp_num>100||temp_num<0) continue;
            sum+=temp_num;
            count++;
            temp_node.scores.push_back(temp_num);
        }
        temp_node.avg =sum*1.0/count;
        V.push_back(temp_node);
    }
    sort(V.begin(),V.end());
    for(int i=0;i<cnt;i++){
        cout<<"["<<i<<"]name:"<<V[i].name<<" score:";
        for(int j=0;j<V[i].scores.size();++j){
            if(j)cout<<" ";
            cout<<V[i].scores[j];
        }
        cout<<endl;
    }
    return 0;
}