/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-23
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入十个整数
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> rec(10,0);
    for(int i=0;i<rec.size();++i){
        cin>>rec[i];
    }
    sort(rec.begin(),rec.end());
    for(int i=0;i<rec.size();++i){
        if(i) cout<<" ";
        cout<<rec[i];
    }
    return 0;
}