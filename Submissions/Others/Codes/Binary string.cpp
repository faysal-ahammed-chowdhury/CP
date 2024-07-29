#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, x;
string s;
pair<int, int> a[N];
bitset<N> dp[N];

// bool f(int i, int x, int k) {
//   if (x < 0) return 0;
//   if (i == k) return x == 0;
//   if (vis[i][x]) return dp[i][x];
//   vis[i][x] = true;
//   bool ans = f(i + 1, x - a[i].first, k);
//   ans |= f(i + 1, x - a[i].second, k);
//   return dp[i][x] = ans;
// }

bool f(int k) {
  dp[k][x] = 1;
  for (int i = k - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] >> a[i].first;
    dp[i] |= dp[i + 1] >> a[i].second;
  }
  return dp[0][0];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("binary.in", "r", stdin);

  cin >> n >> x;
  cin >> s;
  for (int k = 1; k <= n; k++) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) {
      a[i % k].first += s[i] == '0';
      a[i % k].second += s[i] == '1';
    }
    if (f(k)) {
      cout << k << '\n';
      return 0;
    }
  }

  return 0;
}
// https://vjudge.net/problem/gym-103158i