#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;
  ll ans1 = 1ll * a * c;
  ll ans2 = 1ll * a * d;
  ll ans3 = 1ll * b * c;
  ll ans4 = 1ll * b * d;
  cout << max({ans1, ans2, ans3, ans4}) << '\n';

  return 0;
} 