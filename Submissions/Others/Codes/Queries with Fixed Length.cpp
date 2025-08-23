#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  while (q--) {
    int k; cin >> k;
    deque<int> dq;
    for (int i = 1; i <= k; i++) {
      while (!dq.empty() and a[dq.back()] <= a[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    int ans = a[dq.front()];
    for (int i = k + 1; i <= n; i++) {
      while (!dq.empty() and i - dq.front() + 1 > k) {
        dq.pop_front();
      }

      while (!dq.empty() and a[dq.back()] <= a[i]) {
        dq.pop_back();
      }
      dq.push_back(i);

      ans = min(ans, a[dq.front()]);
    }

    cout << ans << '\n';
  }

  return 0;
}