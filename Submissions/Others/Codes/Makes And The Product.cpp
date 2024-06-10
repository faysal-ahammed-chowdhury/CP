#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nC3(int n) {
  ll ans = 1ll * n * (n - 1) * (n - 2);
  ans /= 6;
  return ans;
}

ll nC2(int n) {
  ll ans = 1ll * n * (n - 1);
  ans /= 2;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  sort(a + 1, a + n + 1);
  int first = a[1], second = a[2], third = a[3];

  if (first == second and second == third) {
    cout << nC3(cnt[first]) << '\n';
  }
  else if (first == second) {
    cout << nC2(cnt[first]) * cnt[third] << '\n';
  }
  else if (first == third) {
    cout << nC2(cnt[first]) * cnt[second] << '\n';
  }
  else if (second == third) {
    cout << nC2(cnt[second]) * cnt[first] << '\n';
  }
  else {
    cout << 1ll * cnt[first] * cnt[second] * cnt[third] << '\n';
  }

  return 0;
}