#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 9;
int divisible[N];
int n, cnt[N];

void sieve() {
  for(int i = 1; i < N; i++) {
    for(int j = i; j < N; j += i) {
      divisible[i] += cnt[j];
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  sieve();
  for(int i = 1; i <= N - 9; i++) {
    cout << divisible[i] << '\n';
  }
        
  return 0;
}