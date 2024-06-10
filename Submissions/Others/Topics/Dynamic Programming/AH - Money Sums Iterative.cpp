#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e5 + 9;
int n, a[N];
bool dp[N][MAX_VAL];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int sum = 0; sum < MAX_VAL; sum++) {
      if (i == n + 1) {
        if (sum == 0) dp[i][sum] = true;
        else dp[i][sum] = false;
      }
      else {
        bool &ans = dp[i][sum];
        ans = false;
        if (sum >= a[i]) ans = dp[i + 1][sum - a[i]];
        if (ans) continue;
        ans = dp[i + 1][sum];
      }
    }
  }

  vector<int> v;
  for (int x = 1; x < MAX_VAL; x++) {
    if (dp[1][x]) {
      v.push_back(x);
    }
  }

  cout << v.size() << '\n';
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}