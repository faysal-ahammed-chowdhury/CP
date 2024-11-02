#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int n; cin >> n;
  int org_n = n;
  vector<int> a(n + 1), b(n + 1);
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    cnt1 += a[i] == 1;
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  n = a.size() - 1;
  int len = 1, first = -1, second = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (is_prime[a[i] + a[j]]) {
        if ((a[i] == 1 ? cnt1 : 1) + 1 > len) {
          len = (a[i] == 1 ? cnt1 : 1) + 1;
          first = a[i], second = a[j];
        }
      }
    }
  }

  if (cnt1 > len) {
    cout << cnt1 << '\n';
    for (int i = 1; i <= cnt1; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return 0;
  }
  if (len == 1) {
    cout << len << '\n';
    cout << b[1] << '\n';
    return 0;
  }
  cout << len << '\n';
  bool first_done = false, second_done = false;
  for (int i = 1; i <= org_n; i++) {
    if ((!first_done and b[i] == first) or (first == 1 and b[i] == 1)) {
      cout << b[i] << ' ';
      first_done = true;
    }
    if (!second_done and b[i] == second) {
      cout << b[i] << ' ';
      second_done = true;
    }
  }
  cout << '\n';

  return 0;
}