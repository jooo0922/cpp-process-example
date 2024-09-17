#include <stdio.h>
#include <unistd.h>

void foo() { printf("execute foo\n"); }

void bar() { printf("execute bar\n"); }

void baz() { printf("execute baz\n"); }

int main() {

  /*
    fork()

    현재 프로세스를 복사하여 자식 프로세스 생성.

    이때, 현재 실행 중인 프로세스가 부모 프로세스이면
    fork() 함수는 자식 프로세스의 PID 를 반환하고,

    현재 실행 중인 프로세스가 자식 프로세스이면 0을 반환함.
  */
  if (fork() == 0) {
    if (fork() == 0) {
      /*
        현재 실행 중인 프로세스가 자식 프로세스의 자식 프로세스임을 검사한 후,
        자식 프로세스의 자식 프로세스의 PID 출력
      */
      printf("child of child pid is %d\n", getpid());
      foo();
    } else {
      /*
        현재 실행 중인 프로세스가 자식 프로세스임을 검사한 후,
        자식 프로세스의 PID 출력
      */
      printf("child pid is %d\n", getpid());
      bar();
    }
  } else {
    if (fork() == 0) {
      /*
        현재 실행 중인 프로세스가 또 다른 복제된 자식 프로세스임을 검사한 후,
        자식 프로세스의 PID 출력
      */
      printf("child pid is %d\n", getpid());
    } else {
      /*
        현재 실행 중인 프로세스가 부모 프로세스임을 검사한 후,
        부모 프로세스의 PID 출력
      */
      printf("parent pid is %d\n", getpid());
      baz();
    }
  }

  return 0;
}
