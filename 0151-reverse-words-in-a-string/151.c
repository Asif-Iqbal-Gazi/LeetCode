void reverseWord(char *s, int start, int end) {
  --end;
  while (start < end) {
    char temp = s[start];
    s[start]  = s[end];
    s[end]    = temp;
    start++;
    end--;
  }
}

char *reverseWords(char *s) {
  int write_pos = 0, i = 0;

  // Remove extra spaces: keep single space between words
  while (s[i]) {
    if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
      s[write_pos++] = s[i];
    ++i;
  }

  // Remove trailing space if any
  if (s[write_pos - 1] == ' ')
    write_pos--;
  s[write_pos] = '\0';

  // Reverse each word
  i = 0;
  while (i < write_pos) {
    int j = i;
    while (j < write_pos && s[j] != ' ') ++j;
    reverseWord(s, i, j);
    i = j + 1;
  }

  // Reverse the whole string
  reverseWord(s, 0, write_pos);

  return s;
}
