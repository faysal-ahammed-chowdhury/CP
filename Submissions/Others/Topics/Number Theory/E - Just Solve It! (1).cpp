#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 9;
vector<int> spf(N);
vector<int> nod(N, 0);
vector<long long> sod(N, 0);

void spf_sieve() {
  for(int i = 0; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i; j < N; j += i) {
      spf[j] = min(spf[j], i);
    }
  }
}

void nod_sieve() {
  for(int i = 2; i < N; i++) {
    nod[i] = 2;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i + i; j < N; j += i) {
      nod[j]++;
    }
  }
}


void sod_sieve() {
  for(int i = 2; i < N; i++) {
    sod[i] = i + 1;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i + i; j < N; j += i) {
      sod[j] += i;
    }
  }
}

void solve() {
  int n; cin >> n;
  int x = n;
  cout << spf[n] << ' ';
  int gpf = 0, unique_factor = 0, total_factor = 0;
  while(n > 1) {
    int factor = spf[n];
    unique_factor++;
    while(spf[n] == factor) {
      total_factor++;
      gpf = max(gpf, factor);
      n /= spf[n];
    }
  }
  cout << gpf << ' ';
  cout << unique_factor << ' ';
  cout << total_factor << ' ';
  cout << nod[x] << ' ';
  cout << sod[x] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();
  nod_sieve();
  sod_sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}