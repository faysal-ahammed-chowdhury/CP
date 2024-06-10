#include <bits/stdc++.h>
using namespace std;

// void solve() {
//   int n, q; cin >> n >> q;
//   int a[n + 1], x[q + 1];
//   for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//   }
//   for (int i = 1; i <= q; i++) {
//     cin >> x[i];
//   }
//   int xr = (1 << x[1]);
//   for (int i = 2; i <= q; i++) {
//     if (x[i] < __builtin_ctz(xr)) {
//       xr |= (1 << x[i]);
//     }
//   }
//   xr = xr >> 1;
//   for (int i = 1; i <= n; i++) {
//     int val = 0;
//     for (int k = 0; k < 30; k++) {
//       if ((a[i] & (1 << k)) == 0) {
//         if ((xr & (1 << k)) != 0) {
//           val += (1 << k);
//         }
//       }
//       else {
//         break;
//       }
//     }
//     cout << a[i] + val << ' ';
//   }
//   cout << '\n';
// }

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1], x[31];
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int j = 1;
  for (int i = 1; i <= q; i++) {
    int val; cin >> val;
    if (se.find(val) == se.end()) {
      x[j] = val;
      se.insert(val);
      j++;
    }
  }

  for (int i = 1; i < j; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j] % (1 << x[i]) == 0) {
        a[j] += (1 << (x[i] - 1));
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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