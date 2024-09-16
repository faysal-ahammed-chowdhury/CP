#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
array<int, 2> a[N];
int n, dp[N][N + N];

int f(int i, int last) {
  if (i > n) return 0;
  int &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = f(i + 1, last);
  if (a[i][1] >= last) {
    ans = max(ans, 1 + f(i + 1, a[i][1]));
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0];
    a[i][0] += 1001;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1];
    a[i][1] += 1001;
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof dp);
  cout << f(1, 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}