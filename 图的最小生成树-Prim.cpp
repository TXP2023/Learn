
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct EDGE
{
    ll from,to,right;
};

ll N,M;
vector<EDGE>::iterator obj;
vector<EDGE> way;
vector< bool > vbool;
vector< ll > v;

ll find(ll x)
{
    if(v[x] == x)
    {
        return x;
    }
    else
    {
        return v[x] = find(v[x]);
    }
}

bool cmp(EDGE x, EDGE y)
{
    return x.right < y.right;
}

ll Prim()
{
    ll ans=0,ASML=0;
    sort(way.begin(),way.end(),cmp);
    vbool[way[0].from]=true;
    while (ASML<N-1)
    {
        for (ll i = 0; i < way.size(); i++)
        {
            if(ASML==N-1)
            {
                break;
            }
            else
            {
                if(v.size()==0)
                {
                    printf("orz\n");
                    exit(EXIT_SUCCESS);
                }
            }
            if((vbool[ way[i].to ] == false && vbool[ way[i].from ] == true))
            {
                vbool[ way[i].to ]=true;
                v[way[i].to] = find(way[i].from);
                obj = way.begin()+i;
                ans += way[i].right;
                way.erase(obj);
                i--;
                ASML++;
            }
            else
            {
                if((vbool[ way[i].to ] == true && vbool[ way[i].from ] == false))
                {
                    vbool[ way[i].from ]=true;
                    v[way[i].from] = find(way[i].to);
                    obj = way.begin()+i;
                    ans += way[i].right;
                    way.erase(obj);
                    i--;
                    ASML++;
                }
            }
        }
    }
    return ans;
    
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in", "r", stdin);
    scanf("%lld%lld",&N,&M); //输入代表有N个节点M条路径
    v.resize(N);
    vbool.resize(N,false);
    for (ll i = 0; i < N; i++)
    {
        v[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        EDGE e;
        cin >> e.from >> e.to >> e.right;
        e.from--;
        e.to--;
        way.push_back(e);
    }
    //vbool[0]=true;
    printf("%lld\n",Prim());
    return 0;
}
