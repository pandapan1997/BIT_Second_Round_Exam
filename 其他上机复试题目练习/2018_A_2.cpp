/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    2. 定义移位操作，shift(str,x)代表将str中的前x位移到后面，
    例如shift(“abcd”,2) 得到 cdab。输入一个长度为 n 的字符串，
    最多可以进行 n 次移位操作，移位得到的字符串可能会与原字符串相同，
    输出发生相同的次数。
    输入:byebye
    输出:2
    输入:hello
    输出:1 
    老师实际测试样例: 
    输入:aAa
    输出:1
    输入:a
    输出:1 
    输入:byebyebye 
    输出:3
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string shift(string &s,int x){
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+s.length()-x);
    reverse(s.begin()+s.length()-x,s.end());
    return s;
}
int main(){
    string s,old;
    cin>>s;
    old =s;
    int cnt =0;
    for(int i=0;i<s.length();++i){
        s =shift(s,1);
        if(s==old) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}