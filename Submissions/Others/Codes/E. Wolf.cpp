#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, q;
int a[N], pos[N];

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  while (q--) {
    int l, r, k; cin >> l >> r >> k;
    if (pos[k] < l or pos[k] > r) {
      cout << -1 << ' ';
      continue;
    }
    int choto_drkr = 0, boro_ok = 0, boro_drkr = 0, choto_ok = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] == k) break;
      // cout << l << ' ' << r << ' ' << mid << '\n';
      if (pos[k] < mid) {
        if (a[mid] < k) boro_drkr++;
        else boro_ok++;
        r = mid - 1;
      }
      else if (pos[k] > mid) {
        if (a[mid] > k) choto_drkr++;
        else choto_ok++;
        l = mid + 1;
      }
    }
    int ans = min(boro_drkr, choto_drkr) * 2;
    int extra = max(boro_drkr, choto_drkr) - min(boro_drkr, choto_drkr);
    ans += extra * 2;
    int need = abs(boro_drkr - choto_drkr);
    int ase = 1e9;
    if (boro_drkr > choto_drkr) ase = (n - k) - boro_ok - min(boro_drkr, choto_drkr);
    else if (choto_drkr > boro_drkr) ase = (k - 1) - choto_ok - min(boro_drkr, choto_drkr);
    // cout << boro_drkr << ' ' << choto_drkr << ' ' << choto_ok << ' ' << boro_ok << '\n';
    if (ase >= need) cout << ans << ' ';
    else cout << -1 << ' ';
  }
  cout << '\n';
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