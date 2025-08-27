#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005, mod = 998244353;
int n, a[N], dp[N][N][2];

int f(int i, int tot, bool boro) {
  if (i > n) {
    if (boro) return 0;
    return (tot + 1) / 2;
  }
  int &ans = dp[i][tot][boro];
  if (ans != -1) return ans;
  ans = f(i + 1, tot, boro);
  ans = (ans + f(i + 1, tot + a[i], (a[i] * 2 >= (tot + a[i])))) % mod;
  if ((a[i] * 2 >= (tot + a[i]))) ans = (ans + a[i]) % mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof dp);
  cout << f(1, 0, 0) << '\n';

  return 0;
}