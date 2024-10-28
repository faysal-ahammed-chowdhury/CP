#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 9;
int n, a[N], pref[N], tot_sum_of_segment[N], pref_tot_sum_of_segment[N], len[N];
int final[N];

int f(int r) {
  auto idx = upper_bound(len + 1, len + n + 1, r) - len - 1;
  int ans = pref_tot_sum_of_segment[idx];
  int more = r - len[idx];
  if (more) {
    int x = idx + more;
    int add = final[x] - (pref[x] * (n - x));
    int extra = add - ((final[x] - final[idx]) - ((pref[x] - pref[idx]) * (n - x)));
    ans += add - extra;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    sum += pref[i];
  }

  tot_sum_of_segment[1] = sum; // segment -> {(1...n), (2...n), (3...n), ...}
  for (int i = 2, j = n; i <= n; i++, j--) {
    tot_sum_of_segment[i] = tot_sum_of_segment[i - 1] - (a[i - 1] * j);
  }

  for (int i = 1; i <= n; i++) {
    pref_tot_sum_of_segment[i] = pref_tot_sum_of_segment[i - 1] + tot_sum_of_segment[i];
  }

  for (int i = n, j = 1; i >= 1; i--, j++) {
    len[j] = len[j - 1] + i;
  }

  for (int i = 1, j = n; i <= n; i++, j--) {
    final[i] = a[i] * j;
    final[i] += final[i - 1];
  }

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << f(r) - (l == 1 ? 0 : f(l - 1)) << '\n';
  }

  return 0;
}