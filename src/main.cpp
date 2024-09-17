#include <stdio.h>
#include <windows.h> // Windows 에서 프로세스 생성 관련 API 들을 사용하기 위해 포함한 헤더 (실습 예제에 사용된 unistd.h 파일은 Windows 운영체제에서 미제공...)

int main()
{
  printf("hello, os\n");

  // 현재 실행되는 프로그램의 프로세스 PID 출력
  printf("my pid is %d\n", GetCurrentProcessId());

  return 0;
}
