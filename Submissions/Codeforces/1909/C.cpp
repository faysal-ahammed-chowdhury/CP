#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n; 
  int l[n + 1], r[n + 1], c[n + 1];
  multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    ms.insert(l[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  sort(r + 1, r + n + 1);
  sort(c + 1, c + n + 1);
  vector<int> dis;
  for (int i = 1; i <= n; i++) {
    auto it = ms.lower_bound(r[i]);
    it--;
    dis.push_back(r[i] - (*it));
    ms.erase(it);
  }
  sort(dis.rbegin(), dis.rend());

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * dis[i - 1] * c[i];
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}