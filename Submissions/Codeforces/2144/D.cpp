#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int N = 4e5 + 9, inf = 1e18;
int freq[N], pref[N], a[N], n, y, ans[N];

void solve() {
  memset(freq, 0, sizeof freq);
  memset(pref, 0, sizeof pref);
  memset(ans, 0, sizeof ans);

  cin >> n >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] + freq[i];
  }

  for (int val = 1; val < N; val++) {
    int mx_x = 2;
    for (int x = 2; (val * x) < N; x++, mx_x++) {
      int r = val * x;
      int l = (val - 1) * x + 1;
      int cnt = pref[r] - pref[l - 1];

      ans[x] += cnt * val;
      ans[x] -= max(0ll, cnt - freq[val]) * y;
    }
    if (val * mx_x >= N) {
      int r = min(N - 1, val * mx_x);
      int l = (val - 1) * mx_x + 1;

      if (l <= r) {
        int cnt = pref[r] - pref[l - 1];
        ans[mx_x] += cnt * val;
        ans[mx_x] -= max(0ll, cnt - freq[val]) * y;
      }
    }
  }

  int tmp = -inf;
  for (int x = 2; x < N; x++) {
    tmp = max(tmp, ans[x]);
  }

  cout << tmp << '\n';
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