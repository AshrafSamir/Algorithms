#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/assoc_container.hpp> // Common file

using namespace __gnu_pbds;
using namespace std;

typedef long long  ll;
typedef long double  dbl;

template <class T>
using OSet= tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define endl "\n"
#define ee cout<<endl;
#define X first
#define Y second
#define maxx(a,b) a=max(a,b)
#define minn(a,b) a=min(a,b)
#define pb push_back

const int N=2e5+10,C=200,O=127,OO=0x7F7F7F7F;
const dbl EPS=-1e7;

struct edge{
    int to,cost;

    bool operator <(const edge &e)const{
        return this->cost-e.cost>=0;
    }
};

vector<edge> vec[N];
priority_queue<edge>pq;
int dist[N];
bool vis[N];

int MST(int from , int to){
    memset(dist,O,sizeof dist);
    memset(vis,0,sizeof vis);

    while(!pq.empty()) pq.pop();
    dist[from]=0;
    pq.push({from,0});
    int mx=0;

    edge e;
    while(!pq.empty()){
        e=pq.top();
        maxx(mx,e.cost);
        if(e.to == to) return mx;
        pq.pop();
        if (vis[e.to]) continue;
        else vis[e.to]=1;

        for(auto t :vec[e.to]){
            if(vis[t.to]) continue;
            if(dist[t.to]>t.cost){
                dist[t.to]=t.cost;
                pq.push({t.to,t.cost});
            }
        }
    }
    return OO;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int c,s,q;
    int i=1;
    while(cin>>c>>s>>q &&( c || s || q)){
        cout<<"Case #"<<i++<<endl;
        int from,to,cost;
        for(int i=0;i<s;++i){
            cin>>from>>to>>cost;
            vec[from].pb({to,cost});
            vec[to].pb({from,cost});
        }
        for(int i=0;i<q;++i){
            cin>>from>>to;
            int res=MST(from,to);
            (res>=130)? cout<<"no path":cout<<res;
            ee
        }
        for(int i=0;i<s;++i) vec[i].clear();
        ee
    }
}
