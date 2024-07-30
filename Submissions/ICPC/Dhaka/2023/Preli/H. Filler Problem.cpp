#include <bits/stdc++.h>
using namespace std;
const int N = 125;
int n, a[N];
long long prefix[N];
// bitset<5005> vis[N][5005];
bitset<5005> dp[N][5005];

// bool f(int i, int sum1, int sum2) {
//   if (i == 0) {
//     if (sum1 == 0 and sum2 == 0) {
//       return true;
//     }
//     return false;
//   }
//   if (vis[i][sum1][sum2]) return dp[i][sum1][sum2];
//   bool ans = f(i - 1, sum1, sum2);
//   if (ans) {
//     dp[i][sum1][sum2] = 1;
//     return ans;
//   }
//   if (sum1 - a[i] >= 0) {
//     ans = f(i - 1, sum1 - a[i], sum2);
//     if (ans) {
//       dp[i][sum1][sum2] = 1;
//       return ans;
//     }
//   }
//   if (sum2 - a[i] >= 0) {
//     ans = f(i - 1, sum1, sum2 - a[i]);
//     if (ans) {
//       dp[i][sum1][sum2] = 1;
//       return ans;
//     }
//   }
//   return false;
// }

bool f(int to, int sum) { // optimized using bitset
  for (int i = 1; i <= to; i++) {
    for (int x = 0; x <= sum; x++) {
      dp[i][x].reset();
    }
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= to; i++) {
    for (int x = 0; x <= sum; x++) {
      dp[i][x] = dp[i - 1][x];
      if (x - a[i] >= 0) dp[i][x] |= dp[i - 1][x - a[i]];
      dp[i][x] |= dp[i - 1][x] << a[i];
    }
  }
  return dp[to][sum][sum];
}

int cs = 0;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }
  cout << "Case " << ++cs << ":\n";
  for (int i = 1; i <= n; i++) {
    if (prefix[i] % 3 == 0) {
      cout << f(i, prefix[i] / 3) << '\n';
    }
    else {
      cout << 0 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}