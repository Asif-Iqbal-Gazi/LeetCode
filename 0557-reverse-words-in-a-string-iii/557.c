void reverseWord(char *s, int start, int end) {
  --end;
  while (start < end) {
    char temp  = s[start];
    s[start++] = s[end];
    s[end--]   = temp;
  }
}

char *reverseWords(char *s) {
  int n     = strlen(s);
  int start = 0;

  while (start < n) {
    int end = start;
    while (end < n && s[end] != ' ') end++;
    reverseWord(s, start, end);
    start = end + 1;
  }

  return s;
}
