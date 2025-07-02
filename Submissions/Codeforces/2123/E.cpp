#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  int cnt = 0;
  int psum[n + 5];
  memset(psum, 0, sizeof psum);
  for (int mex = 0; mex <= n; mex++) {
    int mn = mp[mex];
    int mx = mn + cnt + (a + n + 1) - upper_bound(a + 1, a + n + 1, mex);
    // cout << mex << ' ' << mn << ' ' << mx << '\n';
    psum[mn]++;
    psum[mx + 1]--;

    if (mp[mex] == 0) break;
    cnt += mp[mex] - 1;
  }

  for (int i = 0; i <= n; i++) {
    if (i > 0) psum[i] += psum[i - 1];
    cout << psum[i] << ' ';
  }
  cout << '\n';
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