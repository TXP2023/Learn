#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N,ans=0;

vector< vector < ll > > v;
vector< bool > vbool;

void DFS(ll n)
{
    bool B=false;
    for (int i = 0; i < N; i++)
    {
        if (v[n][i] != 0 && !vbool[i])
        {
            B=true;
            vbool[i] = true;
            printf("%d",i+1);
            ans=ans+i+1;
            if(ans<(1+N)*N/2)
            {
                cout<<'-';
            }
            DFS(i);
            break;
        }
    }
    if(B==false)
    {
        ll i=0;
        while(vbool[i]==true) 
        {
            i++;
            if(i==N)
            {
                char a=127;
                //cout<<a;
                exit(0);
            }
        }
        vbool[i]=true;
        ans=ans+i+1;
        printf("%d",i+1);
        if(ans<(1+N)*N/2)
        {
            cout<<'-';
        }
        DFS(i);
    }
    return;
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%lld", &N);
    v.resize(N);
    vbool.resize(N,false);
    for (int i = 0; i < N; i++)
    {
        v[i].resize(N);
        //vint[i] = i;
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            scanf("%lld", &v[i][j]);
        }
    }
    ll M;
    scanf("%lld",&M);
    vbool[M]=true;
    printf("%lld%c",M+1,'-');
    ans=ans+M+1;
    DFS(M);
    return 0;
}
