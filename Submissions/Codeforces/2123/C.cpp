#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int pref[n + 1], suff[n + 2];
  pref[0] = inf;
  for (int i = 1; i <= n; i++) {
    pref[i] = min(pref[i - 1], a[i]);
  }
  pref[0] = pref[1];
  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff[i] = max(suff[i + 1], a[i]);
  }
  suff[n + 1] = suff[n];
  string ans;
  for (int i = 1; i <= n; i++) {
    int mn = pref[i - 1];
    int mx = suff[i];
    if (mx == a[i]) {
      ans.push_back('1');
      continue;
    }
    mn = pref[i];
    mx = suff[i + 1];
    if (mn == a[i]) {
      ans.push_back('1');
      continue;
    }
    ans.push_back('0');
  }

  cout << ans << '\n';
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