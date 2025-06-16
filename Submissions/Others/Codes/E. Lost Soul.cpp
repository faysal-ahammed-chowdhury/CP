#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  map<int, vector<int>> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp1[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    mp2[b[i]].push_back(i);
  }

  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] == b[i]) ans = max(ans, i);
    auto it1 = upper_bound(mp1[a[i]].begin(), mp1[a[i]].end(), i);
    auto it2 = upper_bound(mp2[a[i]].begin(), mp2[a[i]].end(), i + 1);
    if (it1 != mp1[a[i]].end() or it2 != mp2[a[i]].end()) ans = max(ans, i);
  }

  for (int i = n; i >= 1; i--) {
    auto it1 = upper_bound(mp1[b[i]].begin(), mp1[b[i]].end(), i + 1);
    auto it2 = upper_bound(mp2[b[i]].begin(), mp2[b[i]].end(), i);
    if (it1 != mp1[b[i]].end() or it2 != mp2[b[i]].end()) ans = max(ans, i);
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