/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    1. 将输入字符串中的不区分大小写的 select 子串和空格删除掉。 示例
    输入:Select * from emp 
    输出:*fromemp 
    输入:abSEseLEct leCTaNd ABC 
    输出:abaNdABC
*/
#include <iostream>
#include <string>   
using namespace std;
string comp ="select";
bool judge(char a,char b){
    return (a==b||abs(a-b)=='a'-'A');
}
bool Myerase(string &s){
    for(int i=5;i<s.length();++i){
        bool equ =true;
        for(int j=i;j>=i-5;j--){
            if(!judge(s[j],comp[j-i+5])) {
                equ= false;
                break;
            }
        }
        if(equ){//找到
            s.erase(s.begin()+i-5,s.begin()+i+1);
            return true;
        }
    }
    return false;
}
int main(){
    string line,modifed_str;
    getline(cin,line);
    for(auto i: line){
        if(i==' ') continue ;
        else modifed_str.push_back(i);
    }
    while(Myerase(modifed_str));
    cout<<modifed_str<<endl;    
    return 0;
}