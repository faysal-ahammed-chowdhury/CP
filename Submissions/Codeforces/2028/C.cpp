#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int n, m, v, a[N], psum[N];
int dp[N], en[N];

int f(int i) {
  if (i > n) return 0;
  auto it = lower_bound(psum, psum + n + 1, psum[i - 1] + v) - psum;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 0;
  if (it <= n) {
    ans = max(ans, 1 + f(it + 1));
  }
  return ans;
}

bool ok(int r, int baki) {
  return f(r + 1) >= baki;
}

void solve() {
  cin >> n >> m >> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1]  + a[i];
  }

  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  
  if (f(1) < m) {
    cout << -1 << '\n';
    return;
  }

  int id = 1;
  for (int i = 1; i <= m; i++) {
    auto it = lower_bound(psum, psum + n + 1, psum[id - 1] + v) - psum;
    en[i] = it;
    id = it + 1;
  }

  int ans = 0;
  for (int i = 0; i <= m; i++) {
    int l = en[i] + 1, r = n, cur = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, m - i)) {
        cur = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    int here = psum[cur] - psum[en[i]];
    ans = max(ans, here);
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