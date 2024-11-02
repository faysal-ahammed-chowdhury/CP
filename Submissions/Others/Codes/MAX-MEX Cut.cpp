#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, a[N], dp[N];

int get(int i, int j) {
  return (a[i] + a[j] == 1 ? 2 : a[i] + a[j]);
}

int f(int i) {
  if (i == n + 1) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = a[i] + f(i + 1);
  if (i + 1 <= n) {
    ans = max(ans, get(i, i + 1) + f(i + 2));
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    int x = c - '0';
    if (x == a[i] and x == 1) a[i] = 0;
    else if (x == a[i] and x == 0) a[i] = 1;
    else a[i] = 2;
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  cout << f(1) << '\n';
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