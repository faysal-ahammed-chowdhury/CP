#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];
ll pref[N], suff[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + max(0, a[i] - a[i + 1]);
  }
  suff[n + 1] = 0;
   for (int i = n; i > 1; i--) {
    suff[i] = suff[i + 1] + max(0, a[i] - a[i - 1]);
  }

  while (q--) {
    int l, r; cin >> l >> r;
    if (l == r) cout << 0 << '\n';
    else if (l < r) {
      r--;
      cout << pref[r] - pref[l - 1] << '\n';
    }
    else {
      r++;
      cout << suff[r] - suff[l + 1] << '\n';
    }
  }

  return 0;
}