#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  swap(a[n], a[n - 1]);

  for (int i = 2; i + 1 <= n; i++) {
    if (a[i - 1] + a[i + 1] <= a[i]) {
      cout << "NO\n";
      return 0;
    }
  }

  if (a[n - 1] + a[1] <= a[n]) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}