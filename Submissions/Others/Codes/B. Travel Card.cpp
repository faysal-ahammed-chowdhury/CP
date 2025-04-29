#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N], dp[N];
int n;

int f(int i) {
  if (i <= 0) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 20 + f(i - 1);
  auto it = lower_bound(a + 1, a + n + 1, a[i] - 90 + 1);
  int idx = it - a;
  ans = min(ans, 50 + f(idx - 1));

  auto it2 = lower_bound(a + 1, a + n + 1, a[i] - 1440 + 1);
  int idx2 = it2 - a;
  ans = min(ans, 120 + f(idx2 - 1));

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    cout << f(i) - f(i - 1) << '\n';
  }

  return 0;
}