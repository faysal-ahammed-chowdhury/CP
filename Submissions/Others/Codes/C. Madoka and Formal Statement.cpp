#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, a[N], b[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  bool need_help = false;
  int koto = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > b[i]) {
      cout << "NO\n";
      return;
    }

    int me = b[i];
    if (need_help) {
      me = max(me, koto);
    }

    if (me > b[i]) {
      cout << "NO\n";
      return;
    }
    if (me == a[i]) {
      need_help = false;
      continue;
    }

    need_help = true;
    koto = me - 1;
  }

  if (need_help) {
    if (b[1] >= koto) cout << "YES\n";
    else cout << "NO\n"; 
    return;
  }

  cout << "YES\n";
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