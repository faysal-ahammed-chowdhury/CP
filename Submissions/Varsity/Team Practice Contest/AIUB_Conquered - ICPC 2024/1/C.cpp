#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1005, mod = 1e9 + 7;
int n, dp1[N][N], dp2[N][N];

int f(int rem, int last) {
  if (rem == 0) return 1;
  if (last < 0) return 0;
  int &ans = dp1[rem][last];
  if (ans != -1) return ans;
  ans = f(rem, last - 1);
  if (rem - last >= 0) {
    ans += f(rem - last, last);
    ans %= mod;
  }
  return ans;
}

int f2(int rem, int last) {
  if (rem == 0) return 1;
  if (last > n) return 0;
  int &ans = dp2[rem][last];
  if (ans != -1) return ans;
  ans = f2(rem, last + 1);
  if (rem - last >= 0) {
    ans += f2(rem - last, last);
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int ans = 0;
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  for (int mex = 1; mex <= n + 1; mex++) {
    int cur = 0;
    for (int i = 0; i <= n; i++) {
      int x = mex - 1;
      int need = i - ((x * (x + 1)) / 2);
      if (need < 0) continue;
      int cnt1 = f(need, x);
      int z = n - i;
      if (z >= 0) {
        int cnt2 = f2(z, mex + 1);
        int y = 1ll * cnt1 * cnt2 % mod;
        ans += 1ll * y * mex % mod;
        ans %= mod;
      }
      else {
        ans += 1ll * mex * cnt1 % mod;
        ans %= mod;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}