#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
bool dp[N][N][N];
short n, k, a[N];

// bool f(short i, short sum, short subsum) {
//   if (i > n) return sum == 0 and subsum == 0;
//   bool ans = f(i + 1, sum, subsum);
//   if (!ans and sum >= a[i]) {
//     ans |= f(i + 1, sum - a[i], subsum);
//     if (!ans and subsum >= a[i]) ans |= f(i + 1, sum - a[i], subsum - a[i]);
//   }
//   return dp[i][sum][subsum] = ans;
// }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dp[n + 1][0][0] = true;
  for (int i = n; i >= 1; i--) {
    for (int sum = 0; sum <= k; sum++) {
      for (int subsum = 0; subsum <= k; subsum++) {
        bool &ans = dp[i][sum][subsum];
        ans = dp[i + 1][sum][subsum];
        if (sum >= a[i]) {
          ans |= dp[i + 1][sum - a[i]][subsum];
          if (subsum >= a[i]) ans |= dp[i + 1][sum - a[i]][subsum - a[i]];
        }
      }
    }
  }

  vector<short> ans;
  ans.push_back(0);
  for (int i = 1; i <= k; i++) {
    if (dp[1][k][i]) ans.push_back(i);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}