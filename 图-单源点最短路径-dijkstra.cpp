#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node
{
    ll to,dis;
    bool operator <(const node& other) const{
        return dis > other.dis;
    }
};

struct edge
{
    ll to,dis;
}Edge;

vector< vector< edge > > edges;
priority_queue< node > _queue;
vector< bool > vis;
vector< ll > ans;
ll N,M,S,from;

inline void Djstl(ll s)
{
    _queue.push({s,0});
    while (!_queue.empty())
    {
        node now = _queue.top();
        _queue.pop();
        if(vis[now.to])
        {
            continue;
        }
        vis[now.to] = true;
        for (ll i = 0; i < edges[now.to].size(); i++)
        {
            if(ans[now.to] + edges[now.to][i].dis < ans[edges[now.to][i].to])
            {
                ans[edges[now.to][i].to] = ans[now.to] + edges[now.to][i].dis;
                edge e = edges[now.to][i];
                _queue.push({e.to,now.dis + e.dis});
            }
        }
        
    }
    return;
}

int main()
{
    //freopen("D:\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&N,&M,&S);
    vis.resize(N,false);
    ans.resize(N,1E9+7);
    edges.resize(N);
    for (ll i = 0; i < M; i++)
    {
        scanf("%lld%lld%lld",&from,&Edge.to,&Edge.dis);
        if(--from != -- Edge.to)
        {
            edges[from].push_back(Edge);
        }
    }
    ans[--S] = 0;
    Djstl(S);
    for (ll i = 0; i < N; i++)
    {
        printf("%lld%c",ans[i],' ');
    }
    return 0;
}
