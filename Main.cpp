#include "String.h"
#include <iostream> 

inline void
stringTest()
{
  // insert your code here
  using namespace tcii::ex;
  using namespace std;

  String str1{};
  str1.printString();

  str1 = "orange";
  str1.printString();

  String str2{"banana"};
  str2.printString();

  str2 = str1;
  str2.printString();

  String str3{str2};
  str3.printString();
  
  cout << (str3 == str2 ? "Iguais" : "Diferentes") << endl;
  cout << (str2 == str1 ? "Iguais" : "Diferentes") << endl;
  cout << (str1 == "orange" ? "Iguais" : "Diferentes") << endl;
  cout << (str1 == "pineapple" ? "Iguais" : "Diferentes") << endl;
  cout << (str1 != "pineapple" ? "Diferentes" : "Iguais") << endl;
  cout << (str3 != str2 ? "Diferentes" : "Iguais") << endl;

  String str4{std::move(str3)};
  str4.printString();

  str1 = "lemon";
  str4 = std::move(str1);
  str4.printString();
}

//
// Main function
//
int
main()
{
  stringTest();
  return 0;
}
