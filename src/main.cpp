#include <stdio.h>
#include <unistd.h>

int main() {
  printf("hello, os\n");

  // 현재 실행되는 프로그램의 프로세스 PID 출력
  printf("my pid is %d\n", getpid());

  return 0;
}
