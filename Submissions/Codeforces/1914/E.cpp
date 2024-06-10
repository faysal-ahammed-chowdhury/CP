#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 7, inf = 1e18;
int n, a[N], b[N];
vector<bool> done(N, false);

int fun(int cur, vector<bool> &done) {
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!done[i]) {
      ok = false;
      break;
    }
  }
  if (ok) return 0;
  if (cur & 1) {
    int ans = inf;
    for (int i = 1; i <= n; i++) {
      if (!done[i]) {
        done[i] = true;
        ans = min(ans, -(b[i] - 1) + fun(0, done));
        done[i] = false;
      }
    }
    return ans;
  }
  else {
    int ans = -inf;
    for (int i = 1; i <= n; i++) {
      if (!done[i]) {
        done[i] = true;
        ans = max(ans, a[i] - 1 + fun(1, done));
        done[i] = false;
      }
    }
    return ans;
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i <= n; i++) {
    done[i] = false;
  }
  cout << fun(0, done) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}