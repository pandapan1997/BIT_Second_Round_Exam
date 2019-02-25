/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-25
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    求广义表的深度。
    例如输入(c,((d,e),f),h)
        输出 3；
*/
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    stack<int> s;
    cout<<"输入广义表"<<endl;
    cin>>str;
    int max_deep=0;
    for(int i =0;i<str.length();++i){
        if(str[i]=='('){
            s.push(i);
            max_deep = std::max(max_deep,int(s.size()));
        }
        else if(str[i]==')')s.pop();
    }
    return max_deep;
}
