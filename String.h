#ifndef __String_h
#define __String_h

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <cassert>
#include <cstring>
#include <iostream>

namespace tcii::ex
{ // begin namespace tcii::ex


//////////////////////////////////////////////////////////
//
// String class
// ======
class String
{
public:
  // feitos?
  ~String() = default;
  String() = default;
  
  // feitos
  String(const char* const);
  String(const String&);

  // feito?
  String(String&&) noexcept;

  // TO-DO
  void clear();

  auto size() const
  {
    return _size;
  }

  auto capacity() const
  {
    return isShort() ? maxBuffer - 1 : _capacity;
  }

  auto empty() const
  {
    return _size == 0;
  }

  const char* c_str() const
  {
    return _data;
  }

  // funcionou
  String& operator =(const char* const str) {
    std::cout << "Copy char op called\n";
    unsigned size = strlen(str);
    copy(str, size);
    
    return *this;
  }

  // funcionou tb
  String& operator =(const String& str) { 
    std::cout << "Copy ref op called\n";
    return this->operator=(str.c_str());
  }
  
  String& operator =(String&& str) noexcept {
    std::cout << "Move ref op called\n";
    unsigned size = str.size();
    move(str);

    return *this;
  }

  // errado, provavelmente,,,,,,,,,,,,,,
  String operator +(const char* const str) const {
    char* sum = strncat(sum, c_str(), size());
    sum = strncat(sum, str, strlen(str));

    return String(sum);
  }

  String operator +(const String&) const;

  String& operator +=(const char* const);
  String& operator +=(const String&);

  auto& operator [](unsigned i)
  {
    assert(i <= _size);
    return _data[i];
  }

  auto operator [](unsigned i) const
  {
    assert(i <= _size);
    return _data[i];
  }

  // funcionou 
  bool operator ==(const char* const str) const {
    return strcmp(c_str(), str) == 0;
  } 

  // funcionou
  bool operator ==(const String& str) const {
    return operator==(str.c_str());
  }

  auto operator !=(const char* const s) const
  {
    return !operator ==(s);
  }

  auto operator !=(const String& s) const
  {
    return !operator ==(s);
  }

  void printString() {
    using namespace std;

    cout << "String recebida: ";
    for(unsigned i = 0; i < size(); i++) {
      std::cout << _data[i]; 
    }

    cout << endl;
    cout << "Tamanho: " << size() << endl;
  }

private:
  static constexpr auto maxBuffer = 16u;

  unsigned _size;
  char* _data;
  union
  {
    unsigned _capacity;
    char _buffer[maxBuffer];
  };

  bool isShort() const
  {
    return _size < maxBuffer;
  }

  void copy(const char* const, unsigned);
  void move(String&) noexcept;

}; // String

} // end namespace tcii::ex

#endif // __String_h
