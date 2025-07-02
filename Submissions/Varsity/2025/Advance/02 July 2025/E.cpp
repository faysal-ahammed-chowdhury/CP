#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a, b; cin >> a >> b;
  for (int i = 2; i <= n; i++) {
    int x, y; cin >> x >> y;
    
    int xx = (a / x) + bool(a % x);
    int yy = (b / y) + bool(b % y);

    int need = max(xx, yy);

    // cout << need << '\n';

    a = x * need;
    b = y * need;

    // cout << a << ' ' << b << '\n';
  }

  cout << a + b << '\n';

  return 0;
}