#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int a[n + 1];
  int b[m + 1];
  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    mp2[b[i]]++;
  }

  for (int i = 1; i <= m; i++) {
    mp1[a[i]]++;
  }

  set<int> se;
  int match = 0;
  for (int i = 1; i <= n; i++) {
    if (se.find(a[i]) != se.end()) continue;
    match += min(mp1[a[i]], mp2[a[i]]);
    se.insert(a[i]);
  }

  int ans = 0;
  if (match >= k) ans++;

  for (int i = m + 1; i <= n; i++) {
    int idx = i - m;
    mp1[a[idx]]--;
    if (mp1[a[idx]] < mp2[a[idx]]) {
      match--;
    }
    mp1[a[i]]++;
    if (mp1[a[i]] <= mp2[a[i]]) {
      match++;
    }
    if (match >= k) ans++;
  }

  cout << ans << '\n';
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