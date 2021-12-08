vector <i32> rabin_karp(string const &str, string const &pat) {
  i32 ssz = str.size(), psz = pat.size();
  const i32 m = 1e9 + 7, p = 67;

  vector <i64> p_pow(max(ssz, psz));
  p_pow[0] = 1;
  for(int i = 1; i < (i32)p_pow.size(); ++i) {
    p_pow[i] = (p_pow[i - 1] * p) % m;
  }

  vector <i64> hash(ssz + 1, 0);
  for(int i = 0; i < ssz; ++i) {
    hash[i + 1] = (hash[i] + (str[i] - '0' + 1) * p_pow[i]) % m;
  }

  i64 h_pat = 0;
  for(int i = 0; i < psz; ++i) {
    h_pat = (h_pat + (pat[i] - '0' + 1) * p_pow[i]) % m;
  }

  vector <i32> occurences;
  for(int i = 0; i + psz - 1 < ssz; ++i) {
    i64 cur_hash = (hash[i + psz] + m - hash[i]) % m;
    if(cur_hash == h_pat * p_pow[i] % m) {
      occurences.emplace_back(i);
    }
  }

  return occurences;
}
