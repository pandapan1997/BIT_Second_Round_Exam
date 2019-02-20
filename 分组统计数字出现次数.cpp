/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-20
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
        分组统计数字出现的次数。
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main(){
    map<int,map<int,int> > M; //map<int,int> 每个数字的计数 map<int,map<int,int> > 每个分组的计数
    set<int> S;//set用来保存 有哪些数字 去重
    vector<int> nums;
    int cnt =0;
    cin>>cnt;
    for(int i=0;i<cnt;++i){
        int temp;
        cin>>temp;
        nums.push_back(temp);
        S.insert(temp);
    }
    for(int i=0;i<cnt;++i){
        int tag;
        cin>>tag;
        M[tag][nums[i]]++;
    }
    for(map<int,map<int,int> >::iterator it =M.begin();it!=M.end();it++){
        cout<<it->first<<"={";
        bool tag =false;
        for(set<int>::iterator it_s =S.begin();it_s!=S.end();it_s++){
            if(tag) cout<<',';
            tag =true;
            cout<<*it_s<<"="<<it->second[*it_s];
        }
        cout<<"}"<<endl;
    }
    return 0;
}
/*
    输出结果如下
    7
    3 2 3 8 8 2 3
    1 2 3 2 1 3 1
    1={2=0,3=2,8=1}
    2={2=1,3=0,8=1}
    3={2=1,3=1,8=0}
*/
