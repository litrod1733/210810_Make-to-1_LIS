//
// Created by 이인성 on 2021/08/03.
//

#include <iostream>
int min_op[1000001];

int min(int n, int m) {
  if(n <= m)
    return n;
  else
    return m;
}

int main() {
  int N;
  scanf("%d", &N);
  min_op[0] = 0;
  min_op[1] = 0;
  for(int i = 2; i <= N; i++) {
    if((i%2 != 0) && (i%3 != 0)) {
      min_op[i] = min_op[i-1] + 1;
    }
    else if((i%2 == 0) && (i%3 != 0)) {
      min_op[i] = 1 + min(min_op[i-1], min_op[i/2]);
    }
    else if((i%2 != 0) && (i%3 == 0)) {
      min_op[i] = 1 + min(min_op[i-1], min_op[i/3]);
    }
    else
      min_op[i] = 1 + min(min_op[i-1], min(min_op[i/2], min_op[i/3]));
  }
//  for(int i=0; i<=N; i++) {
//    printf("%d -> %d\n", i, min_op[i]);
//  }
  printf("%d\n", min_op[N]);
  return 0;
}