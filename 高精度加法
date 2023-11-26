#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	char a[10000],b[10000];
    long aa[10000],bb[10000],c[10001],B,A;
    for (int i = 0; i < 100; i++)
    {
        aa[i]=0;
        bb[i]=0;
        c[i]=0;
    }
    cin>>a>>b;
    A=strlen(a);
    B=strlen(b);
    if(B>A)
    {
        A=B;
    }
    for (int i = 0; i < strlen(a); i++)
    {
        aa[i]=a[strlen(a)-i-1]-'0';

    }
    for(int i=0;i<strlen(b);i++)
    {
        bb[i]=b[strlen(b)-i-1]-'0';
    }
    for(int i=0;i<=A;i++)
    {
        c[i]=aa[i]+bb[i]+c[i];
        if(c[i]>=10)
        {
            c[i]=c[i]%10;
            c[i+1]++;
        }
    }
    if(c[A]>0)
    {
        A++;
    }
    for(int i=A;i>0;i--)
    {
        cout<<c[i-1];
    }
    cout<<endl;
	return 0;
}
