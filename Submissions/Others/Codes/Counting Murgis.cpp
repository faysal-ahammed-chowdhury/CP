#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 23;
int n, k;
int dp[N][N][N];

int f(int i, int last) {
  if (i <= 0) {
    if (i == 0) return 1;
    return 0;
  }

  int &ans = dp[n][i][last];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = last - 1; j > 0; j--) {
    ans += f(i - 1, j);
  }

  return ans;
}

void solve() {
  cin >> n >> k;
  cout << f(k, n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}