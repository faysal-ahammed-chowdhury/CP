#include <bits/stdc++.h>
using namespace std;

vector<int> get_pf(int n) {
  vector<int> pf;
  int lim = sqrt(n + 1);
  for (int i = 2; i <= lim; i++) {
    while (n % i == 0) {
      pf.push_back(i);
      n /= i;
    }
  }
  if (n > 1) pf.push_back(n);
  return pf;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> pf = get_pf(n);

  if (k > pf.size()) {
    cout << -1 << '\n';
    return 0;
  }

  for (int i = 1; i <= k - 1; i++) {
    cout << pf[i - 1] << ' ';
  }

  int m = pf.size();
  int last = 1;
  for (int i = k; i <= m; i++) {
    last *= pf[i - 1];
  }

  cout << last << '\n';

  return 0;
}