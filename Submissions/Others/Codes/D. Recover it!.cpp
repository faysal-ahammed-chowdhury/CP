#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int P = 2750135;
int greatest_div[P];
vector<int> primes;
vector<int> g[P];
int indeg[P];

void sieve() {
  for (int i = 2; i < P; i++) {
    for (int j = i + i; j < P; j += i) {
      greatest_div[j] = i;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  primes.push_back(0);
  for (int i = 2; i < P; i++) {
    if (greatest_div[i] == 0) primes.push_back(i);
  }

  int n; cin >> n;
  multiset<int> ms;
  for (int i = 1; i <= n + n; i++) {
    int x; cin >> x;
    ms.insert(x);
  }

  for (int i = 2; i < P; i++) {
    int u = greatest_div[i];
    int v = (i < 200000 ? primes[i] : 0);
    if (u and ms.find(i) != ms.end() and ms.find(u) != ms.end()) {
      g[i].push_back(u);
    }
    if (v and ms.find(i) != ms.end() and ms.find(v) != ms.end()) {
      g[i].push_back(v);
    }
  }

  for (int i = 1; i <= P; i++) {
    if (ms.find(i) == ms.end()) continue;
    for (auto v : g[i]) {
      // cout << i << ' ' << v << '\n';
      indeg[v]++;
    }
  }

  queue<int> q;
  for(int i = 1; i < P; i++) {
    if(ms.find(i) != ms.end() and indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> order;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    order.push_back(top);
    for(auto v: g[top]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  vector<int> ans;

  for (auto u : order) {
    // cout << u << ' ';
    for (auto v : g[u]) {
      while (ms.find(u) != ms.end() and ms.find(v) != ms.end()) {
        ans.push_back(u);
        ms.erase(ms.find(u));
        ms.erase(ms.find(v));
      }
    }
  }

  assert(ans.size() == n);
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}