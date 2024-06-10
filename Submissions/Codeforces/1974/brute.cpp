#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, x;
int a[N], b[N];

int f(int i, int money) {
  if (i == n + 1) return 0;
  int ans = f(i + 1, money + x);
  if (money >= a[i]) {
    ans = max(ans, b[i] + f(i + 1, money - a[i] + x));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  cout << f(1, 0) << '\n';

  return 0;
}