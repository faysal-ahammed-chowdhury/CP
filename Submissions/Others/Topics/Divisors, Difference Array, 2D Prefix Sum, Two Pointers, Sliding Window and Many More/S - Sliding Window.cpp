#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> max_values, min_values;
  multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    ms.insert(a[i]);
    if (i >= k) {
      min_values.push_back(*ms.begin());
      max_values.push_back(*(--ms.end()));
      ms.erase(ms.find(a[i - k + 1]));
    }
  }

  for (auto x: min_values) cout << x << ' '; cout << '\n';
  for (auto x: max_values) cout << x << ' '; cout << '\n';

  return 0;
}