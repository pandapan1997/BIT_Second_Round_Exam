/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-25
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:    
   输出最近打开的文件的记录 用数字来表示文件的记录
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
     set<int> s;
    int Q[4]={-1,-1,-1,-1},f =0,r=0,getnum;
    while(cin>>getnum&&getnum!=-1){
        if(s.find(getnum)==s.end()){
            if((f+1)%4==r) {
                s.erase(s.find(Q[r]));
                r = (r + 1)%4;
            }
            Q[f]=getnum;
            s.insert(getnum);
            f= (f+1)%4;
        }
        else{
            vector<int> t;
            while(f!=r){
                if(Q[r]!=getnum)
                    t.push_back(Q[r]);
                r=(r+1)%4;
            }
            for(auto i: t){
                Q[f]=i;
                f=(f+1)%4;
            }
            Q[f]=getnum;
            f= (f+1)%4;
        }
        for(int i = f;i!=r;i=(i-1+4)%4){
            cout<<Q[(i-1+4)%4]<<" ";
        }
        cout<<endl;
    }
    return 0;
}