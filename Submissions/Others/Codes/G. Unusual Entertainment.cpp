#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
vector<int> g[N];
int n, a[N], disc[N], finish[N];
int timer, tmp[N];

void dfs(int u, int p) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

struct wavelet_tree {
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;
  long long *sum = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high) return;
    pref = new int[r - l + 2];
    sum = new long long[r - l + 2];
    pref[0] = 0;
    sum[0] = 0;
    int mid = (low + high) >> 1, cnt = 1;
    for (int *i = l; i != r; i++, cnt++) {
      pref[cnt] = pref[cnt - 1] + ((*i) <= mid);
      sum[cnt] = sum[cnt - 1] + (*i);
    }
    int *pivot = stable_partition(l, r, [&](int x) {return x <= mid;});
    lft = new wavelet_tree(l, pivot, low, mid);
    rgt = new wavelet_tree(pivot, r, mid + 1, high);
  }
  // returns the count of elements that are less than or equal to 'k' in range [l,r]
  int LTE(int l, int r, int k) {
    if (l > r || low > k) return 0;
    if (high <= k) return r - l + 1;
    return lft->LTE(pref[l - 1] + 1, pref[r], k) + rgt->LTE(l - pref[l - 1], r - pref[r], k);
  }
  int GTE(int l, int r, int k) {
    if (l > r || high < k) return 0;
    if (low >= k) return r - l + 1;
    return lft->GTE(pref[l - 1] + 1, pref[r], k) + rgt->GTE(l - pref[l - 1], r - pref[r], k);
  }
  ~wavelet_tree() {
    if (pref != NULL) delete []pref;
    if (sum != NULL) delete []sum;
    if (lft != NULL) delete lft;
    if (rgt != NULL) delete rgt;
  }
};

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  int q; cin >> n >> q;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[x] = i;
  }

  timer = 0;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    tmp[disc[i]] = a[i];
  }

  wavelet_tree t = wavelet_tree(tmp + 1, tmp + n + 1, 1, n);
  while (q--) {
    int l, r, x; cin >> l >> r >> x;
    int L = disc[x], R = finish[x];
    int choto = t.LTE(L, R, l - 1);
    int boro = t.GTE(L, R, r + 1);
    int cnt = choto + boro;
    int len = R - L + 1;
    if (cnt != len) cout << "YES\n";
    else cout << "NO\n";
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}