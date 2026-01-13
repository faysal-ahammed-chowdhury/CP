#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100;
ll C[N][N], fact[N];

void prec() { // O(n^2)
  // nCr = (n-1)C(r-1) + (n-1)Cr
  for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
  }

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i;
  }
}

int nCr(int n, int r) {
  if (n < r) return 0;
  return C[n][r];
}


void solve() {
  int n, k; cin >> n >> k;
  if (k > 60) {
    cout << 0 << '\n';
    return;
  }
  int msb = __lg(n);

  int ans = 0;
  for (int len = msb; len >= 1; len--) {
    for (int one = 1; one <= len; one++) {
      int zero = len - one;
      int need = 1 + ((one - 1) * 2) + zero;
      if (need <= k) {
        ans += nCr(len - 1, one - 1);
        // cout << len << ' ' << one << ' ' << nCr(len - 1, one - 1) << '\n';
      }
    }
  }

  if (msb + 1 <= k) ans++;

  cout << n - ans << '\n';
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