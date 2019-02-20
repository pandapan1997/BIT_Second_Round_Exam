/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-20
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
        计算两个日期的时间差，以及给出一个时间加上 一个整数 之后的新的时间
*/
#include <iostream>
#include <vector>
using namespace std;
int M[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool judgeLeapYear(int y){//能被4 整除法且不能被100整除  或者能被400 整除
    return (y%4==0&&y%100!=0)||y%400==0;
}
struct Mydata{
    int year = 0,month =1,day =1;
    Mydata& operator+=(const int add){
        day+=add;
        while(true){
            int max =M[month];
            if(month==2&&judgeLeapYear(year)) max++;
            if(day>max){
                month++;
                day-=max;
                if(month>12){
                    month=1;
                    year++;
                }
            }else break;
        }
        return *this;
    }
};
long getTime(Mydata b){
    long ret =0;
    for(int i=0;i<b.year;++i){
        ret+=365;
        if(judgeLeapYear(i)) ret++;//闰年多加一天
    }
    for(int i=1;i<b.month;++i){
        ret+=M[i];
        if(judgeLeapYear(b.year)&&i==2) ret++;//闰年多加一天
    }
    ret+=b.day;
    return ret;
}
long getMinus(Mydata a,Mydata b){
    return abs(getTime(a)-getTime(b));
}
int main(){
    while(true){
        cout<<" 1. 计算差!    2.计算增加日期  3.退出"<<endl;
        char ch =getchar();
        if(ch =='1') {
            cout<<"输入两个日期 YY MM DD"<<endl;
            Mydata a,b;
            cin>>a.year>>a.month>>a.day;
            cin>>b.year>>b.month>>b.day;
            cout<<getTime(a)-getTime(b)<<endl;
        }
        else if(ch =='2'){
            cout<<"输入日期 YY MM DD 和 add"<<endl;
            Mydata a;
            int add =0;
            cin>>a.year>>a.month>>a.day>>add;
            a+=add;
            cout<<a.year<<" "<<a.month<<" "<<a.day<<endl;
        }
        else if(ch=='3') break;
    }
    return 0;
}