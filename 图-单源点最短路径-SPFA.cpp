//有权有向图

#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#define ll long

using namespace std;

struct  anode
{
    ll k,right;//走到了节点k,累计权重为right 987\57
    bool operator <(const anode &a)const{
		return right<a.right;
	}
};

priority_queue< anode > nodes;
vector< vector< anode > > v;
vector< ll > vis;
ll N,M,L;//N个点 M条无相边 K次询问 从点L开始

inline void BFS(ll l)
{        
    anode Node;//建立一个类型为anode的结构体为队列的首位
    Node.k = l;
    Node.right = 0;
    nodes.push(Node);//压入队列
    while (!nodes.empty())//如果队列不为空
    {
        while(!nodes.empty() && vis[nodes.top().k] < nodes.top().right)
            nodes.pop();

        if(nodes.empty())
            return;

        anode node = nodes.top();
        nodes.pop();//弹出
        for (ll i = 0; i < v[node.k].size(); i++)
        {
            if((vis[ v[node.k][i].k ] == -1 || vis[v[node.k][i].k] > v[node.k][i].right+node.right) )//如果存在路径且
            {
                vis[v[node.k][i].k] = v[node.k][i].right+node.right;
                anode NODE;
                NODE.k = v[node.k][i].k;
                NODE.right = v[node.k][i].right+node.right;
                nodes.push(NODE);
            }
        }
    }
    return;
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%ld%ld%ld",&N,&M,&L);
    v.resize(N);
    vis.resize(N,-1);
    for (ll i = 0; i < M; i++)
    {
        ll from,to,right;
        scanf("%ld%ld%ld",&from,&to,&right);
        if(--from != --to )
        {
            anode Anode;
            Anode.k = to;
            Anode.right = right;
            v[from].push_back(Anode);
        }
    }
    L--;
    vis[L] = 0;
    BFS(L);
    for (ll i = 0; i < N; i++)
    {
        switch (vis[i])
        {
        case -1:
            printf("%ld%c",-1,' ');
            break;
        
        default:
            printf("%ld%c",vis[i],' ');
            break;
        }
    }
    printf("\n");
    return 0;
}
