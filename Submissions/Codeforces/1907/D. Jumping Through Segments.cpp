#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, x[N], y[N];

bool ok(int k) {
  int range1 = 0, range2 = 0;
  for (int i = 1; i <= n; i++) {
    if (x[i] >= range1 and y[i] <= range2) {
      range1 = x[i], range2 = y[i];
    }
    else if (range1 >= x[i] and range2 <= y[i]) {
      range1 = max(range1 - k, x[i]);
      range2 = min(range2 + k, y[i]);
    }
    else if (x[i] >= range2) {
      int mx = range2 + k;
      if (mx < x[i]) return false;
      range1 = x[i], range2 = min(y[i], mx);
    }
    else if (y[i] <= range1) {
      int mx = range1 - k;
      if (mx > y[i]) return false;
      range1 = max(x[i], mx), range2 = y[i];
    }
    else if (x[i] >= range1 and x[i] <= range2) {
      int mx = range2 + k;
      range1 = x[i], range2 = min(y[i], mx);
    }
    else if (y[i] >= range1 and y[i] <= range2) {
      int mx = range1 - k;
      range1 = max(x[i], mx), range2 = y[i];
    }
    else return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  int l = 0, r = 1e10, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}