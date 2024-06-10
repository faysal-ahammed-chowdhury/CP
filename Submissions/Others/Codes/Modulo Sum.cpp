#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, a[N], dp[N][N][2];

int fun(int i, int sum, int nisi) {
  if (i == n + 1) {
    return sum == 0 and nisi;
  }
  int &ans = dp[i][sum][nisi];
  if (ans != -1) return ans;
  ans = fun(i + 1, sum, nisi);
  ans |= fun(i + 1, (sum + a[i]) % m, 1);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if (n >= m) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  cout << (fun(1, 0, 0) ? "YES" : "NO") << '\n';

  return 0;
}