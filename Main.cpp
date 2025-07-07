#include "String.h"
#include <iostream> 

inline void
stringTest()
{
  // insert your code here
  using namespace tcii::ex;
  using namespace std;

  cout << "Chamando construtor default\n";
  String str1{};
  str1.printString();
  cout << endl;

  cout << "Chamando operator= com parâmetro const char*\n";
  str1 = "orange";
  str1.printString();
  cout << endl;

  cout << "Chamando o construtor com parâmetro const char*\n";
  String str2{"banana"};
  str2.printString();
  cout << endl;

  cout << "Chamando operator= de cópia\n";
  str2 = str1;  
  str2.printString();
  str2 = "banana";
  str2.printString();
  cout << "\n";

  cout << "Chamando construtor de cópia\n";
  String str3{str2};
  str3.printString();
  str3 = "lemon";
  str3.printString();
  cout << endl;
  
  cout << "Testando os operadores de igualdade e desigualdade\n";
  cout << (str3 == str2 ? "Iguais" : "Diferentes") << endl;
  cout << (str2 == str1 ? "Iguais" : "Diferentes") << endl;
  cout << (str1 == "orange" ? "Iguais" : "Diferentes") << endl;
  cout << (str1 == "pineapple" ? "Iguais" : "Diferentes") << endl;
  cout << (str1 != "pineapple" ? "Diferentes" : "Iguais") << endl;
  cout << (str3 != str2 ? "Diferentes" : "Iguais") << endl;
  cout << endl;

  cout << "Chamando construtor de movimento\n";
  String str4{std::move(str3)};
  str4.printString();
  cout << endl;

  // testando os operadores + e +=
  str3 = str3 + " juice" + " meal"; // (string + const char + const char) resulta em string + const char, bem definido no operator+
  str3 += " "; // str3 += " " + str2; não funciona! const char* + String não é definido no operator
  str3 += str2; // os operators assumem que sempre terá uma String primeiro.
  
  cout << "Movendo str3 para str4\n";
  str4 = std::move(str3);
  str4.printString();
  cout << endl;

  cout << "Limpando o str4\n";
  str4.clear();
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
