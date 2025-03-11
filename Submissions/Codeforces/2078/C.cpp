#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int nn = n + n;
  int b[nn + 1];
  for (int i = 1; i <= nn; i++) {
    cin >> b[i];
  }
  
  sort(b + 1, b + nn + 1);
  reverse(b + 1, b + nn + 1);
  swap(b[1], b[2]);
  int first = b[1];
  vector<int> v;
  int l = 3, r = nn;
  int sum = 0;
  while (l < r) {
    v.push_back(b[r]);
    v.push_back(b[l]);
    sum += b[r] - b[l];
    l++, r--;
  }

  int d = abs(first - sum);
  int missing = b[2] + d;
  cout << first << ' ';
  sum = 0;
  sum += missing - b[2];
  cout << missing << ' ' << b[2] << ' ';

  int i = 1;
  for (auto x : v) {
    cout << x << ' ';
    if (i & 1) sum += x;
    else sum -= x;
    i++;
  }
  cout << '\n';

  // cout << sum << '\n';
  assert(sum == first);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}