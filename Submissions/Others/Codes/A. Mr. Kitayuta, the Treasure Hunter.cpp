#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 30005;
int n = 30000, a[N];
int dp[N][509], add;

int f(int i, int last) {
  if (i > n) return 0;
  int &ans = dp[i][last + add];
  assert(last + add >= 0 and last + add <= 500);
  if (ans != -1) return ans;
  ans = a[i];
  if (i + last <= n) ans = max(ans, a[i] + f(i + last, last));
  if (i + last + 1 <= n) ans = max(ans, a[i] + f(i + last + 1, last + 1));
  if (last > 1 and i + last - 1 <= n) ans = max(ans, a[i] + f(i + last - 1, last - 1));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, d; cin >> m >> d;
  while (m--) {
    int x; cin >> x;
    a[x]++;
  }

  add = d - 250;
  add *= -1;
  memset(dp, -1, sizeof dp);
  cout << a[0] + f(d, d) << '\n';

  return 0;
}