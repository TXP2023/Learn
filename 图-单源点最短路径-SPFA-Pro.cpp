#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node
{
    ll to,right;
    bool operator <(const node &a)const{
		return right<a.right;
	}
}Node;


vector< ll > head ,nxt ,_to ,_right ,ans;
priority_queue< node > _queue;
ll N,M,S,cnt;

inline void TODO(ll from,ll to,ll right)
{
    from--;
    to--;
    _to[cnt] = to;
    _right[cnt] = right;
    nxt[cnt] = head[from];
    head[from] = cnt++;
    return;
}

inline void SPFA()
{
    
    _queue.push({--S,0});
    ans[S] = 0;
    while(!_queue.empty())
    {
        
        while (!_queue.empty() && _queue.top().right > ans[_queue.top().to])
            _queue.pop();

        if(_queue.empty())
            break;
        
        
        Node = _queue.top();
        _queue.pop();

        for (ll i = head[Node.to]; ~i ; i = nxt[i])
        {
            if(ans[_to[i]] > ans[Node.to] + _right[i])
            {          
                ans[_to[i]] = ans[Node.to] + _right[i];
                _to[i] = Node.to;
                _right[i] = _right[i];
                _queue.push({_to[i],ans[_to[i]]});
                
            }
        }
        
    }
    
    
}

int main()
{
    freopen("D:\\code\\C++\\SHU_RU.in","r",stdin);
    scanf("%lld%lld%lld",&N,&M,&S);
    head.resize(N,-1);
    nxt.resize(M);
    _to.resize(M);
    _right.resize(M);
    ans.resize(N,1061109567);
    for(ll i=0;i<M;i++)
    {
        ll from,to,right;
        scanf("%lld%lld%lld",&from,&to,&right);
        TODO(from,to,right);
    }
    SPFA();
    for (ll i = 0; i < N; i++)
    {
        printf("%lld%c",ans[i],' ');
    }
    
    return 0;
}
