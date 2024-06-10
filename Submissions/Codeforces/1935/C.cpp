#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, L; cin >> n >> L;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    priority_queue<int> pq;
    int cur = 0;
    for (int r = l; r <= n; r++) {
      cur += a[r].second;
      pq.push(a[r].second);
      while (!pq.empty() and a[r].first - a[l].first + cur > L) {
        int mx = pq.top();
        pq.pop();
        cur -= mx;
      }
      ans = max(ans, (int)pq.size());
    }
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