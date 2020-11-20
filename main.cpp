#include <iostream>

#include <locale.h>
#include <queue>
#include <vector>

using namespace std;

int matriz[6][6] = {{0,5,0,0,15,2},{5,0,0,9,22,4},{0,0,0,12,1,0},{0,9,12,0,0,6},{15,22,1,0,0,0},{2,4,0,6,0,0}};

struct Tarefas
{

    string descricao;
    int ordem;

};

void criarMatriz()
{

    for (int l = 0; l < 6; l++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (matriz[l][c] != 0)
            {
                matriz[l][c] = 1;
            }
        }
    }
    cout << endl;
    cout << "Matriz de Adjacência:" << endl;
    for (int l = 0; l < 6; l++)
    {
        for (int c = 0; c < 6; c++)
        {
            cout << matriz[l][c]<<" | ";
        }
        cout<< endl;
    }
    cout << endl;

    for (int l = 0; l < 6; l++)
    {
        int grau = 0;
        for (int c = 0; c < 6; c++)
        {
            if (matriz[l][c] > 0)
            {
                grau++;
            }
        }

        cout << "O grau do vértice " << l + 1 << " é " << grau << endl;
    }
}

void retornarVertice()
{
    int aux;
    cout << "Digite o número do vértice que deseja retornar os vértices adjacentes: ";
    cin >> aux;

    for (int l = aux; l < aux+1; l++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (matriz[l][c] > 0)
            {
                cout << matriz[l][c] << " | ";
            }
        }

    }
}

int soma(int num[], int atual, int indice)
{
    if (indice == 0)
    {
        atual += num[0];
        indice = 1;
    }
    if (indice == 4)
    {
        return atual + num[indice];
    }
    else
    {
        atual += num[indice];
        soma(num, atual, indice + 1);
    }
}


struct compararOrdem
{
    bool operator()(Tarefas const& p1, Tarefas const& p2)
    {
        return p2.ordem < p1.ordem;
    }
};


void receberTarefas()
{

    int ordem;
    string descricao;

    Tarefas tarefa[10];
    priority_queue <Tarefas, vector<Tarefas>, compararOrdem> fila;

    for (int i = 0; i < 10; i++)
    {
        {
            cout<< "Digite a descrição da tarefa:";
            cin.ignore();
            getline(cin, descricao);
            tarefa[i].descricao = descricao;
            cout<< "Digite o grau de prioridade da tarefa (0 a 9):";
            cin>>ordem;
            cout<<" " <<endl;
            tarefa[i].ordem = ordem;
            fila.push(tarefa[i]);
        }
    }
    while(!fila.empty())
    {
        Tarefas t = fila.top();
        cout << t.descricao << ", ";
        fila.pop();
    }
}

struct Tabuleiro
{
    int mat[3][3] = {{1,2,3},{4,5,6},{7,0,8}};
    int posx = 2;
    int posy = 1;
};

bool validar(int x, int y)
{
    return !(x < 0 || x > 2 || y < 0 || y > 2);
}

void imprimeTabuleiro(Tabuleiro tabuleiro)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << tabuleiro.mat[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void mostrarEstados()
{

    Tabuleiro tabuleiro;
    queue<Tabuleiro> fazer;

    int posicaox[4] = {1,-1,0,0};
    int posicaoy[4] = {0,0,1,-1};

    cout << "Estado Atual: " << endl;
    imprimeTabuleiro(tabuleiro);

    cout << "Sucessores: " << endl;
    for (int i = 0; i < 4; i++)
    {
        int pox = tabuleiro.posx + posicaox[i];
        int poy = tabuleiro.posy + posicaoy[i];
        if (validar(pox,poy))
        {
            Tabuleiro sucessor = tabuleiro;
            swap(sucessor.mat[sucessor.posx][sucessor.posy],sucessor.mat[pox][poy]);
            sucessor.posx = pox;
            sucessor.posy = poy;
            imprimeTabuleiro(sucessor);
        }
    }
}



int main()
{
    setlocale(LC_ALL, "Portuguese");

    cout << "Você deseja chamar qual exercício?" << endl;
    cout << "" << endl;
    cout << "6. Dado o grafo representado na imagem a seguir. Faça um programa que leia um arquivo contendo informações do grafo, gere uma matriz de adjacência e calcule o grau de cada vértice." << endl;
    cout << "7. Dado o grafo anterior, faça um programa que leia um vértice e retorne os vértices adjacentes a ele." << endl;
    cout << "8. Usando recursividade, faça um programa que calcule a soma dos valores de um vetor." << endl;
    cout << "9. Faça um programa que leia 10 tarefas. Cada tarefa contém uma descrição (string) e a ordem que ela deve ser executada (utilizar classe ou estrutura para representar a tarefa). As tarefas devem ser inseridas em um vetor. O programa deve imprimir a descrição tarefas em ordem de execução." << endl;
    cout << "10. Dada o quebra-cabeça de 8 peças. Faça um programa que receba um estado do jogo e retorne todos estados subsequentes possíveis." << endl;

    cout << "Digite o número: ";
    int aux;
    cin >> aux;
    switch (aux)
    {
    case 6:
        cout << "" << endl;
        criarMatriz();
        break;
    case 7:
        cout << "" << endl;
        retornarVertice();
        break;
    case 8:
        cout << "" << endl;
        cout << "Favor conferir o código.";
        break;
    case 9:
        cout << "" << endl;
        receberTarefas();
        break;
    case 10:
        cout << "" << endl;
        mostrarEstados();
        break;
    }
    return 0;
}

