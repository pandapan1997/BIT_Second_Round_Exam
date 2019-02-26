/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-26
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
   输入字符串，输出字符串中包含的数字，比如 2.3ABC0-2.3  输出 2.3 0 -2.3。
    注意一些特殊的情况如+004.500值为+4.5。
    输入 dsfa3.14-2.5+60dsaf4dsaf5923.122139fdsa000001
    输出 3.14 -2.5 60 4 5923.122139 1 

    思路  + 字母以及其他符号 都可以省略，除了. 为了防止 出现表达式这种我们在每个‘-’ \
    前面都加上一个空格。这样就能保证 每次读取的数字都是正确的。
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string getstr;
    cin>>getstr;
    for(int i=0;i<getstr.length();++i){
        if(getstr[i]=='-') getstr.insert(i++," ");
        else if((getstr[i]<'0'||getstr[i]>'9')&&getstr[i]!='.'){
            getstr[i]=' ';
        }
    }
    stringstream IS(getstr);
    cout.precision(10);
    double num;
    while(IS>>num){
        cout<<num<<" ";
    }
    return 0;
}
