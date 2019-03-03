/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    1. 输入一句英文，单词之间有一个空格，然后将句子反向输出。 示例
    输入:hello world
    输出:dlrow olleh
*/  
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string str;
    int flag = 0;
    vector<string> v;
    while(cin>>str){
        reverse(str.begin(),str.end());
        v.push_back(str);
    }
    for(auto i =v.rbegin();i!=v.rend();i++){
        if(flag) cout<<" ";
        flag =1;
        cout<<*i;
    }
    return 0;
}