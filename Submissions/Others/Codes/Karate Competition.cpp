#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 55;
int n, a[N], b[N], dp[N][N];

int f(int i, int j) {
  if (i > n or j > n) return 0;
  int &ans = dp[i][j];
  if (~ans) return ans;
  ans = f(i + 1, j);
  ans = max(ans, f(i, j + 1));
  if (a[i] == b[j]) {
    ans = max(ans, 1 + f(i + 1, j + 1));
  }
  else if (a[i] > b[j]) {
    ans = max(ans, 2 + f(i + 1, j + 1));
  }

  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  reverse(a + 1, a + n + 1);
  reverse(b + 1, b + n + 1);

  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": " << f(1, 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}