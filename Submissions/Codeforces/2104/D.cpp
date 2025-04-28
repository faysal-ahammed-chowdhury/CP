#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 6e6 + 9, N = 4e5 + 9;
vector<bool> is_prime(MAX, true);
vector<int> primes;
int a[N];
int n, idx;

void sieve() {
  is_prime[1] = false;
  for (int i = 2; 1ll * i * i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

bool ok(int rem, ll coin, int idx2) {
  int st = n - rem;
  for (int i = st; i >= idx; i--, idx2++) {
    ll p = primes[idx2];
    ll need = p - a[i];
    assert(need > 0);
    if (coin >= need) coin -= need;
    else return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  ll coin = 0;
  idx = -1;
  int idx2;
  for (int i = 1; i <= n; i++) {
    ll p = primes[i - 1];
    if (a[i] >= p) {
      coin += 1ll * a[i] - p;
    }
    else {
      idx = i;
      idx2 = i - 1;
      break;
    }
  }

  if (idx == -1) {
    cout << 0 << '\n';
    return;
  }

  int l = 0, r = n - idx + 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid, coin, idx2)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  assert(ans != -1);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 2; i < MAX; i++) {
    if (is_prime[i]) primes.push_back(i);
  }
  // cout << (primes.size() >= N) << '\n';

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
