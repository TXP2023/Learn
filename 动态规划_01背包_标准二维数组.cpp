#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <assert.h>
#include <math.h>
#include <stack>
#include <iostream>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque
#define stack std::stack

typedef long long ll;

struct stuff//东西
{
    ll volume,money;//volume 对应体积 money对应价值
};

vector< vector< ll > > dp;
vector< stuff > v;
ll n,m;//n个东西 m个空间

inline ll max(ll a,ll b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    scanf("%lld%lld",&m,&n);
    v.resize(n);
    dp.resize(n+1);
    dp[0].resize(m+1,0);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld%lld",&v[i].volume,&v[i].money);
        dp[i+1].resize(m+1,0);
    }
    for (ll i = 1; i < n+1; i++)
    {
        for (ll j = 1; j < m+1; j++)
        {
            if (v[i-1].volume > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i-1].volume]+v[i-1].money);
            }
        }
    }
    printf("%lld\n",dp[n][m]);
    return 0;
}
