#include <bits/stdc++.h>
using namespace std;

#define int long long
const int SZ = 35;
string s;
int dp1[SZ][2][2], dp2[SZ][2];

int fun2(int i, bool is_small) {
  if (i == SZ) return 1;
  int &ans = dp2[i][is_small];
  if (ans != -1) return ans;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 1;
  ans = fun2(i + 1, (is_small | (r == 1)));
  if (r == 1) {
    ans += fun2(i + 1, is_small);
  }
  return ans;
}

int fun(int i, bool is_small, bool is_last_one) {
  if (i == SZ) return 0;
  int &ans = dp1[i][is_small][is_last_one];
  if (ans != -1) return ans;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 1;
  ans = fun(i + 1, (is_small | (r == 1)), false);
  if (r == 1) {
    ans += fun(i + 1, is_small, true);
    if (is_last_one) {
      ans += fun2(i + 1, is_small);
    }
  }
  return ans;
}

int cs;
void solve() {
  int n; cin >> n;
  bitset<SZ> bs(n);
  s = bs.to_string();
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  cout << "Case " << ++cs << ": ";
  cout << fun(0, false, false) << '\n';
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