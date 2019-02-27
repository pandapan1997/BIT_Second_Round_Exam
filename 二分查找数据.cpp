/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-27
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
            显示出如下数组中的所有元素，并使用二分查找法在数组中查找元素。
            int a[]={-90,-32,12,16,24,36,45,59,98,120};
            输入输出示例
            -90   -32   12   16   24   36   45   59   98   120
            请输入所要查找的元素：24
            输出：第5个元素为24，比较次数为1
            请输入所要查找的元素：120
            输出：第10个元素，比较次数为4
            请输入所要查找的元素：6
            输出：查找失败 比较次数为3
*/
#include <algorithm>
#include <iostream> 
using namespace std;
int a[10]={-90,-32,12,16,24,36,45,59,98,120};
int main(){
    int targ;
    cout<<"请输入要查询的值"<<endl;
    cin>>targ;
    int i=0,j =9,count= 0;
    while(i<=j){
        int m =(i+j)/2;
        count++;
        if(a[m]==targ){
            cout<<"第"<<m+1<<"个元素,比较次数为 "<<count<<endl;
            return 0;
        }
        else if(a[m]>targ) j= m-1;
        else i =m+1;
    }
    cout<<"查找失败"<<"比较次数为 "<<count<<endl;
    return 0;
}
