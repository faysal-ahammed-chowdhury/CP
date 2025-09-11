#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

int32_t main() {

  int n; cin >> n;
  cout << n << endl;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    cout << i << ' ' << i << endl;
    tot += i * 500;
  }

  int w; cin >> w;

  cout << "! " << w - tot << endl;

  return 0;
}