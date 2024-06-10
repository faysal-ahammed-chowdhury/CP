#include <bits/stdc++.h>
using namespace std;

struct Trie {
  const static int N = 26;
  const static char base_char = 'a'; // '0' for '0','1','2'
  struct TrieNode {
    int next[N];
    bool is_end;
    int freq;

    TrieNode() {
      for (int i = 0; i < N; i++) {
        next[i] = -1;
      }
      is_end = false;
      freq = 0;
    }
  };

  inline int get(char c) {
    return c - base_char;
  }

  vector<TrieNode> tree;
  Trie() {
    tree.push_back(TrieNode());
  }

  void insert(string &s) {
    int p = 0;
    tree[p].freq++;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        tree.push_back(TrieNode());
        tree[p].next[get(s[i])] = tree.size() - 1;
      }
      p = tree[p].next[get(s[i])];
      tree[p].freq++;
    }
    tree[p].is_end = true;
  }

  bool is_prefix(const string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].next[get(s[i])];
    }
    return true;
  }

  bool find(const string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        return false;
      }
      p = tree[p].next[get(s[i])];
    }
    return tree[p].is_end;
  }

  long long remove(string s) {
    int p = 0; 
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (tree[p].next[get(s[i])] == -1) {
        return ans;
      }
      p = tree[p].next[get(s[i])];
      ans += 2 * tree[p].freq;
    }
    return ans;
  }

} trie;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string a[n + 1];
  int tot_len = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    trie.insert(a[i]);
    tot_len += a[i].size();
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += tot_len;
    ans += a[i].length() * n;
    string s = a[i];
    reverse(s.begin(), s.end());
    int x = trie.remove(s);
    ans -= x;
  }

  cout << ans << '\n';

  return 0;
}