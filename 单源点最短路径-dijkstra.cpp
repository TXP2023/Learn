//有权有向图

#include <stdio.h>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

struct  anode
{
    ll k,right;//走到了节点k,累计权重为right
};

vector< vector< ll > > v;
vector< ll > vis;
queue< anode > nodes;
ll N,M,K,L;//N个点 M条无相边 K次询问 从点L开始

void BFS(ll l)
{
    anode Node;
    Node.k = l;
    Node.right = 0;
    nodes.push(Node);
    while (!nodes.empty())
    {
        anode node;
        node = nodes.front();
        nodes.pop();
        for (ll i = 0; i < N; i++)
        {
            if(v[node.k][i]!=-1 && (vis[i] == -1 || vis[i] > v[node.k][i]+node.right) )
            {
                vis[i] = v[node.k][i]+node.right;
                anode NODE;
                NODE.k = i;
                NODE.right = v[node.k][i]+node.right;
                nodes.push(NODE);
            }
        }
    }
    return;
}

int main()
{
    freopen("D:\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld%lld",&N,&M,&K,&L);
    v.resize(N);
    vis.resize(N,-1);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N,-1);
    }
    for (ll i = 0; i < M; i++)
    {
        ll from,to,right;
        scanf("%lld%lld%lld",&from,&to,&right);
        if(from != to && (v[--from][--to]>right || v[from][to] == -1))
        {
            v[from][to] = right;
        }
    }
    BFS(L);
    for (ll i = 0; i < K; i++)
    {
       ll x,y;
       scanf("%lld",&x);
       x--;
       printf("%lld\n",vis[x]);
    }
    return 0;
}
