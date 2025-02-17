#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int a[N], pref[N], suff[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1];
    if (a[i] >= 0) pref[i] += a[i];
  }

  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1];
    if (a[i] < 0) suff[i] += abs(a[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = pref[i] + suff[i];
    ans = max(ans, cur);
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