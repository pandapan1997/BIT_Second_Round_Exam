/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-22
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入一组 单词 （区分大小写） 输出这些单词的字典许排序。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<string> v;
    int cnt;
    cout<<"请输入单词的个数"<<endl;
    cin>>cnt;
    v.resize(cnt);
    for(int i=0;i<v.size();++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cout<<"排序结果如下:"<<endl;
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    return 0;
}
