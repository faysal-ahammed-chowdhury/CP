#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ms.insert(-x);
  }

  int b[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + 1 + m);
  int l = 1, r = m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int first = *ms.begin();
    int last = *(--ms.end());
    first *= -1;
    last *= -1;
    int x = abs(first - b[l]);
    int y = abs(last - b[r]);

    if (x > y) {
      ms.erase(ms.begin());
      ans += x;
      l++;
    }
    else {
      ms.erase(--ms.end());
      ans += y;
      r--;
    }
  }

  cout << ans << '\n';
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