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
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    vector<int> dp(a.length(),0);
    for(int i =0;i<a.length();++i){
        for(int j =a.length()-1;j>i;--j){
            string substr =a.substr(i,j);
            if(b.find(substr)!=-1){
                dp[i] = j;
                break;
            }
        }
    }
    int max = *max_element(dp.begin(),dp.end());
    cout<<max;
    return 0;
}