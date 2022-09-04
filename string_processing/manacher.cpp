/**
   Manacher's Algorithm - Finding all sub-palindromes in O(N)
   Problem: https://leetcode.com/problems/longest-palindromic-substring
 */

vector<int> manacher_odd(string &s) {
  int n = s.size();
  s = "^" + s + "$";
  vector<int> pal(n + 2);
  int l = 1, r = 1;

  for (int i = 1; i <= n; ++i) {
    int mirror = pal[l + (r - i)];
    pal[i] = max(0, min(r - i, mirror));

    while (s[i - pal[i]] == s[i + pal[i]]) {
      ++pal[i];
    }

    if (i + pal[i] > r) {
      l = i - pal[i], r = i + pal[i];
    }
  }
  return vector<int>(begin(pal) + 1, end(pal) - 1);
}

vector<int> manacher(const string &s) {
  string t = "#";

  for (char c : s)
    t += c + string("#");

  vector<int> res = manacher_odd(t);
  return vector<int>(begin(res) + 1, end(res) - 1);
}

void Solve() {
  string s = "ababa";
  vector<int> v = manacher(s);

  int mx = *max_element(begin(v), end(v));
  int maxIdx = find(begin(v), end(v), mx) - begin(v);
  maxIdx -= (maxIdx + 1) / 2;

  return s.substr(maxIdx - (mx / 2) + 1, mx - 1);
}
