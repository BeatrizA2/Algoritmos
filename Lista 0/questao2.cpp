#include <iostream>

using namespace std;

int Produto(int num1, int num2)
{
  int resultado;

  if (num1 == 0 || num2 == 0)
    return 0;

  else
  {
    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 > 0))
    {
      resultado = num1;
      for (int i = 0; i < num2 - 1; i++)
      {
        resultado += num1;
      }
    }
    else if (num1 > 0 && num2 < 0)
    {
      resultado = num2;
      for (int i = 0; i < num1 - 1; i++)
      {
        resultado += num2;
      }
    }
    else
    {
      resultado = num1;
      for (int i = 0; i > num2 - 1; i--)
      {
        resultado -= num1;
      }
    }

    return resultado;
  }
}

int main()
{
  int numero1, numero2;
  cin >> numero1;
  cin >> numero2;
  cout << Produto(numero1, numero2) << endl;

  return 0;
}
