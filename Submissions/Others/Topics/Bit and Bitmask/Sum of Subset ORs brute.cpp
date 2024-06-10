#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, mod = 1e9 + 7;
int n, a[N];

int power(int b, int p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

long long ans;
void fun(int i, int x) {
  if (i == n + 1) {
    ans += x;
    return;
  }
  fun(i + 1, x | a[i]);
  fun(i + 1, x);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ans = 0;
  fun(1, 0);
  cout << ans << '\n';

  return 0;
}