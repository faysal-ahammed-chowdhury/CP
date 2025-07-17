#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
const ll inf = 1e18;
int n, a[N];
ll dp[N][2][2];

ll f(int i, bool swap, bool last_swap) {
  if (i > n) return 0;
  ll &ans = dp[i][swap][last_swap];
  if (ans != -1) return ans;
  ans = inf;
  if (swap) {
    int x = abs(a[i] - a[i - 1]);
    if (last_swap and i - 3 >= 1) {
      x += abs(a[i] - a[i - 3]);
    }
    else if (i - 2 >= 1) {
      x += abs(a[i] - a[i - 2]);
    }
    ans = min(ans, x + f(i + 1, false, true));
  }
  else {
    int x = 0;
    if (last_swap and i - 2 >= 1) {
      x += abs(a[i] - a[i - 2]);
    }
    else if (i - 1 >= 1) {
      x += abs(a[i] - a[i - 1]);
    }
    ans = min(ans, x + f(i + 1, false, false));
    if (i + 1 <= n) ans = min(ans, f(i + 1, true, last_swap));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  cout << f(1, false, false) << '\n';

  return 0;
}