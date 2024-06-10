#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 9;
int s, p, m, n, a[N]; 
ll dp[N];

bool ok(int len, int i) {
  return (a[i + len - 1] - a[i]) < m;
}

ll fun(int i) {
  if (i == n + 1) {
    return 0;
  }

  ll &ans = dp[i];
  if (ans != -1) return ans;

  ans = s + fun(i + 1);
  int l = 1, r = n - i + 1, cnt = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid, i)) {
      cnt = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  ans = min(ans, p + fun(i + cnt));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> p >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  memset(dp, -1, sizeof(dp));
  cout << fun(1) << '\n';

  return 0;
}