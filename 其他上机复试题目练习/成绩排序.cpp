/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-01
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    题目描述
    查找和排序
    题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
    都按先录入排列在前的规则处理。
    示例：
    jack      70
    peter     96
    Tom       70
    smith     67
    从高到低  成绩 
    peter     96 
    jack      70 
    Tom       70 
    smith     67
    从低到高
    smith     67
    jack      70 
    Tom      70 
    peter     96
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node{
    string name;
    int sco;
    int idx;
};
bool cmp1(const node& a,const node& b){// 降序
        if(a.sco!=b.sco) return a.sco>b.sco;
        else return a.idx<b.idx;
}
bool cmp(const node& a,const node& b){// 升序
        if(a.sco!=b.sco) return a.sco<b.sco;
        else return a.idx<b.idx;
}
int main(){
    vector<node> v;
    int cnt,sort_flag;
    while(cin>>cnt>>sort_flag){
        for(int i =0;i<cnt;i++){
            node newnode;
            cin>>newnode.name>>newnode.sco;
            newnode.idx =i;
            v.push_back(newnode);
        }
        if(sort_flag) sort(v.begin(),v.end(),cmp);
        else sort(v.begin(),v.end(),cmp1);
        for(int i=0;i<v.size();i++){
            cout<<v[i].name<<" "<<v[i].sco<<endl;
        }
    }
    return 0;
}