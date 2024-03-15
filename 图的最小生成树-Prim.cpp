#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Edge{//存信息
    ll to,right;// to
};

vector< vector< ll > > v;
vector< bool > vis;
vector< Edge > ve;
ll N,M,ans=0,to; // N个点 M个边

bool cmp( Edge a, Edge b)
{
    return a.right > b.right;
}

void DFS(ll n,ll m)
{
    if(n == N)//如果已经联通的边包含全部边
    {
        printf("%lld",ans);
        exit(EXIT_SUCCESS);
        return;
    }
    for (ll i = 0; i < N; i++)//寻找所以当前寻找点联通的边
    {
        if(v[m][i] != -1 && !vis[i])//如果这个点可以被当前寻找点到达。且没有被走过
        {
            Edge EDGE;              //添加到ve备用
            EDGE.right = v[m][i];   
            EDGE.to = i;            
            ve.push_back(EDGE);     
        }
    }
    for (ll i = ve.size()-1; i >= 0; i--) //去除已经没有实际意义的路径存储
    {
        if(vis[ ve[i].to ])
        {
            ve.erase(ve.begin() + i); //删掉它
        }
    }
    sort(ve.begin(),ve.end(),cmp);  //排序以寻找路权最小的，和当前树连接的点
    
    if (ve.size()>0)//如果可以有点被选择
    {
        ans += ve[ve.size()-1].right;  //选择它加上他的路权
        vis[ ve[ve.size()-1].to ] = true; //将他标记为 "已经连接"
        to = ve[ve.size()-1].to;
        ve.erase( ve.end() );   //删除
        DFS(n+1, to );  //继续
    }
    else
    {
        printf("orz");
        exit(EXIT_SUCCESS);
    }
    return;
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    //freopen("D:\\code\\C++\\SHU_CHU.out", "w", stdout);
    scanf("%lld%lld",&N,&M);
    vis.resize(N,false);
    v.resize(N);
    for (ll i = 0; i < N; i++)
    {
        v[i].resize(N,-1);
    }
    
    for (ll i = 0; i < M; i++)
    {
        {
            ll A,B,Z;
            cin>>A>>B>>Z;
            if(A!=B)
            {
                if(v[--A][--B] == -1 || v[A][B] > Z)
                {
                    v[A][B] = Z;
                    v[B][A] = Z;
                }
            }
        }
    }
    vis[0] = true;
    DFS(1,0);
    return 0;
}
