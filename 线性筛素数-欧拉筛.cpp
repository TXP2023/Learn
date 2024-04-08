#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

typedef long long ll;

std::vector< ll > ans;
std::vector< bool > vb;
ll n,q;

int main()
{
    //freopen("D:\\code\\C++\\SHU_RU.in", "r",stdin);
    scanf("%lld%lld",&n,&q);
    vb.resize(n,true);
    vb[0] = false;
    for (ll i = 1; i < n; i++)
    {
        if(vb[i])
        {
            ans.push_back(i+1);
        }
        for (ll j = 1; j <= ans.size() && i*ans[j-1]<n; j++)
        {
            vb[i*ans[j-1]-1] = false;
            if(i%ans[j-1] == 0)
                break;
        }
    }
    for (ll i = 0; i < q; i++)
    {
        ll k;
        scanf("%lld",&k);
        printf("%lld\n",ans[k-1]);
    }
    
}
