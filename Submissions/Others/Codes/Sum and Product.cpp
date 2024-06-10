#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll s, p; cin >> s >> p;
  for (int i = 1; 1ll * i * i <= p; i++) {
    if (p % i == 0) {
      if (i + (p / i) == s) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}