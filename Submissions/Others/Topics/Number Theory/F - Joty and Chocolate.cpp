#include <bits/stdc++.h>
using namespace std;

long long lcm(int a, int b) {
  return (1LL * a * b) / __gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, p, q; cin >> n >> a >> b >> p >> q;
  int divisible_by_a = n / a;
  int divisible_by_b = n / b;
  long long l = lcm(a, b);
  int divisible_by_l = n / l;

  long long ans = (1LL * divisible_by_a * p) + (1LL * divisible_by_b * q) - (1LL * divisible_by_l * min(p, q));

  cout << ans << '\n';

  return 0;
}