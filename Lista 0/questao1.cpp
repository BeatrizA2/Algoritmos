#include <iostream>

using namespace std;

int Fibonacci(int num)
{
  if (num == 1)
  {
    return 0;
  }
  else if (num == 2)
  {
    return 1;
  }
  else
  {
    return Fibonacci(num - 1) + Fibonacci(num - 2);
  }
}

int main()
{
  int numero;
  cin >> numero;
  cout << Fibonacci(numero) << endl;
  cout << "

      return 0;
}
