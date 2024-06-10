#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e6 + 9;
vector<int> spf(N);
void spf_sieve() {
  for(int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    for(int j = i; j < N; j += i) {
      spf[j] = min(spf[j], i);
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

  spf_sieve();

  int x;
  while(true) {
    cin >> x;
    if(x == 0) break;
    int tmp = x;
    set<int> se;
    while(tmp > 1) {
      se.insert(spf[tmp]);
      tmp /= spf[tmp];
    }
    cout << x << " : " << (int)se.size() << '\n';
  }
        
  return 0;
}