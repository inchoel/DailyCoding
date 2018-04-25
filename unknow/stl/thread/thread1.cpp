#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void foo()
{
  cout << "thread start" << endl;
  this_thread::sleep_for(3s);
  cout << "thread end" << endl;
}

int main()
{
  thread t(&foo);

  // t.join(); // 스레드 종료 대기.
  t.detach(); // 별도 처리 / 분리

  /*
  thread::id id = this_thread::get_id();

  cout << id << endl;

  this_thread::sleep_for(3s);
  this_thread::sleep_until(chrono::system_clock::now() + 3s);
  this_thread::yield();
  */
}
