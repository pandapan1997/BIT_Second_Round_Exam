/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-04
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    2.在公司中，存在着领导-员工关系，一个领导可以有多个员工，
    一个员工只能有一个领导。 用 {员工, 领导}, {员工, 领导}, {员工, 领导}, {员工, 领导}..... 
    这样的格式录入数据，输 出公司的管理关系，其中{员工, 领导}用编号表示
    例如输入
    {21, 13}, {32, 13}, {24, 14}, {28, 14}, {13, 11}, {14, 11}
    输出
    {11, [{13, [{21}, {32}]}, {14, [{24}, {28}]}]}
    注:其中 xx, [{aa},{bb}]表示，xx 的员工有 
    aa，bb {},{}...之间是同级员工关系，要按照编号从小到大排列。
*/
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const string true_res ="{11, [{13, [{21}, {32}]}, {14, [{24}, {28}]}]}";
void show( map<int,set<int> >& m,int id){
    cout<<"{"<<id;
    if(m[id].size()){
        cout<<", [";
        int flag =0;
        for(set<int>::iterator it =m[id].begin(); it!= m[id].end();it++){
            if(flag) cout<<", ";
            flag =1;
            show(m,*it);
        }
        cout<<"]";
    }
    cout<<"}";
}
int main(){
    map<int,set<int> > m;
    map<int,int> leader;
    int a, b;
    while(scanf("{%d, %d}, ",&a,&b)){
        m[b].insert(a);//员工集
        leader[a] =b;//领导集 
    }
    set<int> highest_leader;//找到多个 最高领导 并且存下来
    for(map<int,int>::iterator it = leader.begin();it!=leader.end(); it++){
        int cur  =it->second;
        while(leader[cur]!=0){
            cur =leader[cur];
        }
        if(cur) highest_leader.insert(cur);
    }
    for(set<int>::iterator it =highest_leader.begin() ; it!=highest_leader.end() ;it++){
        show(m,*it);
    }
    cout<<endl;
    cout<<true_res<<endl;//比对
    return 0;    
}
