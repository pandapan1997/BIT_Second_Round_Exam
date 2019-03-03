/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
   1. 输入一串整数，用逗号隔开。如果有重复的数字就输出最靠后的一个，没有 重复的就输出-1.
   输入:1,2,3,4,3,2,1
   输出:1
   输入:1,2,3,4,5,6,7
   输出:-1
   老师实际测试样例:
   输入:0
   输出:-1
   输入:1,0
   输出:-1
   输入:0,1,0,1
   输出:1
*/
#include <iostream>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;
int main(){
   cout<<"请输入";
   int num,flag = 0;
   char nope;
   map<int,int> m;
   string temp_line;
   getline(cin,temp_line);
   for(int i=0;i<temp_line.length();i++){
      if(temp_line[i]==',') temp_line[i] =' ';
   }
   stringstream IS(temp_line);
   while(IS>>num){
      if(flag==0&&m[num]++){
         flag =1;
      }
   }
   if(flag==0) cout<<"-1"<<endl;
   else cout<<num<<endl;
   return 0;
}
