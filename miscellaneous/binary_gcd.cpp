i64 gcd(i64 a, i64 b) { // binary GCD uses about 60% fewer bit operations
  if (!a) return b;

  u64 shift = __builtin_ctzll(a | b);
  a >>= __builtin_ctzll(a);

  while (b) {
    b >>= __builtin_ctzll(b);

    if (a > b)
      swap(a, b);
    b -= a;
  }
  return a << shift;
}

i64 lcm(i64 a, i64 b) {
  return a / gcd(a, b) * b;
}
	
