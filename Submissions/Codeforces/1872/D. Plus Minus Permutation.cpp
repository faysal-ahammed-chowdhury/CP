#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

long long sum(int n) {
  return (1ll * n * (n + 1)) / 2;
}

long long lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

void solve() {
  int n, x, y; cin >> n >> x >> y;
  int add = n / x;
  int remove = n / y;
  long long l = lcm(x, y);
  int common = n / l;
  long long ans = sum(n) - sum (n - add + common);
  int rem = remove - common;
  ans -= sum(rem);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}