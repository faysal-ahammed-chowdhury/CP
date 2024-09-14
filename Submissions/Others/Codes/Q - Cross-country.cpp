#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

int f(int i, int j, vector<vector<int>> &dp) {
  if (i >= a.size() or j >= b.size()) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (a[i] == b[j]) {
    ans = max(ans, 1 + f(i + 1, j + 1, dp));
  }
  else {
    ans = max(ans, f(i + 1, j, dp));
    ans = max(ans, f(i, j + 1, dp));
  }
  return ans;
}

// int f(int i, int j) {
//   if (i >= a.size() or j >= b.size()) return 0;
//   // int &ans = dp[i][j];
//   // if (ans != -1) return ans;
//   int ans = f(i + 1, j);
//   ans = max(ans, f(i, j + 1));
//   if (a[i] == b[j]) {
//     ans = max(ans, 1 + f(i + 1, j + 1));
//   }
//   return ans;
// }

void solve() {
  a.clear();
  int x;
  while (cin >> x and x) {
    a.push_back(x);
  }
  int y;
  int ans = 0;
  while (cin >> y and y) {
    b.clear();
    b.push_back(y);
    while (cin >> x and x) {
      b.push_back(x);
    }
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    ans = max(ans, f(0, 0, dp));
  }
  cout << ans << '\n';
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