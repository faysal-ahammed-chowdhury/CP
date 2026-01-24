#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  string s; cin >> s;
  s = '.' + s;

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  set<int> alive;
  map<int, vector<int>> mp;
  b[0] = 1e9;
  for (int i = 1; i <= n; i++) {
    alive.insert(i);
    auto it1 = lower_bound(b + 1, b + m + 1, a[i]);
    int right = (it1 == (b + m + 1)) ? 1e9 : (*it1) - a[i];
    int left = *(--it1) - a[i];
    mp[left].push_back(i);
    mp[right].push_back(i);
  }

  int cur = 0;
  for (auto idx : mp[cur]) alive.erase(idx);
  for (int i = 1; i <= k; i++) {
    cur += s[i] == 'L' ? -1 : +1;
    for (auto idx : mp[cur]) alive.erase(idx);
    mp[cur].clear();
    cout << alive.size() << ' ';
  } cout << '\n';
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