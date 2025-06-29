#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
ll dp[N];

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  stack<pair<int, int>> st;
  int right[n + 1];
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first < a[i]) {
      right[st.top().second] = i - 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    right[st.top().second] = n;
    st.pop();
  }

  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    int idx = right[i];
    int nxt = idx + 1;
    dp[i] = 1ll * (a[i] + 1) * (idx - i + 1);
    if (nxt <= n) {
      if (a[nxt] == a[i] + 1) {
        dp[i] += dp[nxt];
      }
      else {
        dp[i] += 1ll * (a[i] + 1) * (n - nxt + 1);
      }
    }
    // cout << dp[i] << ' ';
    if (a[i] == 0) ans += dp[i];
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