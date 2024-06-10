#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  freopen("easy.in", "r", stdin);
  freopen("easy.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  deque<int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    deque<int> dq;
    for (int i = 1; i <= x; i++) {
      int y; cin >> y;
      dq.push_back(y);
    }
    a[i] = dq;
  }

  int tot = 0, cnt = 0;

  while (cnt < k) {
    for (int i = 1; i <= n; i++) {
      if (a[i].empty()) {
        tot += 50;
        cnt++;
        if (cnt == k) break;
        continue;
      }
      int x = a[i].front();
      a[i].pop_front();
      if (x >= tot) {
        tot += x;
        cnt++;
        if (cnt == k) break;
      }
    }
  }

  cout << tot << '\n';

  return 0;
}