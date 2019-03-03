/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    2. 输入两个整数，查找出重叠的部分，输出重叠的位数。
    示例
    输入:12345 56713
    输出:1
    输入:12345 23467
    输出:3
    输入:123 456
    输出:0
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
    map<char,int> m;
    string s;
    cin>>s;
    for(auto i:s){
        m[i]++;
    }
    int cnt = 0;
    cin>>s;
    for(auto i:s){
        if(m[i]){
            cnt++;
            m[i]--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}