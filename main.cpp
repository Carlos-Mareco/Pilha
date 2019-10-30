#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::endl;
using std::cout;
using std::cin;

typedef struct no
{
	int valor;
	struct no* proximo;
}no;

void setWindowsUTF8();
int menu(int itens);
int inserirPilha(no** pilha, int itens);
int excluirPilha(no** pilha, int itens);
void listarPilha(no* pilha, int itens);
int limparPilha(no** pilha, int itens);
bool pilhaVazia(int itens, bool exibir);

int main()
{	
	no* pilha = NULL;
	int itens = 0;
	bool sair = false;

	while (sair == false)
	{
		switch (menu(itens))
		{
		case 1:
			//inserir
			itens = inserirPilha(&pilha, itens);
			system("cls");
			break;
		case 2:
			//excluir
			itens = excluirPilha(&pilha, itens);
			system("cls");
			break;
		case 3:
			//listar itens
			listarPilha(pilha, itens);
			system("cls");
			break;
		case 4:
			//limpar pilha
			itens = limparPilha(&pilha, itens);
			system("cls");
			break;
		case 5:
			//sair
			system("cls");
			cout << "Obrigado por usar! :)" << endl;
			system("pause");
			sair = true;
			break;
		default:
			cout << "ERRO: Opção inválida! :(" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

int menu(int itens)
{
	int opcao;
	cout << "****PILHA****" << endl;
	cout << "1 - Inserir" << endl;
	cout << "2 - Excluir" << endl;
	cout << "3 - Listar itens (" << itens << ")" << endl;
	cout << "4 - Limpar pilha" << endl;
	cout << "5 - Sair" << endl;
	cout << "Escolher: ";
	cin >> opcao;
	return opcao;
}
int inserirPilha(no** pilha, int itens)
{
	int num;
	cout << "Entre com um valor inteiro: ";
	cin >> num;
	no* novo = (no*) new no;
	novo->valor = num;
	if (pilhaVazia(itens, false) == true)
	{
		novo->proximo = NULL;
		*pilha = novo;
		itens++;
	}
	else
	{
		no* aux = *pilha;
		while (aux->proximo != NULL)
		{
			aux = aux->proximo;
		}
		aux->proximo = novo;
		novo->proximo = NULL;
		itens++;
	}
	return itens;
}
int excluirPilha(no** pilha, int itens)
{
	if (pilhaVazia(itens, true) == true)
	{
	}
	else
	{
		if (itens == 1)
		{
			delete* pilha;
			*pilha = NULL;
			itens--;
		}
		else
		{
			no* aux = *pilha;
			for (int i = 2; i < itens; i++)
			{
				aux = aux->proximo;
			}
			delete aux->proximo;
			aux->proximo = NULL;
			itens--;
		}
	}
	return itens;
}
void listarPilha(no* pilha, int itens)
{
	if (pilhaVazia(itens, true) == true)
	{
	}
	else
	{
		no* aux = pilha;
		cout << "Itens da pilha: " << endl;
		while (aux != NULL)
		{
			cout << " " << aux->valor << endl;
			aux = aux->proximo;
		}
		system("pause");
	}
}
int limparPilha(no** pilha, int itens)
{
	if (pilhaVazia(itens, true) == true)
	{
	}
	else
	{
		no* aux = *pilha;
		no* aux2;
		while (aux != NULL)
		{
			aux2 = aux;
			aux = aux->proximo;
			delete aux2;
		}
		itens = 0;
		*pilha = NULL;
	}
	return itens;
}
bool pilhaVazia(int itens, bool exibir)
{
	if (itens == 0)
	{
		if (exibir == true)
		{
			cout << "ERRO: Lista vazia!" << endl;
			system("pause");
		}
		return true;
	}
	else
	{
		return false;
	}
}
void setWindowsUTF8()
{
	system("chcp 65001");
	system("cls");
}
