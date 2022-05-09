#include <iostream>

using namespace std;

struct node{
    int custo, vertice;
    node* next;
};

int num_nos, emissor, receptor, n_msg, tam;

void push_front(node *&head_ptr, int cost, int vert)
{
  node *no = new node;
  no->custo = cost;
  no->vertice = vert;
  no->next = head_ptr;
  head_ptr = no;
}

void remove_front(node *&head)
{
  node *aux = head;
  head = head->next;
  delete aux;
  aux = nullptr;
}

void bubble_down(node *&head)
{
    int a, b;
    node* aux = head;
    while(aux->next != nullptr)
    {
        if((aux->custo) > (aux->next->custo))
        {
            a = aux->custo;
            b = aux->vertice;
            aux->custo = aux->next->custo;
            aux->vertice = aux->next->vertice;
            aux->next->custo = a;
            aux->next->vertice = b;
        }
        aux = aux->next;
    }
}

void update(node *&head, int cost, int vert) //percorre a lista e atualiza o custo
{
    node* aux = head;
    while(aux != nullptr || aux->vertice != vert)
    {
        if (aux->vertice != vert)
            aux = aux->next;
        else
            break;
    }
    aux->custo = cost;
    bubble_down(head);
}

void dijkstra(node** matriz, int scr)
{
    int* n_arestas = new int[num_nos];
    int* D = new int[num_nos];
    int* F = new int[num_nos];
    
    for(int a = 0; a < num_nos; a++)
    {
        D[a] = F[a] = -1;
        n_arestas[a] = 0;
    }
    
    D[scr] = 0;
    
    node* heap = nullptr;
    
    //insere as informações da scr - heap_insert
    push_front(heap, 0, scr);
    bubble_down(heap);
    
    int u, v, w, test;
    node* e;
    for(int i = 0; i < num_nos; i++)
    {
        //heap extract
        u = heap->vertice;
        remove_front(heap);
        
        e = matriz[u];
        
        while(e != nullptr)
        {
            v = e->vertice;
            w = e->custo;
            if((D[u] + w < D[v]) || (D[v] == -1))
            {
                test = D[v];
                D[v] = D[u] + w;
                F[v] = u;
                
                n_arestas[v] = n_arestas[u] + 1;
                
                //heap update
                if(test == -1)//se o  v não tiver na heap
                {
                    push_front(heap, D[v], v);
                    bubble_down(heap);
                }
                else//se o v tiver na heap, atualiza o custo 
                    update(heap, D[v], v);
            }
            e = e->next;
        }
    }
  
    for(int b = 0; b < n_msg; b++)
    {
        cin >> emissor >> receptor >> tam;
        cout <<  n_arestas[emissor] + n_arestas[receptor] << " " << ((D[emissor] + D[receptor])*tam)/(1 << 20) << "\n";
    }
    cout << "\n";
}

int main()
{
    int bandwidth, cost, num_casos, DR, n_adj, vizinho;
    int custo1;
    
    cin >> num_casos;
 
    for(int i = 0; i < num_casos; i++)
    {
        cin >> num_nos >> DR;
        
        //criar matriz de listas de adjacência
        node** matriz = new node*[num_nos];
        for(int a = 0; a < num_nos; a++)
            matriz[a] = nullptr;
        
            
        for(int j = 0; j < num_nos; j++)
        {
            cin >> n_adj;
            for(int a = 0; a < n_adj; a++)
            {
                cin >> vizinho >> bandwidth;
                cost = (1 << 20)/bandwidth;
                push_front(matriz[j], cost, vizinho);
            }
        }
        
        cin >> n_msg;
        cout << "caso " << i << ":" << "\n";
        dijkstra(matriz, DR);
    }
}


