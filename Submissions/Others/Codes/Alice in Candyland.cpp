#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 9;
int n, k;
int a[N][N], dp[(1 << N) + 2][(1 << N) + 2];

int cnt = 0;
int f(int mask1, int mask2) {
  if (__builtin_popcount(mask1) + __builtin_popcount(mask2) == min(k, n + n)) {
    return 0;
  }

  int &ans = dp[mask1][mask2];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (CHECK(mask1, i) == false) {
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        if (CHECK(mask2, j) == false) {
          sum += a[i][j];
        }
      }
      ans = max(ans, sum + f(mask1 | (1 << i), mask2));
    }
  }

  for (int j = 1; j <= n; j++) {
    if (CHECK(mask2, j) == false) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        if (CHECK(mask1, i) == false) {
          sum += a[i][j];
        }
      }
      ans = max(ans, sum + f(mask1, mask2 | (1 << j)));
    }
  }

  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof dp);
  cout << f(0, 0) << '\n';
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