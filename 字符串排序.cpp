/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-20
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入字符串，最多4个字符串，要求最后输入的字符串排在前面;
    第一小问 输出到屏幕
    第二小问 输出到文件
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    vector<string> Q(5,"");
    int f =0,r=0;   //构造循环队列
    string temp;
    while(cin>>temp&&temp!="#"){
        Q[f]=temp;
        f=(f+1)%5;
        if(f==r)r=(r+1)%5;
        for(int i=f,count=0;i!=r;i=(i-1+5)%5){
            if(count) cout<<" ";
            cout<<1+count++<<"="<<Q[(i-1+5)%5];
        }
        cout<<endl;
    }
    string path ="./Bin/res.txt";
    ofstream os(path,os.out);
    for(int i=f,count=0;i!=r;i=(i-1+5)%5){
            if(count) os<<" ";
            os<<1+count++<<"="<<Q[(i-1+5)%5];
        }
    os<<endl;
    os.close();
    return 0;
}