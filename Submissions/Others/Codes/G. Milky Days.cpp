#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9, inf = 2e9;
int d[N], a[N];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> d[i] >> a[i];
  }
  int ans = 0;
  stack<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    st.push({d[i] + k - 1, a[i]});
    int cur = d[i] - 1;
    int meyad = inf, quantity = 0;
    while (!st.empty()) {
      meyad = st.top().first;
      quantity += st.top().second;
      st.pop();

      int possible = min(meyad, (cur + (quantity / m)));
      if (i + 1 <= n) possible = min(possible, d[i + 1] - 1);

      if (possible < cur) break;

      quantity = quantity - ((possible - cur) * m);
      ans += (possible - cur);

      // cout << i << ' ' << cur << ' ' << possible << ' ' << ans << '\n';

      cur = possible;
      if (i + 1 <= n and cur == d[i + 1] - 1) break;

      // break;
    }

    if (quantity > 0 and meyad > cur) {
      int baki = 0;
      if (i + 1 <= n) baki = (d[i + 1] - 1) - cur;
      if (baki == 0) {
        st.push({meyad, quantity});
      }
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