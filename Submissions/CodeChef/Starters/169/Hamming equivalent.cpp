#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par, sz;
  int c;
  DSU(int n) {
    par.resize(n + 1), sz.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
    c = n;
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() { // number of connected components
    return c;
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    c--;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i;
    sz[i] += sz[j];
    return i;
  }
};

void solve() {
  int n; cin >> n;
  int a[n + 1];
  DSU dsu(n);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int cnt = __builtin_popcount(a[i]);
    if (mp.find(cnt) == mp.end()) {
      mp[cnt] = a[i];
    }
    else dsu.merge(mp[cnt], a[i]);
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int cnt = __builtin_popcount(a[i]);
    ok &= dsu.same(mp[cnt], i);
  }

  if (ok) cout << "Yes\n";
  else cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}