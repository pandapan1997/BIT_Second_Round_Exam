/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    2. 打印拆线字符串，呈现 W 型。输入字符串及要输出的行数。 示例1
    输入:apple 2 
    输出:a  p  e
          p  l  
    示例2
    输入:appleorange 3 
    输出:a    e     n
         p  l  o  a  g 
          p     r     e
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string str;
    int row,i =0;
    cin>>str>>row;
    vector<vector<char> > rec(row,vector<char>(str.length(),' '));
    int x =0,y =0;
    while(i<str.length()){
        while(i<str.length()&&x<row){
            rec[x++][y++] =str[i++];
        }
        x =row-2;
        while(i<str.length()&&x>=0){
            rec[x--][y++] =str[i++];
        }
        x =1;
    }
    for(auto i: rec){//输出
        for(auto j: i){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}