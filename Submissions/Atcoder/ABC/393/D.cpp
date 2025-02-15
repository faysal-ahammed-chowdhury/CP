#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9;
const ll inf = 1e18;
int n, pref0_left[N], pref0_right[N];
int pref1_left[N], pref1_right[N];
ll pref1[N], pref2[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  string s; cin >> s;
  s = '.' + s;

  for (int i = 1; i <= n; i++) {
    pref0_left[i] = pref0_left[i - 1] + (s[i] == '0');
    pref1_left[i] = pref1_left[i - 1] + (s[i] == '1');
  }

  pref0_right[n + 1] = 0;
  pref1_right[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    pref0_right[i] = pref0_right[i + 1] + (s[i] == '0');
    pref1_right[i] = pref1_right[i + 1] + (s[i] == '1');
  }

  for (int i = 1; i <= n; i++) {
    pref1[i] = pref1[i - 1] + (s[i] == '1' ? pref0_right[i] : 0);
  }
  pref2[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    pref2[i] = pref2[i + 1] + (s[i] == '1' ? pref0_left[i] : 0);
  }

  ll ans = inf;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') continue;
    ll l = pref1[i - 1] - (1ll * pref1_left[i - 1] * pref0_right[i + 1]);
    ll r = pref2[i + 1] - (1ll * pref1_right[i + 1] * pref0_left[i - 1]);
    ll cur = l + r;
    ans = min(ans, cur);
  }
  cout << ans << '\n';

  return 0;
}