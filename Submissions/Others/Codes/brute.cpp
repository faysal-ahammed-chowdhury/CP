#include <bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(0)

#define PB push_back

#define SZ 200005

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<bool> vbl;
typedef vector<string> vst;

// ordered_set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

/* debugger begin */
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T, typename V, typename Z>
void __print(const tuple<T, V, Z> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

void err(istream_iterator<string> it) {
    cerr << '\n';
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=";
    __print(a);
    cerr << ' ';
    err(++it, args...);
}

/* debugger end */

//const ll MOD = 1000000007;

const ll INF = (1LL<<59);

// point update
// range query
struct Segtree {
    vector<pll> values;
    int n;

    Segtree() {}

    Segtree(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        values.resize(4*n);
    }

    pll merge(pll a, pll b) {
        if (a.first == b.first) {
            return make_pair(a.first, a.second+b.second);
        }
        else {
            return max(a, b);
        }
    }

    void build(vector<ll> &a, int at, int lo, int hi) {
        if (lo == hi) {
            values[at] = {a[lo], 1LL};
            return;
        }
        int mid = (lo+hi)/2;
        build(a, at*2, lo, mid);
        build(a, at*2+1, mid+1, hi);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void build(vector<ll>&a) {
        build(a, 1, 1, n);
    }

    // point update
    // assign val to a[i]
    void update(int at, int lo, int hi, int i, ll val, int add) {
        if (i < lo || hi < i) return;
        if (lo == hi) {
            if (add) {
                values[at].first += val;
            }
            else {
                values[at].first = val;
            }
            return;
        }
        int mid = (lo+hi)/2;
        update(at*2, lo, mid, i, val, add);
        update(at*2+1, mid+1, hi, i, val, add);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void update(int i, ll val, int add) {
        update(1, 1, n, i, val, add);
    }

    void update(int at, int lo, int hi, int i, pll val) {
        if (i < lo || hi < i) return;
        if (lo == hi) {
            values[at] = val;
            return;
        }
        int mid = (lo+hi)/2;
        update(at*2, lo, mid, i, val);
        update(at*2+1, mid+1, hi, i, val);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void update(int i, pll val) {
        update(1, 1, n, i, val);
    }

    pll query() {
        return values[1];
    }
};

// point update
// range query
struct Segtree2 {
    vector<pll> values;
    int n;

    Segtree2() {}

    Segtree2(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        values.resize(4*n);
    }

    pll merge(pll a, pll b) {
        return max(a, b);
    }

    void build(vector<pll> &a, int at, int lo, int hi) {
        if (lo == hi) {
            values[at] = a[lo];
            return;
        }
        int mid = (lo+hi)/2;
        build(a, at*2, lo, mid);
        build(a, at*2+1, mid+1, hi);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void build(vector<pll>&a) {
        build(a, 1, 1, n);
    }

    // point update
    // assign val to a[i]
    void update(int at, int lo, int hi, int i, ll val, int add) {
        if (i < lo || hi < i) return;
        if (lo == hi) {
            if (add) {
                values[at].first += val;
            }
            else {
                values[at].first = val;
            }
            return;
        }
        int mid = (lo+hi)/2;
        update(at*2, lo, mid, i, val, add);
        update(at*2+1, mid+1, hi, i, val, add);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void update(int i, ll val, int add) {
        update(1, 1, n, i, val, add);
    }

    void update(int at, int lo, int hi, int i, pll val) {
        if (i < lo || hi < i) return;
        if (lo == hi) {
            values[at] = val;
            return;
        }
        int mid = (lo+hi)/2;
        update(at*2, lo, mid, i, val);
        update(at*2+1, mid+1, hi, i, val);
        values[at] = merge(values[at*2], values[at*2+1]);
    }

    void update(int i, pll val) {
        update(1, 1, n, i, val);
    }

    pll query() {
        return values[1];
    }
};

void dfs1(int u, vector<vi> &G, vi &order, vi &visited) {
    visited[u] = 1;
    for (auto v : G[u]) {
        if (!visited[v]) {
            dfs1(v, G, order, visited);
        }
    }
    order.PB(u);
}
 
void dfs2(int u, vector<vi> &Gr, vi &comp, vi &visited) {
    visited[u] = 1;
    comp.PB(u);
    for (auto v : Gr[u]) {
        if (!visited[v]) {
            dfs2(v, Gr, comp, visited);
        }
    }
}

void solve(int tt) {
    int n, m, q;
    cin >> n >> m >> q;
    vvi G(n+1), Gr(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].PB(v);
        Gr[v].PB(u);
    }
    vi s(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    vi order;
    vi vis(n+1), vis2(n+1);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i, G, order, vis);
        }
    }
    // error(order);
    int cnt = 0;
    vpii a(n+1);
    vector<Segtree> ss;
    reverse(all(order));
    for (auto u : order) {
        if (!vis2[u]) {
            vi comp;
            dfs2(u, Gr, comp, vis2);
            // error(comp);
            int sz = comp.size();
            vll b(sz+1);
            for (int j = 0; j < sz; ++j) {
                int v = comp[j];
                a[v] = {cnt, j+1};
                b[j+1] = s[v];
            }
            Segtree st(sz);
            st.build(b);
            ss.emplace_back(st);
            ++cnt;
        }
    }
    Segtree2 st(cnt);
    vpll d(cnt+1);
    for (int i = 1; i <= cnt; ++i) {
        d[i] = ss[i-1].query();
    }
    vll c(cnt);
    st.build(d);
    while (q--) {
        string t;
        cin >> t;
        if (t == "AC") {
            ll x, y;
            cin >> x >> y;
            auto [u, v] = a[y];
            st.update(u+1, x, 1);
            c[u] += x;
        }
        else if (t == "AS") {
            ll x, y;
            cin >> x >> y;
            auto [u, v] = a[y];
            ss[u].update(v, x, 1);
            pll ret = ss[u].query();
            ret.first += c[u];
            st.update(u+1, ret);
        }
        else {
            auto [u, v] = st.query();
            if (u < 0) cout << 0 << endl;
            else cout << u << endl;
        }
    }
    // error(G, Gr);
}

int main() {
    FASTIO;
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}