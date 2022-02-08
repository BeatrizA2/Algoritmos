#include <iostream>

using namespace std;

string parOuimpar(int num)
{
  if (num % 2 == 0)
    return "Par";
  else
    return "Impar";
}

int main()
{
  int numero;
  cin >> numero;
  cout << parOuimpar(numero) << endl;

  return 0;
}
