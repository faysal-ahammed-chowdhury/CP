#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int a[N];
int n, k;

bool ok(int mex) {
  int cnt = 0;
  bool missing[mex + 5];
  for (int i = 0; i <= mex; i++) {
    missing[i] = true;
  }
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (x == mex) {
      cnt++;
      x = 0;
      for (int j = 0; j <= mex; j++) {
        missing[j] = true;
      }
    }
    if (a[i] < mex) {
      if (missing[a[i]]) {
        x++;
      }
      // cout << i  << ' ' << x << "here\n";
      missing[a[i]] = false;
    }
    if (x == mex) {
      cnt++;
      x = 0;
      for (int j = 0; j <= mex; j++) {
        missing[j] = true;
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
  while (t--) {
    solve();
  }

  return 0;
}