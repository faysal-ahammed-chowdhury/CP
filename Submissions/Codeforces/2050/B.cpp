#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n != 0) {
    cout << "No\n";
    return;
  }

  int avg = sum / n;
  for (int i = 1; i <= n; i++) {
    if (a[i] > avg) {
      if (i + 2 <= n) {
        int x = abs(a[i] - avg);
        a[i] -= x;
        a[i + 2] += x;
      }
      else {
        cout << "No\n";
        return;
      }
    }
    else if (a[i] < avg) {
      if (i + 2 <= n) {
        int x = abs(a[i] - avg);
        a[i] += x;
        a[i + 2] -= x;
      }
      else {
        cout << "No\n";
        return;
      }
    }
  }

  bool ok = true;
  for (int i = 2; i <= n; i++) {
    ok &= a[i] == a[i - 1] and a[i] == avg;
  }
  if (ok) cout << "Yes\n";
  else cout << "No\n";
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