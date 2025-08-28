#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20;
string s;
int sz;
ll k;
ll dp1[N][2][2], dp2[N][2];

ll f2(int i, bool is_small) {
  if (i == sz) return 1;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;

  ll &ans = dp2[i][is_small];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    ans += f2(i + 1, (is_small | (x < r)));
  }
  return ans;
}

ll f(int i, bool is_small, bool has_started) {
  if (i == sz) return 0;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;

  ll &ans = dp1[i][is_small][has_started];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    bool new_has_started = has_started | (x != 0);
    ans += f(i + 1, (is_small | (x < r)), new_has_started);
    if (new_has_started) {
      ans += f2(i + 1, (is_small | (x < r)));
    }
  }
  return ans;
}

void get(long long x) {
  if (x < 0) return;
  s = "";
  while (x > 0) {
    char c = (x % 10) + '0';
    s += c;
    x /= 10;
  }
  reverse(s.begin(), s.end());
  sz = s.size();
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
}

bool ok(ll n) {
  get(n);
  ll cnt = f(0, false, false);
  // cout << cnt << '\n';
  return cnt >= k;
}

void solve() {
  cin >> k;
  ll l = 1, r = 1e18, ans = -1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  get(ans - 1);
  ll cnt = f(0, false, false);
  ll need = k - cnt;
  assert(need >= 1);

  string s = to_string(ans);
  cout << s[need - 1] << '\n';
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