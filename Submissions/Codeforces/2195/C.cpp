#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
int n, a[N], dp[N][8];
int no_need[7];

int f(int i, int last) {
  if (i > n) return 0;

  int &ans = dp[i][last];
  if (ans != -1) return ans;

  ans = N;
  for (int j = 1; j <= 6; j++) {
    if (j != no_need[last] and j != last) {
      int cost = a[i] != j;
      ans = min(ans, cost + f(i + 1, j));
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= 6; j++) {
      dp[i][j] = -1;
    }
  }

  cout << f(1, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  no_need[1] = 6;
  no_need[6] = 1;
  no_need[2] = 5;
  no_need[5] = 2;
  no_need[3] = 4;
  no_need[4] = 3;

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}