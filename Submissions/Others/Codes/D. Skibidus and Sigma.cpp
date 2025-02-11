#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int nm = n * m;
  int a[n + 1][m + 1]; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  priority_queue<pair<ll, int>> pq;
  for (int i = 1; i <= n; i++) {
    ll score = 0;
    for (int j = 1; j <= m; j++) {
      score += a[i][j];
    }
    pq.push({score, i});
  }

  int i = 1;
  ll ans = 0;
  while (!pq.empty()) {
    auto [_, idx] = pq.top();
    pq.pop();
    for (int j = 1; j <= m; j++, i++) {
      ans += 1ll * a[idx][j] * (nm - i + 1);
    }
  }
  cout << ans << '\n';
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