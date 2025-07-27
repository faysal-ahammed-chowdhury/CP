#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

const int N = 300000 + 9;
int a[N], pref[N];
int n, k, lft, rght;

bool ok(int med) {
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (a[i] < med ? -1 : 1);
  }

  int mn = 0, idx = 0;
  for (int i = k, j = 1; i <= n; i++, j++) {
    if (pref[i] - mn >= 0) {
      lft = idx + 1;
      rght = i;
      return true;
    }
    // mn = min(mn, pref[j]);
    if (mn > pref[j]) {
      mn = pref[j];
      idx = j;
    }
  }

  return false;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  ok(ans);
  cout << ans << ' ' << lft << ' ' << rght << '\n';
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