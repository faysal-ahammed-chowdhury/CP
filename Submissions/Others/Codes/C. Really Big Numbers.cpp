#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, s;

bool ok(ll x) {
  int sum = 0;
  ll tmp = x;
  while(tmp > 0) {
    sum += tmp % 10;
    tmp /= 10;
  }
  return (x - sum) >= s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  ll l = 10, r = n, ans = -1;
  while(l <= r) {
    ll mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << (ans == -1 ? 0 : n - ans + 1) << '\n';

  return 0;
}