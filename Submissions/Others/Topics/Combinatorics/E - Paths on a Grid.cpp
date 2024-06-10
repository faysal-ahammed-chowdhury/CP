#include <iostream>
using namespace std;

#define ll long long

ll nCr(ll n, ll r) {
  r = min(r, n - r);
  ll ans = 1;
  for (int i = 1; i <= r; i++, n--) {
    ans *= n;
    ans /= i;
  }
  return ans;
}

int main() {
  ll n, m;
  while (cin >> n >> m and !(n == 0 and m == 0)) {
    cout << nCr(n + m, m) << '\n';
  }

  return 0;
}