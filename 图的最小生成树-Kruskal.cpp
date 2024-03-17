#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct Edge
{
    ll from,to,right;
};

vector< vector< ll > > vlong;
vector< Edge > edges;
vector< ll > v;
ll N,M,ans = 0;

bool cmp(Edge a, Edge b)
{
    return a.right < b.right;
}

ll find(ll a)
{
    if(v[a] == a)
    {
        return a;
    }
    else
    {
        return v[a] = find(v[a]);
    }
}

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%lld%lld",&N,&M);
    vlong.resize(N);
    v.resize(N);
    for (ll i = 0; i < N; i++)
    {
        v[i] = i;
        vlong[i].resize(N,-1);
    }
    for (ll i = 0; i < M; i++)
    {
        ll from,to,right;
        scanf("%lld%lld%lld",&from,&to,&right);
        if(from!=to && (vlong[--from][--to]==-1 || right<vlong[from][to]) )
        {
            vlong[from][to] = right;
        }
    }

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if(vlong[i][j] != -1 /*&& i<j*/)
            {
                Edge EDGE;
                EDGE.right = vlong[i][j];
                EDGE.to = i;
                EDGE.from = j;
                edges.push_back(EDGE);
            }
        }
    }
    
    sort(edges.begin() ,edges.end() ,cmp);

    ll n = 1,i=0;
    while(n < N)
    {
        if(find( edges[i].from ) != find( edges[i].to ))
        {
            v[find( edges[i].from )] = find( edges[i].to );
            ans += edges[i].right;
            n++;
        }
        i++;
    }
    printf("%lld\n",ans);
    return 0;
}
