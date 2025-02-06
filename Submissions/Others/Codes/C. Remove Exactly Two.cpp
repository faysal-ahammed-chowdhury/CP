#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<pair<int, int>> vec;
set<pair<int, int>> se;
int n;

void clr(int n) {
  se.clear();
  vec.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    if (u > v) swap(u, v);
    se.insert({u, v});
  }

  for (int i = 1; i <= n; i++) {
    vec.push_back({g[i].size(), i});
  }
  sort(vec.rbegin(), vec.rend());

  if (vec.size() == 2) {
    cout << 0 << '\n';
    return;
  }

  if (vec[0].first == vec[1].first and vec[1].first == vec[2].first) {
    cout << vec[0].first + vec[1].first - 1 << '\n';
    return;
  }

  if (vec[0].first == vec[1].first) {
    int u = vec[0].second, v = vec[1].second;
    if (u > v) swap(u, v);
    if (se.find({u, v}) == se.end()) cout << vec[0].first * 2 - 1 << '\n';
    else cout << vec[0].first * 2 - 2 << '\n';
    return;
  }

  for (int i = 1; i < vec.size(); i++) {
    if (vec[i].first != vec[1].first) break;
    int u = vec[0].second, v = vec[i].second;
    if (u > v) swap(u, v);
    if (se.find({u, v}) == se.end()) {
      cout << vec[0].first + vec[i].first - 1 << '\n';
      return;
    }
  }

  cout << vec[0].first + vec[1].first - 2 << '\n';
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