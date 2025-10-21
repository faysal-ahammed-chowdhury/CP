#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 19;
vector<int> divs[N];

void sieve() {
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

void solve() {
  int n; cin >> n;
  int a[n + 1], even = 0;
  set<int> se;
  bool done = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 1 and se.find(a[i]) != se.end()) {
      done = true;
    }
    else se.insert(a[i]);
    even += (a[i] % 2) == 0;
  }

  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
  }

  if (done) {
    cout << 0 << '\n';
    return;
  }

  se.clear();

  for (int i = 1; i <= n; i++) {
    for (auto d : divs[a[i]]) {
      if (se.find(d) != se.end()) {
        cout << 0 << '\n';
        return;
      }
      se.insert(d);
    }
  }

  se.clear();

  for (int i = 1; i <= n; i++) {
    for (auto d : divs[a[i]]) {
      if (se.find(d) != se.end()) {
        cout << 1 << '\n';
        return;
      }
    }
    for (auto d : divs[a[i] + 1]) {
      se.insert(d);
    }
  }

  se.clear();

  for (int i = 1; i <= n; i++) {
    for (auto d : divs[a[i] + 1]) {
      if (se.find(d) != se.end()) {
        cout << 1 << '\n';
        return;
      }
    }
    for (auto d : divs[a[i]]) {
      se.insert(d);
    }
  }

  cout << 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}