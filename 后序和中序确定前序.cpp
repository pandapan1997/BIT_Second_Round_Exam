/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-24
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
   通过二叉树的后序序列 与中序序列 确定前序的序列

*/
#include <iostream>
#include <string>
using namespace std;
string calPre(string Post,string In){
    string ret;
    if(Post.length()==0) return ret;
    int i=0;
    for(;i<In.length()&&In[i]!=Post[Post.length()-1];++i);
    ret.push_back(Post[Post.size()-1]);
    string s(In.begin()+i+1,In.end());
    return ret+//根节点
           calPre( //左边
               string(Post.begin(),Post.begin()+i),
               string(In.begin(),In.begin()+i)
                ) +
           calPre(//右边
               string(Post.begin()+i,Post.begin()+Post.length()-1),
               string(In.begin()+i+1,In.end())
               );
}
int main(){ 
    string post,in;
    cout<<"请输入后续和中序的序列"<<endl;
    cin>>post>>in;
    cout<<calPre(post,in)<<endl;
    return 0;
}