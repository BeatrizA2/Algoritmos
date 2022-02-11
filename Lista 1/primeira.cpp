#include <iostream>
#include <string>

using namespace std;

class node
{
public:
  string value;
  node *next;
};

void push_front(node **head, string valor);
void remove_front(node *&head);
void delete_all(node **head);
void push_back(node **head, string valor);

int main()
{
  node *head_historico = nullptr; // pilha -> push_front , remove_front
  node *head_memoria = nullptr;   // fila -> push_back, remove_front
  int memoria_size = 0, historico_size = 0;
  string comando = "biazita";
  string url;

  while (comando != "END")
  {
    getline(cin, comando);

    if (comando.length() > 3)
    {
      url = comando.substr(4, comando.length() - 4);
      comando = comando.substr(0, 3);
    }

    if (comando == "OPN")
    {
      push_front(&head_historico, url);
      historico_size++;
      cout << historico_size << endl;
    }
    else if (comando == "CUR")
    {
      if (historico_size == 0)
        cout << "NULL" << endl;
      else
        cout << head_historico->value << endl;
    }
    else if (comando == "BCK")
    {
      if (historico_size != 0)
      {
        remove_front(head_historico);
        historico_size--;
      }

      if (historico_size == 0)
        cout << "NULL" << endl;
      else
        cout << head_historico->value << endl;
    }
    else if (comando == "PAN")
    {
      cout << historico_size << endl;
      delete_all(&head_historico);
      historico_size = 0;
    }
    else if (comando == "SAV")
    {
      push_back(&head_memoria, head_historico->value);
      memoria_size ++;
      cout << memoria_size << endl;
    }
    else if (comando == "REA")
    {
      if (head_memoria == nullptr)
        cout << "NULL" << endl;
      else
      {
        cout << head_memoria->value <<  endl;
        remove_front(head_memoria);
        memoria_size --;
      }
    }
  }

  return 0;
}

void push_front(node **head_ptr, string valor)
{
  node *no = new node();
  no->value = valor;
  no->next = *head_ptr;
  *head_ptr = no;
}


void remove_front(node *&head)
{
  node *aux = head;
  head = head->next;
  delete aux;
  aux = nullptr;
}

void delete_all(node **head)
{
  node *head_ptr = *head;
  node *prox = nullptr;

  while (head_ptr != nullptr)
  {
    prox = head_ptr->next;
    delete prox;
    head_ptr = prox;
  }

  *head = nullptr;
}

void push_back(node **head, string valor)
{
  node *tail = new node();
  tail->next = nullptr;
  tail->value = valor;

  if (*head == nullptr)
    *head = tail;
  else
  {
    node *tail_aux = *head;

    while (tail_aux->next != nullptr)
      tail_aux = tail_aux->next;
    
    tail_aux->next = tail;
  }
}

