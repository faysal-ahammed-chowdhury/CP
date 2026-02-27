#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, l, r; cin >> n >> l >> r;
  int a[n + 1];
  l++;
  int mn = 1e9, idx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i >= l and i <= r) {
      mn = min(mn, a[i]);
      if (mn == a[i]) idx = i;
    }
  }

  vector<int> mid;
  for (int i = idx; i <= r; i++) {
    mid.push_back(a[i]);
  }
  for (int i = l; i < idx; i++) {
    mid.push_back(a[i]);
  }

  for (int i = 1; i < l; i++) {
    if (a[i] > mn) {
      for (int j = 1; j < i; j++) {
        cout << a[j] << ' ';
      }
      for (auto x : mid) {
        cout << x << ' ';
      }
      for (int j = i; j < l; j++) {
        cout << a[j] << ' ';
      }
      for (int j = r + 1; j <= n; j++) {
        cout << a[j] << ' ';
      }
      cout << '\n';

      return;
    }
  }


  for (int i = 1; i < l; i++) {
    cout << a[i] << ' ';
  }
  for (int i = r + 1; i <= n; i++) {
    if (a[i] > mn) {
      for (int j = r + 1; j < i; j++) {
        cout << a[j] << ' ';
      }
      for (auto x : mid) {
        cout << x << ' ';
      }
      for (int j = i; j <= n; j++) {
        cout << a[j] << ' ';
      }
      cout << '\n';
      return;
    }
  }
  for (int j = r + 1; j <= n; j++) {
    cout << a[j] << ' ';
  }
  for (auto x : mid) {
    cout << x << ' ';
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