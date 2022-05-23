#include <iostream>

using namespace std;

int n_brin, n_visitas, kmax;

void knapsack(int* S, int* B, int* C, int* visitas)
{
    int d, i, j, count, v, aux;
    int** R = new int*[n_brin + 1];
    for(int c = 0; c < n_brin + 1; c++)
    {   R[c] = new int[kmax + 1];
        for(d = 0; d < kmax + 1; d++)
            R[c][d] = 0;
    }
    
    for(i = 1; i < n_brin + 1; i++)
    {
        for(j = 1; j < kmax + 1; j++)
        {
            v = 0;
            R[i][j] = R[i - 1][j];
            for(count = 1; count*C[i-1] <= j; count++)
            {
                aux = S[i - 1] -(count - 1)*(count - 1)*B[i - 1];
                if(aux > 0)
                    v += aux;
                
                if(v + R[i - 1][j - count*C[i - 1]] > R[i][j])
                    R[i][j] = v + R[i - 1][j - count*C[i - 1]];
                
            }
        }
    }
    
    for(int k = 0; k < n_visitas; k++)
        cout << k << ": " << R[n_brin][visitas[k]] << "\n";
}

int main()
{
   cin >> n_brin;
   int* diversao = new int[n_brin];
   int* aborr = new int[n_brin];
   int* custo = new int[n_brin];
   
   for(int b = 0; b < n_brin; b++)
       cin >> diversao[b] >> aborr[b] >> custo[b];
   
   cin >> n_visitas;
   int* visitas = new int[n_visitas];
   kmax = 0;
   
   for(int a = 0; a < n_visitas; a++)
   {
       cin >> visitas[a];
       if(kmax < visitas[a])
        kmax = visitas[a];
   }
    
    knapsack(diversao, aborr, custo, visitas);
}
