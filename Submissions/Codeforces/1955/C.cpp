#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, ans = 0;
  bool last = true;
  while (l < r and k >= 1) {
    if (last) {
      if (a[l] <= a[r]) {
        if (a[l] == 1) {
          l++;
          k--;
          ans++;
        }
        else {
          int need = (a[l] - 1) * 2 + 1;
          if (need > k) break;
          ans++;
          k -= need;
          l++;
          a[r] -= (need / 2);
          if (a[r] <= 0) {
            ans++;
            r--;
          }
        }
        last = false;
      }
      else {
        if (a[r] == 1) {
          a[l]--;
          k--;
          if (k <= 0) break;
          r--;
          k--;
          ans++;
        }
        else {
          k--;
          a[l]--;
          int need = (a[r] - 1) * 2 + 1;
          if (need > k) break;
          ans++;
          k -= need;
          r--;
          a[l] -= (need / 2);
          if (a[l] <= 0) {
            ans++;
            l++;
          }
        }
        last = true;
      }
    }
    else {
      a[r]--;
      k--;
      last = true;
      if (a[r] == 0) {
        ans++;
        r--;
      }
    }
  }

  if (l == r) {
    if (a[l] <= k) ans++;
  }
  cout << ans << '\n';
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