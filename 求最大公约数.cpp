/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-24
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    求两个数的最大公约数
    例如： 输入  : 24 18 
          输出  ：6
*/
#include <iostream>
using namespace std;
int main(){
    int a,b=INT_MAX-1;
    cin>>a;
    int min_val = min(a,b),max_val =0;
    for(int i=min_val;i>=1;--i){
        if(a%i==0&&b%i==0) max_val =max(max_val,i);
    }
    cout<<"最大公约数："<<max_val<<endl;
    return 0;
}