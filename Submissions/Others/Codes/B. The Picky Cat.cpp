#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  int val = a[1];

  int boro1 = 0, choto1 = 0;
  for (int i = 1; i <= n; i++) {
    boro1 += a[i] > val;
    choto1 += a[i] < val;
    a[i] = -a[i];
  }
  val = a[1];

  int boro2 = 0, choto2 = 0;
  for (int i = 1; i <= n; i++) {
    boro2 += a[i] > val;
    choto2 += a[i] < val;
  }

  int mid = (n + 1) / 2;

  if (boro1 >= choto1) cout << "YES\n";
  else if (choto2 >= boro2) cout << "YES\n";
  else if (choto2 + 1 == mid or choto1 + 1 == mid) cout << "YES\n";
  else cout << "NO\n";
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