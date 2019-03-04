/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-03-03
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    1.乒乓球比赛分为 11 分制和 21 分制，(得分达到了 11 分或 21 分为赢一局)下面输入比 赛的获胜情况，
    分别输出 11 分制和 21 分制的比赛结果
    其中输入数据中 W 代表甲得分，L 代表乙得分，E 代表输入结束，可以多行输入，并忽略 E 以后的内容
    例如:
    输入
    WWWWWWWWWWWWWWWW
    WWWWWWWWWLE
    输出
    11分制 第1局:11:0 第2局:11:0 第3局:3:1 21分制 第1局:21:0 第2局:4:1
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string match_info,temp;
    while(cin>>temp){
        match_info+=temp;
        if(temp.length()&&temp[temp.length()-1]=='E') break;
    }//11 分制
    match_info.erase(match_info.begin()+match_info.length()-1);//删除 E
    cout<<"11分制度:"<<endl;
    for(int i=0 ; i<match_info.length();){
        cout<<"第"<<((i)/11)+1<<"局:";
        int a = 0,b = 0, j;
        for(j = i; j<i+11&&j<match_info.length();j++){
            if(match_info[j]=='W') a++;
            else b++;
        }
        i = j;
        cout<<a<<" : "<<b<<endl;
    }
    cout<<"11分制度:"<<endl;
    for(int i=0 ; i<match_info.length();){
        cout<<"第"<<((i)/21)+1<<"局:";
        int a = 0,b = 0, j;
        for(j = i; j<i+21&&j<match_info.length();j++){
            if(match_info[j]=='W') a++;
            else b++;
        }
        i = j;
        cout<<a<<" : "<<b<<endl;
    }
    return 0;
}