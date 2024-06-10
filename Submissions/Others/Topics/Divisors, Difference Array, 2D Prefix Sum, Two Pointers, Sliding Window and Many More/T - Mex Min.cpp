#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9, inf = 1e9;
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  set<int> missing_numbers;
  for (int i = 0; i <= n; i++) {
    missing_numbers.insert(i);
  }
  map<int, int> freq;
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    freq[a[i]]++;
    missing_numbers.erase(a[i]);
    if (i >= m) {
      ans = min(ans, *missing_numbers.begin());
      freq[a[i - m + 1]]--;
      if (freq[a[i - m + 1]] == 0) {
        freq.erase(a[i - m + 1]);
        missing_numbers.insert(a[i - m + 1]);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}