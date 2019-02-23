/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-23
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    学生有（学号：姓名：性别：年龄） 初始化三个学生的信息；
    例如: I12, rt, f, 67表示插入12, rt, f, 67
    D10表示删除学号为10的学生的信息
    每次操作完成以后输出所有学生的信息按学号从大到小排序
    输入: I12,rt,f,67
    输出(10, wes, f, 23)，(12,rt, f, 67), (20, ert, f, 45), (30, str, t, 89)
    输入: D10
    输出: (12,rt,f, 67), (20, ert, f, 45), (30, str, t, 89)
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
struct node{
    string name;
    char sex;
    int age;
};
map<int,node> m;

string s_init[3]={"10 wes f 23","20 ert f 45","30 str t 89"};
int main(){
    for(int i = 0; i < 3; i++){//初始化三个数据
        node temp;
        int t_id;
        char t_name[100];
        sscanf(s_init[i].c_str(),"%d %s %s %d",&t_id,t_name,&temp.sex,&temp.age);
        temp.name =string(t_name);
        m[t_id]=temp;
    }
    string s;
    while(cin>>s&&s!="exit"){
        if(s[0]=='D'){
            int d_id;
            sscanf(s.c_str(),"D%d",&d_id);
            if(m.count(d_id)){
                m.erase(m.find(d_id));
            }
        }
        else if(s[0]=='I'){
            node temp;
            int t_id;
            char t_name[100];
            replace(s.begin(),s.end(),',',' ');// 去掉空格方便输入
            sscanf(s.c_str(),"I%d %s %c %d",&t_id,t_name,&temp.sex,&temp.age);
            temp.name =string(t_name);
            m[t_id]=temp;
        }
        cout<<"当前库中有以下记录";
        for(map<int,node>::iterator it =m.begin();it!=m.end();++it){
            if(it!=m.begin()) cout<<" ";
            printf("(%d,%s,%c,%d)",it->first,it->second.name.c_str(),it->second.sex,it->second.age);
        }
        cout<<endl;
    }
    return 0;
}