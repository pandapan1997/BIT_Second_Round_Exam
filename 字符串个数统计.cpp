/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-22
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    输入一组单词，（区分大小写） 统计首字母相同的单词的个数，相同的单词不累加。
    最后输出 【首字母 统计个数】
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<char,int> Cnt;
    map<string,int> m;//记录某个单词是否出现过
    int word_cnt;
    cout<<"请输入 单词 的个数: "<<endl;
    cin>>word_cnt;
    while(word_cnt--){
        string temp;
        cin>>temp;
        if(m[temp]) continue;//如果是出想过的单词不统计
        m[temp]++;
        Cnt[temp[0]]++;
    }
    for(map<char,int>::iterator it =Cnt.begin();it!=Cnt.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}