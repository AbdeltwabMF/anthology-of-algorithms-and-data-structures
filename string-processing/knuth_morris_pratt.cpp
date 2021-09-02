/**
 * KMP(Knuth-Morris-Pratt) Algorithm
 ** Longest Prefix 
 *** proper prefix = all prefixes except the whole string
 *** propre suffix = all suffixes except the whole string
 ** Prefix Function = Failure Function
 *** Given String P of len m, Find F[m];
 *** let t = P[0....i] 
 *** f[i] = length of the longest proper prefix of t that is suffix of t 
 *** calculating i different ways
 *** match the pattern against itself
 *** O(m) for failure function
 *** O(n) for KMP
 **/

vector <int> LongestPrefix(string &p) {
  int psz = p.size();
  vector <int> longest_prefix(psz, 0);

  for(int i = 1, k = 0; i < psz; ++i) {
    while(k && p[k] != p[i]) k = longest_prefix[k - 1];
    longest_prefix[i] = (p[k] == p[i] ? ++k : k);
  }
  return longest_prefix;
}

vector <int> KMP(string &s, string &p) {
  int ssz = s.size(), psz = p.size();

  vector <int> longest_prefix = LongestPrefix(p), matches;
  
  for(int i = 0, k = 0; i < ssz; ++i) {
    while(k && p[k] != s[i]) k = longest_prefix[k - 1]; // Fail go back
    k += (p[k] == s[i]);
    
    if(k == psz) {
      matches.emplace_back(i - psz + 1);
      k = longest_prefix[k - 1]; // faill safe and find another pattern
    }
  }
  return matches;
}
