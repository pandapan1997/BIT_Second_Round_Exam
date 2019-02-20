/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-20
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    统计一个英文句子中的所有单词 以及每个单词出现的次数  
    并且将单词按照出现的次数从高到底输出
    例如  i love BIT very mush, and i hold that BIT is the best College.
    BIT 2
    i 2
    and 1
    best 1
    hold 1
    College 1
    is 1
    love 1
    mush 1
    that 1
    the 1
    very 1
*/

#include<iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<string,int>&a,const pair<string,int>&b){
    return a.second>b.second;
}
int main(){
    string s,temp;
    getline(cin,s);
    map<string,int> M;
    for(int i=0;i<s.length();++i){
        if(s[i]==' '||s[i]==','||s[i]=='.'){
            if(temp.size()){//注意空的字符串不然会出现 空格也算一个字符串的情况
                M[temp]++;
                temp.clear();
            }
        }
        else temp.push_back(s[i]);
    }
    vector<std::pair<string,int> > V(M.begin(),M.end());//转存到vector 在排序
    sort(V.begin(),V.end(),cmp);
    for(vector<std::pair<string,int> >::iterator it =V.begin();it!=V.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}