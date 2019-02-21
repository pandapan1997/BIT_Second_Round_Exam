/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-21
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入中追表达式，转化成后缀表达式，并且求值；(注意 数字应当为一位数字)
    例如：3+(5-2)*5
    输出  352-5*+
    res_val: 18
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
char sig[7]={'#','(','*','/','+','-',')'};
int  arr_isp[7]={0,1,5,5,3,3,6};
int  arr_icp[7]={0,6,4,4,2,2,1};
int main(){
    unordered_map<char,int> isp,icp;
    for(int i=0;i<7;++i){ isp[sig[i]]=arr_isp[i];icp[sig[i]]=arr_icp[i];}
    string exp,post_exp;
    stack<char> s;
    s.push('#');
    cout<<"清输入中追表达式"<<endl;
    cin>>exp;
    for(int i=0;i<exp.length();++i){
        if(exp[i]>='0'&&exp[i]<='9') post_exp.push_back(exp[i]);
        else if(icp[exp[i]]>isp[s.top()]){//是符号
            s.push(exp[i]);
        }
        else{//出战
            while(icp[exp[i]]<=isp[s.top()]){
                char top =s.top();s.pop();
                if(top=='(')break;
                post_exp.push_back(top);
            }
            if(exp[i]!=')')s.push(exp[i]);
        }
    }
    while(s.size()>1){
        post_exp.push_back(s.top());s.pop();
    }
    cout<<"后缀表达式："<<post_exp<<endl;
    //计算后缀表达式
    stack<float> cal_s;
    for(int i=0;i<post_exp.length();++i){
        if(post_exp[i]>='0'&&post_exp[i]<='9') cal_s.push(post_exp[i]-'0');
        else if(isp[post_exp[i]]){
            int num1 =cal_s.top();cal_s.pop();
            int num2 =cal_s.top();cal_s.pop();
            if(post_exp[i]=='+'){
                cal_s.push(num2+num1);
            }
            else if(post_exp[i]=='-'){
                cal_s.push(num2-num1);
            }
            else if(post_exp[i]=='*'){
                cal_s.push(num2*num1);
            }
            else if(post_exp[i]=='/'){
                cal_s.push(num2*1.0/num1);
            }
        }
    }
    cout<<"val:"<<cal_s.top();
    return 0;
}