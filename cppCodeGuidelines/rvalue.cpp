#include <iostream>

using namespace std;

class Data {
  public:
    int code;
    string name;
    Data() { cout << "기본 생성자" << '\n'; }
    Data(int _code, string _name) {  cout << "인자 생성자" << '\n'; }
    Data(Data& other) { cout << "복사 생성자" << '\n'; }
    Data& operator= (const Data& d) { cout << "대입" << '\n'; return *this; }

    Data(Data&& other) { cout << "Move 생성자" << '\n'; }
    Data& operator = (const Data&& d) { cout << "Move 대입" << '\n'; return *this; }
};

int main(void) {
  //좌측값은 라인이 지났어도 값유지
  //우측값은 라인이 벗어나면 없어짐
  // 대입값이 우측값이여야지 우측값 참조 관련 연산자 발동!! 
  cout<<"1"<<endl;
  Data data1(Data(10,"Orge1")); //인자, 무브

  cout<<endl<<"2"<<endl;
  Data data2(11,"Orge2");// 인자
  Data data3 = data2;// 복사

  cout<<endl<<"3"<<endl;
  Data data4; Data data5; // 기본, 기본
  data5 = data4; // 대입

  cout<<endl<<"4"<<endl;
  Data data6 = Data(12,"Orge3"); // 인자, 무브

  cout<<endl<<"5"<<endl;
  Data data7; Data data8; // 기본, 기본
  data8 = std::move(data7); // 무브 대입

  //주의!!! 우측값으로 쓰여진것은 다음에 쓸수있을지 없을지 알수 없다!!!
  //Data data9 = data7; // <- 이런짓은 위험하니깐 하지말자...
  return 0;
}
