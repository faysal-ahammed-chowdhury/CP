#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, k; cin >> n >> k;
  int lim = sqrt(n + 1);
  vector<ll> v;
  for (int i = 1; i <= lim; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i != (n / i)) v.push_back(n / i);
    }
  }

  sort(v.begin(), v.end());
  if (k > (int)v.size()) {
    cout << -1 << '\n';
  }
  else {
    cout << v[k - 1] << '\n';
  }

  return 0;
}