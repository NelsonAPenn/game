#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
void testSection(std::string should);
void expectCondition(bool cond);
void expectEqual(const char* a, std::string b);
void expectEqual(std::string a, const char* b);
template <class T>
void expectEqual(T a, T b);
void expectNotEqual(const char* a, std::string b);
void expectNotEqual(std::string a, const char* b);
template <class T>
void expectNotEqual(T a, T b);

void runTests()
{
  testSection("Unit tests should work");
  expectCondition(true);
  expectEqual("a", "a");
  expectNotEqual(2, 5);
}
void testSection(std::string should)
{
  std::cout << "\033[1;33m" << should << "\033[0m\n";
}
void expectCondition(bool cond)
{
  std::cout << '\t';
  if(cond)
    std::cout << "\033[1;32mPASS\033[0m\n";
  else
    std::cout << "\033[1;31mFAIL\033[0m\n";
}
void expectEqual(const char* a, std::string b)
{
  std::string newA(a);
  expectEqual(newA, b);
}
void expectEqual(std::string a, const char* b)
{
  std::string newB(b);
  expectEqual(a, newB);
}
template <class T>
void expectEqual(T a, T b)
{
  bool cond = a == b;
  std::cout << '\t';
  if(cond)
    std::cout << "\033[1;32mPASS:\033[0m\t" << "\033[1;33m" << a << " equals " << b << "\033[0m\n";
  else
    std::cout << "\033[1;31mFAIL:\033[0m\t" << "\033[1;33m" << a << " does not equal " << b << "\033[0m\n";
}
void expectNotEqual(const char* a, std::string b)
{
  std::string newA(a);
  expectEqual(newA, b);
}
void expectNotEqual(std::string a, const char* b)
{
  std::string newB(b);
  expectEqual(a, newB);
}
template <class T>
void expectNotEqual(T a, T b)
{
  bool cond = a != b;
  std::cout << '\t';
  if(cond)
    std::cout << "\033[1;32mPASS:\033[0m\t" << "\033[1;33m" << a << " does not equal " << b << "\033[0m\n";
  else
    std::cout << "\033[1;31mFAIL:\033[0m\t" << "\033[1;33m" << a << " equals " << b << "\033[0m\n";
}
