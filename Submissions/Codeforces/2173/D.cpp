#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e18;
vector<int> v;
string s;
int n, dp[40][45][2][2];

int f(int i, int rem, bool last_taken, bool must) {
  if (i >= n) return rem;
  int &ans = dp[i][rem][last_taken][must];
  if (ans != -1) return ans;
  ans = -inf;
  if (i % 2 == 0) { // zeros
    if (v[i] <= rem) ans = max(ans, v[i] + f(i + 1, rem - v[i], true, !last_taken));
    ans = max(ans, f(i + 1, rem, false, false));
  }
  else { // one
    if (rem > 0) ans = max(ans, v[i] + f(i + 1, rem - 1, true, false));
    if (last_taken and !must) ans = max(ans, v[i] + f(i + 1, rem, true, false));
    if (!must) {
      ans = max(ans, f(i + 1, rem, false, false));
    }
  }
  // cout << i << ' ' << rem << ' ' << last_taken << ' ' << must << ' ' << ans << '\n';
  return ans;
}

void solve() {
  v.clear();
  s.clear();
  int x, k; cin >> x >> k;
  if (k >= 40) {
    int ans = __builtin_popcountll(x) + k - 1;
    cout << ans << '\n';
    return;
  }

  bitset<30> bs(x);
  s = bs.to_string();
  s = '.' + s;
  int cnt = 1;
  if (s[1] == '1') v.push_back(0);
  for (int i = 2; i < s.size(); i++) {
    if (s[i] == s[i - 1]) cnt++;
    else {
      v.push_back(cnt);
      cnt = 1;
    }
  }
  v.push_back(cnt);
  n = v.size();

  // for (auto x : v) {
  //   cout << x << ' ';
  // }
  // cout << '\n';

  memset(dp, -1, sizeof dp);
  cout << f(0, k, false, false) << '\n';
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