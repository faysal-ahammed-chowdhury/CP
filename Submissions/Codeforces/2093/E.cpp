#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int a[N];
int n, k;

bool ok(int mex) {
  int cnt = 0;
  set<int> se;
  for (int i = 0; i <= mex + 2; i++) {
    se.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if (*se.begin() >= mex + 2) {
      cnt++;
      for (int j = 0; j <= mex; j++) {
        se.insert(j);
      }
    }
    if (a[i] < mex) se.erase(a[i]);
    if (*se.begin() >= mex) {
      cnt++;
      for (int j = 0; j <= mex + 2; j++) {
        se.insert(j);
      }
    }
  }
  // cout << cnt << '\n';
  return cnt >= k;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << ans << '\n';
  // cout << ok(1) << '\n';
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