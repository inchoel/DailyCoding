int main()
{
  printTestResults(testParameters, sizeof(testParameters) / sizeof(testParameters[0]));  // testParameter에 기록한 테스트 입력으로 실행한 결과를 출력해준다. (수험자 확인용)

  test_2_1();

  test_2_2();

  return 0;
}
