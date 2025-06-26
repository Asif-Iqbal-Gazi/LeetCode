int heightChecker(int *heights, int heightsSize) {
  int count[101] = {0};

  for (int i = 0; i < heightsSize; i++) {
    count[heights[i]]++;
  }

  int res         = 0;
  int curr_height = 1;
  for (int i = 0; i < heightsSize; i++) {
    while (count[curr_height] == 0) curr_height++;
    if (heights[i] != curr_height) res++;
    count[curr_height]--;
  }
  return res;
}
