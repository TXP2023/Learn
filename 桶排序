#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    srand((unsigned)time(NULL));
    cin>>n;
    double a[n],b[n],x,d;
    for (int i = 0; i < n; i++)
    {
        //cin>>a[i];
        a[i]=rand()%1000000000000;
    }
    for (int i = 0; i < n; i++)
    {
        x=a[i];
        for (int ti = i; ti < n; ti++)
        {
            if(x>a[ti])
            {
                d=x;
                x=a[ti];
                a[ti]=d;
            }
        }
        b[i]=x;
    }
    for (long long  i = 0; i < n; i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}
