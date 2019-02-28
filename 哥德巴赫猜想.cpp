/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-28
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
    给你两个整数n,m (6<=m<=n<=50)，
    首先把[m,n]区间所有偶数表示成两个素数之和，
    然后根据素数出现的个数有多到少依次输出素数及其出现次数
    当多个素数出现的次数相同的时候,优先输出较大的素数。 
    
    思路:
        先求出M内所有的素数存起来
        例如 14 = 3 + 11 7 + 7;
        我们只需要遍历 所有存下来的素数 , 看是否存在 14 -3 = 11 以及是否存在 14 -7 =7
        然后 在统计一下每个素数 出现的次数.
        最后输出.   
*/
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
using namespace std;

bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second!=b.second)  return a.second>b.second;
    else return a.first>b.first;
}

int main(){
    int m,n;
    map<int,set<pair<int,int> > > M; // 每个偶数 的可能出现的 素数对
    map<int,int> count;//统计 每个素数出现的次数
    map<int,int> prim;//存素数
    cin>>m>>n;
    for(int i =2;i<=n;i++){
        bool flag =true;
        for(int j=2;j<=sqrt(i);++j){
            if(i%j==0){ flag =false ;break;}
        }
        if(flag) 
            prim[i]++;//存到map中
    }
    for(int i= m;i<=n;i++){
        if(i%2==1) continue;
        //表示成两个数字的加法
        for(map<int,int>::iterator it =prim.begin();it!=prim.end();it++){
            int f =it->first,r =i-f;
            if(prim.count(r)){//存在 i = it->first + i-it->first
                if(r<f) swap(r,f);
                pair<int,int> t_pair(f,r);
                if(M[i].find(t_pair)==M[i].end()){//没有出现过
                    count[f]++;
                    count[r]++;
                    M[i].insert(t_pair);
                }
            }
        }
    }
    for(map<int,set<pair<int,int> > >::iterator it =M.begin();it!=M.end();it++){
        cout<<it->first<<" = ";
        for(set<pair<int,int> > ::iterator it_s =it->second.begin();it_s!=it->second.end();it_s++){
            cout<<it_s->first<<"+"<<it_s->second<<" / ";
        }
        cout<<endl;
    }
    //输出用到的素数 的是使用次数
    vector<pair<int,int> > V(count.begin(),count.end());
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();++i){
        cout<<"数字 "<<V[i].first<< " 次数: "<<V[i].second<<endl;
    }
    return 0;
}