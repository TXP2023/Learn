#include<iostream>
using namespace std;
int main()
{
    long long i,n,ti,j;
    cin>>n;
    long long z[n];
    for ( i = 0; i < n; i++)
    {
        cin>>z[i];
    }
    for ( i = 1; i <= n; i++)   //#############################
    {
        for ( ti = 0; ti < n-i; ti++)
        {
            if(z[ti]>z[ti+1])
            {
                j=z[ti];
                z[ti]=z[ti+1];
                z[ti+1]=j;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<z[i]<<" ";
    }
    return 0;
}
