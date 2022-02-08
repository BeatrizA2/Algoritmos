#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numPalavras;
int numeros[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void Senha(int indice, string senha, string padrao, vector<string> &words);

int main()
{
  cin >> numPalavras;
  cin.ignore(256, '\n');

  vector<string> palavras(numPalavras);

  for (int g = 0; g < numPalavras; g++)
  {
    getline(cin, palavras[g]);
  }

  string padrao = "something";

  while (getline(cin, padrao))
  {
    if (padrao.length() == 0 || padrao.empty())
      break;

    Senha(0, "", padrao, palavras);
  }

  return 0;
}

void Senha(int indice, string senha, string padrao, vector<string> &words)
{
  int indexMax;
  string passw;
  string add;

  if (padrao[indice] == 'X')
    indexMax = numPalavras;
  else
    indexMax = 10;

  for (int a = 0; a < indexMax; a++)
  {
    if (padrao[indice] == 'X')
      add = words[a];
    else
      add = to_string(numeros[a]);

    passw = senha + add;

    if (indice == padrao.length() - 1)
      cout << passw << endl;
    else
      Senha(indice + 1, passw, padrao, words);
  }
}
