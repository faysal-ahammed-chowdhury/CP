#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 998244353;
int a[N], dp[N][5];
int n;

int f(int i, int last) {
  if (i > n) {
    // cout << last << '\n';
    return last == 3;
  }
  int &ans = dp[i][last];
  if (ans != -1) return ans;

  ans = 0;
  if (a[i] == 1) {
    ans += f(i + 1, last);
    ans %= mod;
    if (last == 0) {
      ans += f(i + 1, 1);
      ans %= mod;
    }
  }
  else if (a[i] == 2) {
    ans += f(i + 1, last);
    ans %= mod;
    if (last == 1 or last == 2) {
      ans += f(i + 1, 2);
      ans %= mod;
    }
  }
  else if (a[i] == 3) {
    ans += f(i + 1, last);
    ans %= mod;
    if (last == 2) {
      ans += f(i + 1, 3);
      ans %= mod;
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = -1;
    }
  }

  cout << f(1, 0) << '\n';
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