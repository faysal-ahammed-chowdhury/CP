#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 42;
int n, k, a[N], mid;
vector<int> v1, v2;

void f(int i, int sum, int end, int box) {
  if (i > end) {
    if (box == 1) v1.push_back(sum);
    else v2.push_back(sum);
    return;
  }
  f(i + 1, sum + a[i], end, box);
  f(i + 1, sum, end, box);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  mid = (n + 1) / 2;

  f(1, 0, mid - 1, 1);
  f(mid, 0, n, 2);

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  int ans = 0;
  for (auto x : v1) {
    if (x > k) continue;
    int mx = k - x;
    auto it = --upper_bound(v2.begin(), v2.end(), mx);
    ans = max(ans, x + *it);
  }

  cout << ans << '\n';

  return 0;
}