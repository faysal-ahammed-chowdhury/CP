#include <bits/stdc++.h>
using namespace std;

const int N = 12, inf = 1e6;
string s1, s2;
int sz1, sz2;
int dp[N][2][2];

int f(int i, bool is_small, bool is_big) {
  if (i == sz1) return 0;
  int l = s1[i] - '0', r = s2[i] - '0';
  if (is_small) r = 9;
  if (is_big) l = 0;

  int &ans = dp[i][is_small][is_big];
  if (ans != -1) return ans;
  ans = inf;
  for (int x = l; x <= r; x++) {
    int y = ((s1[i] - '0') == x) + ((s2[i] - '0') == x);
    ans = min(ans, y + f(i + 1, (is_small | (x < r)), (is_big | (x > l))));
  }
  return ans;
}

void get(int x, int y) {
  s1 = "";
  while (x > 0) {
    char c = (x % 10) + '0';
    s1 += c;
    x /= 10;
  }
  reverse(s1.begin(), s1.end());
  sz1 = s1.size();

  s2 = "";
  while (y > 0) {
    char c = (y % 10) + '0';
    s2 += c;
    y /= 10;
  }
  reverse(s2.begin(), s2.end());
  sz2 = s2.size();

  for (int i = 0; i <= sz1; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }
}

int cs;
void solve() {
  int l, r; cin >> l >> r;
  get(l, r);

  // cout << s1 << ' ' << s2 << '\n';
  cout << f(0, false, false) << '\n';
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