#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y, z, n; cin >> x >> y >> z >> n;
  int total_class = x * y;
  int sixty_percent = ceil(total_class * 0.6);
  int rem = (x - z) * y;
  if (rem + n >= sixty_percent) {
    cout << "Yes\n";
    int need = sixty_percent - n;
    vector<int> v;
    while (need > 0) {
      v.push_back(min(need, y));
      need -= min(need, y);
    }
    for (int i = v.size(); i < (x - z); i++) {
      v.push_back(0);
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "No\n";
  }

  return 0;
}