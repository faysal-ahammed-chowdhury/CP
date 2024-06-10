#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int ans[N];

int sod(int x) {
  int sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

void solve() {
  int n; cin >> n;
  cout << ans[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i < N; i++) {
    ans[i] = ans[i - 1] + sod(i);
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}