#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, MAX = 1e6 + 9;
bool has[MAX];
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    if (mp[a[i]] == 1) {
      for (int j = a[i] + a[i]; j < MAX; j += a[i]) {
        has[j] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!(has[a[i]] or mp[a[i]] > 1)) {
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}