#include<bits/stdc++.h>
using namespace std;
vector<bool> b;
vector<int> c;
int m=3;
int64_t k(int64_t n)
{
    if(n==1) return n;
    return  n*k(n-1);
}
void f(int n)
{
    if(n==m+1){
        for (int i = 0; i < m; i++)
        {
            cout<<c[i]<<"  ";
        }
        cout<<endl;
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
    cin>>m;
    c.resize(m);
    b.resize(m);
    f(1);
    cout<<"Number of programs:"<<k(m);
    return 0;
}
