#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 105, inf = 1e9;
int m, dp[N][(int)(1e5 + 9)];
string s;
int sz;

int f(int i, int cur) {
  if (i >= sz) return cur == 0 ? 0 : -inf;
  int &ans = dp[i][cur];
  if (ans != -1) return ans;
  ans = -inf;
  for (int x = 0; x <= 9; x++) {
    if (i == 0 and x == 0) continue;
    int tmp = (cur * 10) % m;
    tmp += x;
    tmp %= m;
    int y = (s[i] - '0') == x;
    ans = max(ans, y + f(i + 1, tmp));
  }
  return ans;
}

void print(int i, int cur) {
  if (i >= sz) return;
  int ans = f(i, cur);
  // cout << i << ' ' << cur << '\n';

  for (int x = 0; x <= 9; x++) {
    if (i == 0 and x == 0) continue;
    int tmp = (cur * 10) % m;
    tmp += x;
    tmp %= m;
    int y = (s[i] - '0') == x;
    int here = y + f(i + 1, tmp);

    if (here == ans) {
      cout << x;
      print(i + 1, tmp);
      break;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  sz = s.size();
  cin >> m;

  memset(dp, -1, sizeof dp);
  // cout << f(0, 0) << '\n';
  print(0, 0);

  return 0;
}