#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct NODE
{
    ll Y=-1,B=-1;
}Node;

bool cmp(NODE a, NODE b)
{
    return a.B > b.B;
}

vector< NODE >::iterator obj;
vector< vector< ll > > v;
vector< bool > vbool;
vector< NODE > Edge;
ll N,M,ans=0,ASML=0;


void DFS(ll n)
{
    if(ASML == N-1)
    {
        printf("%lld\n",ans);
        exit(EXIT_SUCCESS);
        return;
    }
    for (ll i = 0; i < N; i++)//寻找当前被寻找点的最小路径
    {
        if(v[n][i]!= -1 && vbool[i]==false)//如果这个路径可以走且这个点没有被走过
        {
            NODE BUG;//如果大于，加入未选择数组
            BUG.Y=i;
            BUG.B=v[n][i];
            Edge.push_back(BUG);
        }
    }
    stable_sort(Edge.begin(),Edge.end(),cmp);//排序
    for (ll i = Edge.size()-1; i >= 0; i--)
    {
        if(vbool[Edge[i].Y]==true)
        {
            obj=Edge.begin()+i;
            Edge.erase(obj); 
        }
    }
    ll Y=Edge[Edge.size()-1].Y;
    ans=ans+Edge[Edge.size()-1].B;
    Edge.pop_back();
    ASML++;
    vbool[Y] = true;
    DFS(Y);
    return;
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%lld%lld",&N,&M);
    v.resize(N);
    vbool.resize(N,false);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N,-1);
    }
    for (int i = 0; i < M; i++)
    {
        ll A,B,Z;
        //scanf("%lld%lld%lld",&A,&B,&Z);
        cin>>A>>B>>Z;
        A--;
        B--;
        v[A][B]=Z;
        v[B][A]=Z;
    }
    Node.B=10000;
    vbool[0] = true;
    DFS(0);
    return 0;
}
