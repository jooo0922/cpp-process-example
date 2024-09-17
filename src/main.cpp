#include <stdio.h>
#include <unistd.h>

/*
  참고로, Windows 운영체제에서는
  unistd.h 헤더가 제공되지 않는 이슈로 인해,
  프로젝트가 macos 에서 실행 가능하도록 빌드 및 디버깅 환경 설정을 수정함.
*/

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
