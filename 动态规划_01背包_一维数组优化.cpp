#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <assert.h>
#include <math.h>

#define vector std::vector
#define queue std::queue
#define priority_queue std::priority_queue
#define deque std::deque

typedef long long ll;

struct stuff//储存物品数据的结构体
{
    ll money,volume;
};

vector< ll > dp;//dp[i]表示前i件物品的最大价值
vector< stuff > v;//储存物品数据
ll N,M;//N 对应背包空间 M对应物品数量

inline ll max(ll a,ll b)//max函数
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    scanf("%lld%lld",&N,&M);//输入背包容量和物品数量
    v.resize(M);//初始化v
    dp.resize(N+1);//初始化dp
    for (ll i = 0; i < M; i++)//读取物品数据
    {
        scanf("%lld%lld",&v[i].volume,&v[i].money);
    }
    for (ll i = 0; i < M; i++)//枚举前i种物品
    {
        for (ll j = N; j >= 0; j--)//逆序计算
        {
            if (v[i].volume <= j)//如果第i种物品的体积小于等于背包剩余容量
            {
                dp[j] = max(dp[j],dp[j-v[i].volume]+v[i].money);//动态转移方程
            }
        }
    }
    printf("%lld\n",*(dp.end()-1));//输出
    return 0;
}   
