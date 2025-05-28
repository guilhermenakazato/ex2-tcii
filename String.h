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
  ~String() = default;
  
  String() = default;
  String(const char* const);
  String(const String&);
  String(String&&) noexcept;

  // capacity is only used when String is not short
  // _data only allocates memory when String is not short
  void clear() {
    if(!isShort()) {
      delete[] _data;
      _capacity = 0u;
    } else {
      _data = nullptr;
    }

    _size = 0;
  }

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

  String& operator =(const char* const str) {
    unsigned size = strlen(str);
    copy(str, size);
    
    return *this;
  }

  String& operator =(const String& str) { 
    return operator=(str.c_str());
  }
  
  String& operator =(String&& str) noexcept {
    unsigned size = str.size();
    move(str);

    return *this;
  }

  // var + "string"
  String operator +(const char* const str) const {
    String sum{*this};
    strncat(sum._data, str, strlen(str));

    return String(sum);
  }

  // var + var
  String operator +(const String& str) const {
    return operator+(str.c_str());
  }

  String& operator +=(const char* const str) {
    return operator=(operator+(str));
  }

  String& operator +=(const String& str) {
    return operator=(operator+(str.c_str()));
  }

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

  bool operator ==(const char* const str) const {
    return strcmp(c_str(), str) == 0;
  } 

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
