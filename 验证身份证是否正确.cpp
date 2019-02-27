/*
   Name: 北京理工大学复试上机历年题目
   Date: 2019-02-27
   Author: Sologala
   GitHub: https://github.com/Sologala
   Question:
            1、输入身份证号，通过计算比较校验位来判断身份证号是否正确。
            如，aaaaaayyyymmddxxsp共18位，其中：
            年份代码yyyy共4位。最后一位p为校验位。
            校验规则是：
            （1）对前17位数字的权求和 S=Sum(Ai*Wi)，i=0,...,16
            Ai：表示第i位置上的身份证号码数字值
            Wi：表示第i位置上的加权因子
            Wi：7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2
            （2）计算模 Y=mod(S,11)
            （3）通过模得到对应的校验码
                Y：0 1 2 3 4 5 6 7 8 9 10
                校验码：1 0 X 9 8 7 6 5 4 3 2
                例如，如果得到Y为9则最后的校验位p应该为3
                如果校验位不是3，则该身份证号码不正确。
                输入示例：
                110130197606175317
                输出示例：
                110130197606175317 正确.
                输入示例：
                110200197501175220
                输出示例：
                应为：11020019750117522X
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
int W[17]={7 ,9 ,10 ,5, 8, 4 ,2 ,1 ,6, 3, 7 ,9 ,10, 5 ,8, 4, 2};
char chk[11] ={'1','0', 'X','9','8', '7', '6', '5', '4', '3', '2'};
int main(){
    string str;
    cin>>str;
    int sum =0;
    for(int i=0;i<17;i++){
        sum+=(str[i]-'0')*W[i];
    }
    if(str[17]==chk[sum%11]){
        cout<<str<<" "<<"正确！"<<endl;
    }
    else {
        str[17]=chk[sum%11];
        cout<<"应为："<<str<<endl;
    }
    return 0;
}