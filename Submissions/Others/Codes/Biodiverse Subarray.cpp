#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, k, a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int i = 1, j = 0;
  map<int, int> mp;
  long long ans = 0;
  while (i <= n and j <= n) {
    if (mp.size() == k) {
      ans += n - j + 1;
      mp[a[i]]--;
      if (mp[a[i]] == 0) mp.erase(a[i]);
      i++;
    }
    else {
      j++;
      if (j <= n) mp[a[j]]++;
    }
  }

  cout << ans << '\n';

  return 0;
}