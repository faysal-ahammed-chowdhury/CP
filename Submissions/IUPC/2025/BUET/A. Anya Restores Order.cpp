#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
  vector<int> par, mex;
  vector<set<int>> se;
  DSU(int n) {
    par.resize(n + 1);
    se.resize(n + 1);
    mex.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
  }
  int find(int i) {
    return (i == par[i] ? i : par[i] = find(par[i]));
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    if (se[i].size() < se[j].size()) swap(i, j);
    int cur_mex = max(mex[i], mex[j]);
    for (auto x : se[j]) {
      se[i].insert(x);
    }
    while (se[i].find(cur_mex) != se[i].end()) {
      cur_mex++;
    }
    se[j].clear();
    mex[i] = cur_mex;
    par[j] = i;
    return i;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  DSU dsu(n);
  for (int i = 1; i <= n; i++) {
    int m; cin >> m;
    while (m--) {
      int x; cin >> x;
      dsu.se[i].insert(x);
    }
    int mex = 1;
    for (auto x : dsu.se[i]) {
      if (mex == x) mex++;
    }
    dsu.mex[i] = mex;
  }

  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i, j; cin >> i >> j;
      dsu.merge(i, j);
    }
    else {
      int i; cin >> i;
      i = dsu.find(i);
      int ans = dsu.mex[i];
      if (dsu.se[i].size() > 0 and ans > *dsu.se[i].rbegin()) cout << "complete\n";
      else cout << ans << '\n';
    }
  }
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