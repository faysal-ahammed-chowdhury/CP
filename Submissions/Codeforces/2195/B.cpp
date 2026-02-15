#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, set<int>> mp;
  map<int, int> mp2;
  for (int i = 1; i <= n; i++) {
    int x = i;
    if (mp2.find(x) != mp2.end()) continue;
    for (int j = x; j <= n; j *= 2) {
      mp2[j] = x;
      mp[x].insert(a[j]);
    }
  }

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int x = mp2[i];
    // cout << i << ' ' << x << '\n';
    v.push_back(*mp[x].begin());
    mp[x].erase(mp[x].begin());
  }

  if (is_sorted(v.begin(), v.end())) cout << "YES\n";
  else cout << "NO\n";
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