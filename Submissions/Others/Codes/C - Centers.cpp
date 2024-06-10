#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 9;
int freq[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ninto3 = 3 * n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(int i = 1; i <= ninto3; i++) {
    int x; cin >> x;
    freq[x]++;
    if(freq[x] == 2) {
      pq.push({i, x});
    }
  }
  while(!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    cout << p.second << ' ';
  }
  cout << '\n';
        
  return 0;
}