#include <bits/stdc++.h>
using namespace std;
#define int  long long
using ll =  long long;
const int N = 30;
string s, str;
int sz;
int dp[N][2][2][2][N];

int f(int i, bool is_small, bool is_big, bool has_started, int last) {
  if (i == sz) return 0;
  int l = s[i] - '0', r = str[i] - '0';
  if (is_big) l = 0;
  if (is_small) r = 9;

  // if (i == 1) cout << last << ' ' << l << ' ' << r << '\n';

  int &ans = dp[i][is_small][is_big][has_started][last + 1];
  if (ans != -1) return ans;
  ans = 0;

  for (int x = l; x <= r; x++) {
    bool new_has_started = has_started | (x != 0);
    ans = max(ans, f(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, last));
    if (x > last and (x > 0 or (x == 0 and has_started))) {
      ans = max(ans, 1 + f(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, x));
    }
  }
  // cout << i << ' ' << last << ' ' << ans.first << '\n';
  return ans;
}

int print(int i, bool is_small, bool is_big, bool has_started, int last) {
  if (i == sz) return 1;
  int l = s[i] - '0', r = str[i] - '0';
  if (is_big) l = 0;
  if (is_small) r = 9;

  // if (i == 1) cout << last << ' ' << l << ' ' << r << '\n';

  int ans = f(i, is_small, is_big, has_started, last);

  int cnt = 0;
  for (int x = l; x <= r; x++) {
    bool new_has_started = has_started | (x != 0);
    int ans1 = f(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, last);
    if (ans == ans1) {
      cnt += print(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, last);
    }
    if (x > last and (x > 0 or (x == 0 and has_started))) {
      int ans2 = 1 + f(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, x);
      if (ans == ans2) {
        cnt += print(i + 1, (is_small | (x < r)), (is_big | (x > l)), new_has_started, x);
      }
    }
  }
  // cout << i << ' ' << last << ' ' << ans.first << '\n';
  return cnt;
}

void get(long long x, long long y) {
  int sz1, sz2;
  if (x >= 0) {
    s = "";
    while (x > 0) {
      char c = (x % 10) + '0';
      s += c;
      x /= 10;
    }
    reverse(s.begin(), s.end());
    sz1 = s.size();
  }
  if (y >= 0) {
    str = "";
    while (y > 0) {
      char c = (y % 10) + '0';
      str += c;
      y /= 10;
    }
    reverse(str.begin(), str.end());
    sz2 = str.size();
  }
  sz = max(sz1, sz2);
  if (sz1 < sz) {
    int k = sz - sz1;
    for (int i = 1; i <= k; i++) {
      s =  '0' + s;
    }
  }
  if (sz2 < sz) {
    int k = sz - sz2;
    for (int i = 1; i <= k; i++) {
      str =  '0' + str;
    }
  }
  // cout << s << ' ' << str << '\n';
}

int cs;
void solve() {
  ll n, m; cin >> n >> m;
  get(n, m);
  memset(dp, -1, sizeof(dp));
  auto ans = f(0, false, false, false, -1);
  // cout << s << '\n';
  cout << "Case " << ++cs << ": ";
  cout << ans << ' ' << print(0, false, false, false, -1) << '\n';
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