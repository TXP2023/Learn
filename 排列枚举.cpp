#include<bits/stdc++.h>
using namespace std;
vector<bool> b;
vector<int> c;
int m=3;
int64_t l=0;
void f(int n)
{

    if(n==m+1){
        for (int i = 0; i < m; i++)
        {
            printf("%d",c[i]);
            cout<<"  ";
        }
        cout<<endl;
        l++;
        return;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            if(b[i]==false)
            {
                b[i]=true;
                c[n-1]=i+1;
                f(n+1);
            }
        }
        if(n>1)
            for (int i = n-2; i < m; i++)
                b[c[i]-1]=false;
        return;
    }
}
int main()
{
    scanf("%d",&m);
    c.resize(m);
    b.resize(m);
    clock_t start,end;
    start = clock();
    f(1);
    end = clock();
    cout<<"Number of programs:"<<l<<endl;
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}
