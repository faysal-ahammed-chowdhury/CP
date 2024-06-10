#include <bits/stdc++.h>
using namespace std;

#define int long long
int fun(int n) {
  if (n < 10) return n;
  int ans = n / 10;
  int rem = (n % 10) + ans;
  return ans * 10 + fun(rem);
}

void solve() {
  int n; cin >> n;
  cout << fun(n) << '\n';
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