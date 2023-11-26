#include<iostream>
#include<cstring>
using namespace std;
int a[2005],b[2005],c[4010];
int len1,len2,len;
char s1[2005],s2[2005];
long int m;
int main(){
    cin>>s1;   //输入乘数1  
    len1=strlen(s1);    //获取乘数1的长度
    for (int i=0;i<len1;i++)     //
    {                            //将字符形式存在的乘数1转化成数组
      a[i]=s1[len1-i-1]-'0';     //
    }                            //
    cin>>s2;   //输入乘数2
    len2=strlen(s2);    //获取乘数2的长度
    for (int i=0;i<len2;i++)   //
    {                          //
    	b[i]=s2[len2-i-1]-'0'; //将字符形式存在的乘数2转化成数组
    }                          //
    for (int i=0;i<len1;i++)
    {
    	for (int j=0;j<len2;j++)
        {
            c[i+j]=c[i+j]+a[i]*b[j];
        } 	
    }
    len=len1+len2;
    for (int i=0;i<len;i++)
    {
        c[i+1]=c[i+1]+c[i]/10;
        c[i]=c[i]%10;
    }      
    while (c[len]==0)
    {
      len--;    
    }
    for (int i=len;i>=0;i--)
    {
       cout<<c[i];
    }
    return 0;
}
