#include <bits/stdc++.h>
using namespace std;
const int N = 2005, mod = 1e9 + 7;
int C[N][N], fact[N];

void prec() { // O(n^2)
  // nCr = (n-1)C(r-1) + (n-1)Cr
  for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
}

int nCr(int n, int r) {
  if (n < r) return 0;
  return C[n][r];
}

int nPr(int n, int r) {
  if (n < r) return 0;
  return 1ll * C[n][r] * fact[r] % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}