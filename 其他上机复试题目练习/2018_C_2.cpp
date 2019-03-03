/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    2. 什么是最长上升子序列? 
    就是在一个序列中求出一段不断严格上升的部分，
    它不一定要连续。
    比如:2,3,4,7 和 2,3,4,6 
    就是序列 2 5 3 4 1 7 6 的两种选取方案，
    最长的长度是 4。
    输入一个序列，输出最大上升子序列的长度。
    输入:1 3 2 5 6 4 9 (最大上升子序列为13569 或 12569) 输出:5
    输入:1 2 3 4 5 6 7
    输出:7
    输入:7 6 5 4 3 2 1 输出:1
*/
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    vector<int> rec,dp;
    int get;
    string line;
    getline(cin,line);
    stringstream IS(line);
    while(IS>>get){
        rec.push_back(get);
    }
    dp.resize(rec.size(),0);
    dp[0]=1; 
    for(int i=1;i<rec.size();i++)  
    {  
        dp[i]=1;
        for(int j=0;j<i;j++)  
            if(rec[i]>rec[j]) 
                dp[i]=max(dp[i],dp[j]+1);
    }  
    int max_len =0;
    for(auto i:dp) 
        max_len =max(max_len,i);
    cout<<max_len<<endl;    
    return 0;
}