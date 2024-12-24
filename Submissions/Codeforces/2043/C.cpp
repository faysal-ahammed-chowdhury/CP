#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const ll inf = 1e15;
const int N = 2e5 + 9;
int a[N], b[N];
ll psum1[N], psum2[N];

void solve() {
  int n; cin >> n;
  int idx = -1, val = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = -a[i];

    if (a[i] == 0 or a[i] > 1 or a[i] < -1) {
      idx = i;
      val = a[i];
    }
  }

  if (idx != -1) {
    a[idx] = 0;
    b[idx] = 0;
  }

  for (int i = 1; i <= n; i++) {
    psum1[i] = psum1[i - 1] + a[i];
    psum2[i] = psum2[i - 1] + b[i];
  }

  set<int> se;
  se.insert(0);

  ll low1 = 0, low2 = 0;
  ll mx = -inf, mn = -inf;
  for (int i = 1; i < idx; i++) {
    mx = max(mx, psum1[i] - low1);
    low1 = min(low1, psum1[i]);

    mn = max(mn, psum2[i] - low2);
    low2 = min(low2, psum2[i]);
  }
  for (int i = -mn; i <= mx; i++) {
    se.insert(i);
  }

  if (idx != -1 and val == 0) {
    low1 = 0, low2 = 0;
    mx = -inf, mn = -inf;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, psum1[i] - low1);
      low1 = min(low1, psum1[i]);

      mn = max(mn, psum2[i] - low2);
      low2 = min(low2, psum2[i]);
    }
    for (int i = -mn; i <= mx; i++) {
      se.insert(i);
    }
  }

  psum1[idx] = 0;
  psum2[idx] = 0;
  for (int i = idx + 1; i <= n; i++) {
    psum1[i] = psum1[i - 1] + a[i];
    psum2[i] = psum2[i - 1] + b[i];
  }

  low1 = 0, low2 = 0;
  mx = -inf, mn = -inf;
  for (int i = idx + 1; i <= n; i++) {
    mx = max(mx, psum1[i] - low1);
    low1 = min(low1, psum1[i]);

    mn = max(mn, psum2[i] - low2);
    low2 = min(low2, psum2[i]);
  }
  for (int i = -mn; i <= mx; i++) {
    se.insert(i);
  }

  if (idx == -1 or val == 0) {
    cout << se.size() << '\n';
    for (auto x : se) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  a[idx] = val;
  b[idx] = -val;

  for (int i = 1; i <= n; i++) {
    psum1[i] = psum1[i - 1] + a[i];
    psum2[i] = psum2[i - 1] + b[i];
  }

  low1 = 0, low2 = 0;
  mx = -inf, mn = -inf;
  for (int i = 1; i < idx; i++) {
    low1 = min(low1, psum1[i]);
    low2 = min(low2, psum2[i]);
  }

  for (int i = idx; i <= n; i++) {
    mx = max(mx, psum1[i] - low1);
    mn = max(mn, psum2[i] - low2);
  }

  // cout << -mn << ' ' << mx << '\n';

  for (int i = -mn; i <= mx; i++) {
    se.insert(i);
  }

  cout << se.size() << '\n';
  for (auto x : se) {
    cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}