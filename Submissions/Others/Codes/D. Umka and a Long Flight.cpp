#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 45;
ll fibo[N];

void prec() {
  fibo[0] = fibo[1] = 1;
  for (int i = 2; i < N; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
}

void solve() {
  int n, x, y; cin >> n >> x >> y;
  bool ok1 = false, ok2 = false;

  ll sum1 = 0, sum2 = 0;
  if (sum1 + 1 == y) ok1 = true;
  if (sum2 + 1 == x) ok2 = true;

  if (n & 1) {
    for (int i = n; i >= 1; i -= 2) {
      if (sum1 + fibo[i] < y) {
        sum1 += fibo[i];
      }
      if (i - 1 >= 2) {
        if (sum2 + fibo[i - 1] < x) {
          sum2 += fibo[i - 1];
        }
      }

      // cout << sum1 << ' ' << sum2 << '\n';

      if (sum1 + 1 == y) ok1 = true;
      if (sum2 + 1 == x) ok2 = true;
    }
  }
  else {
    for (int i = n; i >= 2; i -= 2) {
      if (sum1 + fibo[i] < y) {
        sum1 += fibo[i];
      }
      if (i - 1 >= 1) {
        if (sum2 + fibo[i - 1] < x) {
          sum2 += fibo[i - 1];
        }
      }

      // cout << sum1 << ' ' << sum2 << '\n';

      if (sum1 + 1 == y) ok1 = true;
      if (sum2 + 1 == x) ok2 = true;
    }
  }

  if (ok1 and ok2) cout << "Yes\n";
  else cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}