ll readll () {
  bool minus = false;
  unsigned long long result = 0;
  char ch;
  ch = getchar();
  
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }

  if (ch == '-') minus = true;
  else result = ch - '0';

  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }

  if (minus) return -(ll)result;
  return result;
}

int readi () {
  bool minus = false;
  unsigned int result = 0;
  char ch;
  ch = getchar();
  
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }

  if (ch == '-') minus = true;
  else result = ch - '0';

  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }

  if (minus) return -(int)result;
  return result;
}
