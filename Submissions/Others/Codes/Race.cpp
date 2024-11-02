#include <bits/stdc++.h>
using namespace std;

const int N = 1005, mod = 10056;
int C[N][N], fact[N], dp[N];

void prec() { // O(n^2)
  // nCr = (n-1)C(r-1) + (n-1)Cr
  for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
}

int nCr(int n, int r) {
  if (n < r) return 0;
  return C[n][r];
}

int f(int rem) {
  if (rem == 0) return 1;
  int &ans = dp[rem];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 1; i <= rem; i++) {
    ans += 1ll * nCr(rem, i) * f(rem - i) % mod;
    ans %= mod;
  }
  return ans;
}

int cs;
void solve() {
  int n; cin >> n;
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": " << f(n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}