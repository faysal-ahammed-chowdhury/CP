#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    cout << "Case " << ++cs << ": ";
    cout << 1LL * (n / 2) * m  << '\n';
  }

  return 0;
}