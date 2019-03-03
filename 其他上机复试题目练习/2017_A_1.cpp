/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    1.用英文输入一个乘法表达式，表达式中只包含 1-9，编写程序，输出结果
    示例1
    输入:one * two * three 输出:6
    示例2
    输入:five * three * three 输出:45
    示例3 输入:four
    输出:4
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;
string table[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    unordered_map<string,int> m;
    for(int i=1;i<10;i++)//初始化 hash表
        m[table[i]]=i;
    string get_line,temp,modi_line;
    getline(cin,get_line);
    for(int i=0;i<get_line.length();++i){//去掉空格
        if(get_line[i]==' ') continue;
        modi_line.push_back(get_line[i]);
    }
    stringstream IS(modi_line);
    int res =1;
    while(getline(IS,temp,'*')){//按照'*' 换行读取字符串
        res*=m[temp];//计算
    }
    cout<<res<<endl;
    return 0;
}