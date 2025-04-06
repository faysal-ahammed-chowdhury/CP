#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;

bool ok(int mex) {
  int a[n + 1];
  set<int> se;
  for (int i = 1, j = 0; i <= n; i++, j++) {
    if (mex == 0) j = 0;
    else j %= max(k, mex);
    a[i] = j;
    // cout << a[i] << ' ';
    se.insert(i - 1);
  }
  se.insert(n);
  se.insert(n + 1);
  // cout << '\n';


  set<int> se2;
  for (int i = 1, j = max(k, mex) - 1; i <= k; i++, j--) {
    se2.insert(j);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt < (m * k) and se2.find(a[i]) != se2.end()) {
      cnt++;
      continue;
    }
    se.erase(a[i]);
  }
  int here = *se.begin();
  // cout << mex << '\n';
  return here >= mex;
}

void solve() {
  cin >> n >> m >> k;
  int l = 1, r = n, mex = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      mex = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  // cout << mex << '\n';
  // cout << ok(0) << '\n';
  for (int i = 1, j = 0; i <= n; i++, j++) {
    j %= max(k, mex);
    cout << j << ' ';
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