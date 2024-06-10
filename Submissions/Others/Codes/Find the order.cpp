#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  multiset<int, greater<int>> ms;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ms.insert(x);
  }

  int a[n + 1];
  for (int i = 2; i <= n; i += 2) {
    a[i] = *ms.begin();
    ms.erase(ms.begin());
  }
  for (int i = 1; i <= n; i += 2) {
    a[i] = *ms.begin();
    ms.erase(ms.begin());
  }

  for (int i = 2; i <= n; i += 2) {
    if (a[i - 1] >= a[i] or (i + 1 <= n and a[i + 1] >= a[i])) {
      cout << -1 << '\n';
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}