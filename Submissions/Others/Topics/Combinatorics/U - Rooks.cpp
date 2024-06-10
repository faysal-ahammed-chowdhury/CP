#include <bits/stdc++.h>
using namespace std;
const int N = 32;
long long C[N][N];

void prec() {
  for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int n, k; cin >> n >> k;

  if (k > n) {
    cout << 0 << '\n';
    return;
  }
  long long fact = 1;
  for (int i = 1; i <= k; i++) {
    fact *= i;
  }
  long long ans = C[n][k] * C[n][k] * fact;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}