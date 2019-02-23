/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-22
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question: 
    输入一个字符串 例如 (aaa(bbb(ccc,ddd),eee(fff)))
    表示      aaa
            /    \
          bbb     eee
         /   \   /    
      ccc   ddd fff
    再输入一个请求，查询 例如fff  输出fff 的所有父节点
    输出： aaa>eee>fff

    思路：
        根据各处的字符串构造图 然后dfs 搜索。
*/
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <stack>
using namespace std;
bool dfs(int i,string &name);
struct edge{
    int v;
    edge* next;
};
struct vex{
    string name;
    edge* firstout;
};
vector<bool> vis;
vector<vex> G;
vector<int> R;
int main(){
    string str;
    cin>>str;
    str.erase(str.begin());//去掉头和尾的括号,在这里没有用。
    str.erase(str.begin()+str.length()-1);
    //creat map
    stack<int> s;
    string temp_name;
    for(int i=0;i<str.length();++i){
        if(str[i]=='('||str[i]==','||str[i]==')'){//temp_name的名字构建新的节点
            if(temp_name.size()==0) continue;
            vex temp_v ={temp_name,NULL};
            G.push_back(temp_v);// 新建立一个节点
            if(!s.empty()){
                edge *temp_e = new edge();
                temp_e->v =G.size()-1;
                temp_e->next =G[s.top()].firstout;
                G[s.top()].firstout =temp_e;//头插法 插入边链
            }
            if(str[i]=='(')                
                s.push(G.size()-1);//把新节点的编号入站
            else if(str[i]==')'){
                s.pop();
            }
            temp_name.clear();//清空temp_name 方便下一次的记录
        }
        else{
            temp_name.push_back(str[i]);//读取名字
        }
    }
    cout<<"图的信息如下:"<<endl;
    for(int i=0;i<G.size();i++){
        cout<<"编号:" <<i<<" "<< G[i].name<<"边：";
        edge* p =G[i].firstout;
        while(p){
            cout<<G[p->v].name<<" , ";
            p=p->next;
        }
        cout<<endl;
    }
    //dfs
    string query_name;
    cout<<"请输入要查询的节点的名字!"<<endl;
    cin>>query_name;
    vis.resize(G.size(),false);
    if(!dfs(0,query_name)) cout<<"没有找到！"<<endl;
    bool flag =false;
    for(int i=R.size()-1;i>=0;--i){
        if(flag) cout<<">"; flag =true;
        cout<<G[R[i]].name;
    }
}
bool dfs(int i,string &name){
    if(vis[i])return false;
    vis[i]=true;
    if(G[i].name==name) { R.push_back(i);return true;}
    edge *p =G[i].firstout;
    while(p){
        if(dfs(p->v,name)) {R.push_back(i);return true;}
        p=p->next;
    }
    return false;
}