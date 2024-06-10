#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += x;
  }
  long long sq = sqrtl(sum);
  while (sq * sq < sum) sq++;
  while (sq * sq > sum) sq--;

  if (sq * sq == sum) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}