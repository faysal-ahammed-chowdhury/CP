#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int pos[n + 1];
  for (int i = 1; i <= n; i++) {
    pq.push({ a[i], i});
    pos[i] = a[i];
  }

  while (!pq.empty()) {
    auto [x, idx] = pq.top(); pq.pop();
    if (pos[idx] < min(x, a[idx])) continue;
    // cout << idx << ' ' << x << '\n';
    pos[idx] = min(x, a[idx]);
    if (idx > 1 and pos[idx - 1] > pos[idx] + 1) pq.push({pos[idx] + 1, idx - 1});
    if (idx < n and pos[idx + 1] > pos[idx] + 1) pq.push({pos[idx] + 1, idx + 1});
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    // cout << pos[i] << ' ';
    ans += a[i] - pos[i];
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