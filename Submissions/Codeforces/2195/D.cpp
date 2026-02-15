#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 3e5 + 9;
int n, f[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }

  int sum = (f[1] + f[n]) / (n - 1);
  int tot = 0;
  int tmp = 0;
  for (int i = 2; i <= n; i++) {
    int x = ((f[i] - f[i - 1] + sum) - (2 * tot)) / 2;
    cout << x << ' ';
    tot += x;
    tmp += x * (i - 2);
  }
  cout << (f[1] - tmp) / (n - 1) << '\n';
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