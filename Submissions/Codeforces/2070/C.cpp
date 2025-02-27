#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 9;
int n, k, a[N];
string s;

bool ok(int mx) {
  bool open = false;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= mx) continue;
    else {
      if (s[i] == 'R') {
        open = false;
      }
      else {
        if (open) continue;
        open = true;
        cnt++;
      }
    }
  }

  return cnt <= k;
}

void solve() {
  cin >> n >> k;
  cin >> s;
  s = '.' + s;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  int l = 0, r = mx, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
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