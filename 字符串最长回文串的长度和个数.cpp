/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-28
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
            输入一个字符串，输出该字符串最长回文串的长度和个数（回文串：如果一个字符串中心对称就是回文串）
            注意：大小写不敏感
            AbcBa 5 1
            AbaB 3 2
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool judge(string &s,int l ,int h){
    while(l<=h){//判断回文串
        if(s[l++]!=s[h--])return false;
    }
    return true;
}
int main(){
    string str;
    cin>>str;
    for(int i =0;i<str.length();i++){//全部变成小写
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=('a'-'A');
    }
    int max_len =0,count=0;
    for(int i=0;i<str.length();++i){
        for(int j =str.length()-1;j>=i&&j-i>=max_len;j--){
            if(judge(str,i,j)){
                if(j-i==max_len) count++;
                else {
                    max_len =j-i;
                    count=1;
                }
            }           
        }
    }
    cout<<"长:"<<max_len+1<<" 总共"<<count<<endl;
    return 0;
}