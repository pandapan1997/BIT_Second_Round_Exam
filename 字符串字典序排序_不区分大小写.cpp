/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-24
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    字符串排序  不区分大小写
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp( string a, string b){// 懒得重写字符串比较函数了。
    for(int i=0;i<a.length();++i)
            if(a[i]>='A'&&a[i]<='Z') a[i]+=('a'-'A');
    for(int i=0;i<b.length();++i)
            if(b[i]>='A'&&b[i]<='Z') b[i]+=('a'-'A');
    return a<b;
}
int main(){
    vector<string> v;
    string temp;
    while(cin>>temp&&temp!="exit"){
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();++i){
        if(i) cout<<" ";
        cout<<v[i];
    }
    return 0;
}