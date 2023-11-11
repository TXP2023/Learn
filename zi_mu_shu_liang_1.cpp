#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    char a[100],esl[26],x;
    long long sl[26],i,ti,j;
    for ( i = 0; i < 26; i++)
    {
        esl[i]=i+'a';
        sl[i]=0;
    }
    cin>>a;
    for(i=0;i<strlen(a);i++)
    {
        sl[a[i]-'a']++;
    } 
    for(i=0;i<26;i++)
    {
        for(ti=0;ti<25-i;ti++)
        {
            if(sl[ti]<sl[ti+1])
            {
                {
                    j=sl[ti];
                    sl[ti]=sl[ti+1];
                    sl[ti+1]=j;
                }
                {
                    x=esl[ti];
                    esl[ti]=esl[ti+1];
                    esl[ti+1]=x;
                }
            }
        }
    }
    for(i=0;i<26;i++)
    {
        if(sl[i]>0)
        {
            cout<<esl[i]<<" "<<sl[i]<<endl;
        }
    }
    return 0;
}
