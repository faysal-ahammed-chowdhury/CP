#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
// const int N = 300005;
int n;
// ll dp[N][3];

// ll f(int i, int rem) {
//   if (i == n + 1) return rem == 0;
//   ll &ans = dp[i][rem];
//   if (ans != -1) return ans;
//   ans = 0;
//   for (int k = 0; k <= 9; k++) {
//     ans += f(i + 1, (rem + k) % 3);
//   }
//   return ans;
// }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  // memset(dp, -1, sizeof dp);
  // cout << f(1, 0) << '\n';
  for (int i = 1; i < n; i++) cout << 3;
  cout << 4 << '\n';

  return 0;
}