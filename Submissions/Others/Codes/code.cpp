#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(x) x.begin(),x.end()
// #define int long long

#ifdef SHAMIM_AHMED
    #include <G:\Desktop Items\STATION\CPP\debug.h>
#else
    #define debug(x...) 
    #define debug2(x...) 
    #define debug3(x...)
#endif

const int N = 2e5+10;
vector<int> adj[2][N];
bool vis[2][N];
stack<int> stk;
int c = 0;
int j = 1;
map<int,int> comp;
map<int,int> idx;
map<int,int> comp_size;
map<int,int> comp_start;
int a[N];
void dfs(int vertex,int t)
{
    if(t == 1)
    {
        comp_size[c]++;
        comp[vertex] = c;
        idx[vertex] = j++;
    }

    vis[t][vertex] = true;
    for(auto child: adj[t][vertex])
    {
        if(vis[t][child]) continue;

        dfs(child,t);
    }
    if(t == 0)
    stk.push(vertex);
}


struct ST {
    int tree[4 * N], lazy[4 * N];
    void push(int n, int b, int e) {
        if (lazy[n] == 0) return;
        tree[n] += lazy[n];
        if (b != e) {
            int l = n << 1, r = l + 1;
            lazy[l] += lazy[n];
            lazy[r] += lazy[n];
        }
        lazy[n] = 0;
    }
    void build(int n, int b, int e) {
        lazy[n] = 0;
        if (b == e) {
            tree[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(n * 2, b, mid);
        build(n * 2 + 1, mid + 1, e);
        tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
    }
    void upd(int n, int b, int e, int i, int j, int x) {
        push(n, b, e);
        if (e < i or b > j) {
            return;
        }
        if (b >= i and e <= j) {
            lazy[n] += x;
            push(n, b, e);
                return;
        }
        int mid = (b + e) >> 1;
        upd(n * 2,b, mid,i, j, x);
        upd(n * 2 + 1,mid + 1,e,i, j, x);
        tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (e < i or b > j) {
            return 0;
        }
        if (b >= i and e <= j) {
                return tree[n];
        }
        int mid = (b + e) >> 1;
        int L = query(n * 2,b, mid,i, j);
        int R = query(n * 2 + 1,mid + 1,e,i, j);
        return max(L, R);
    }
} st;

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }

    int income[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> income[i];
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[0][i] == false)
        {
            dfs(i,0);
        }
    }
    j = 1;
    while(stk.size())
    {
        if(vis[1][stk.top()] == false)
        {
            c++;
            comp_start[c] = j;
            dfs(stk.top(),1);
        }
        stk.pop();
    }

    // for(auto [x,y]: comp)
    // {
    //     cout << x << " -> " << idx[x] << endl;
    //     // cout << idx[x] << endl;
    // }    

    // debug(comp_size);
    // debug(comp_start);
    for (int i = 1; i <= n; i++) {
        a[idx[i]] = income[i];
    }
    st.build(1, 1, n);
    while (q--) {
        string Q; cin >> Q;
        if (Q=="Q") {
            cout << max(st.query(1,1, n, 1, n), 0) << '\n';
        }
        else if (Q == "AC") {
            int x, y; cin >> x >> y;
            int start = comp_start[comp[y]];
            int end = start + comp_size[comp[y]] - 1;
            st.upd(1, 1, n, start, end, x);
        }
        else {
            int x, y; cin >> x >> y;
            st.upd(1, 1, n, idx[y], idx[y], x);
        }
    }
    


}

int32_t main()
{
    //    Bismillah
    int t = 1;
    // cin >> t;
    while(t--) solve();
}