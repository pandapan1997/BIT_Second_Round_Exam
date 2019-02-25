/*
   Name: 北京理工大学复试上机历年题目
   Author: Sologala
   GitHub: https://github.com/Sologala
   Date: 2019-02-24
   Question:
    给出一个表达式 输出相应二叉树的 先序遍历结果
    输入 a+b*(c-d)-e/f
    输出 -+a*b-cd/ef
*/
#include<iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;
char sig[7] ={'#',')','*','/','+','-','('};
int isp_val[7] ={-1,0,2,2,1,1,0};
int icp_val[7] ={-1,3,2,2,1,1,0};
int main(){
    map<char,int> isp,icp;
    for(int i=0;i<7;i++){
        isp[sig[i]]=isp_val[i];
        icp[sig[i]]=icp_val[i];
    }
    cout<<"请输入中序的表达式！"<<endl;
    string In,Pre;
    cin>>In;
    stack<char> s;
    s.push('#');
    for(int i=In.length()-1;i>=0;--i){
        if(isp.count(In[i])){//是符号
            while(icp[In[i]]<isp[s.top()]){
                if(s.top()!=')') Pre.push_back(s.top());
                s.pop();
            }
            if(In[i]!='(') s.push(In[i]);
        }
        else Pre.push_back(In[i]);
    }
    while(s.top()!='#'){
        if(s.top()!=')') Pre.push_back(s.top());
        s.pop();
    }
    reverse(Pre.begin(),Pre.end());
    cout<<"前序表达式："<<Pre<<endl;
    return 0;
}