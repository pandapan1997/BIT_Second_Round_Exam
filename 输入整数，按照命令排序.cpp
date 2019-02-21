/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-21
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入一串整数，输入命令排序
    输入a num 将num 插入到末尾
    输入c num0 num1 用num1 替换num0
    输入d num 删除num
    输入s 排序
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> N;
    while(true){
        cout<<"a: 插入 c：替换 d：删除 s：排序 e:退出"<<endl;
        for(auto num:N) cout<<num<<" ";
        cout<<endl;
        char ch =getchar();
        if(ch=='e') break;
        else if(ch == 's') sort(N.begin(),N.end());
        else if(ch =='d') {
            cout<<"输入要删除的数组:  ";
            int getnum;
            cin>>getnum;
            for(vector<int>::iterator i =N.begin();i!=N.end();++i){
                if(*i==getnum) N.erase(i--);
            }
        }
        else if(ch=='c'){
            cout<<"输入要被替换的数和替换的数:  ";
            int targnum,repnum;
            cin>>targnum>>repnum;
            for(vector<int>::iterator i =N.begin();i!=N.end();++i){
                if(*i==targnum) *i=repnum;
            }
        }
        else if(ch=='a'){
            cout<<"输入要添加数:  ";
            int getnum;
            cin>>getnum;
            N.push_back(getnum);
        }
    }
    return 0;
}