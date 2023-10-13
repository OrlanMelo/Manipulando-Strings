#include <string>
#include <iostream>
#include <algorithm>
#include <tchar.h>

using namespace std;

class cFuncoes
{
private:
public:

	void TextoGRANDE(wstring Texto)
	{
		transform(Texto.begin(), Texto.end(), Texto.begin(), towupper);
		_tprintf(L"Conversão: %s\n", Texto.c_str());
	}

	void Textopequeno(wstring Texto)
	{
		transform(Texto.begin(), Texto.end(), Texto.begin(), towlower);
		_tprintf(L"Conversão: %s\n", Texto.c_str());
	}

	void TextoNormal(wstring Texto)
	{
		_tprintf(L"Texto a ser convertido: %s\n", Texto.c_str());
	}

	void RemoverItem(wstring Texto, char Remover)
	{
		wstring wTexto = Texto;

		wTexto.erase(remove(wTexto.begin(), wTexto.end(), Remover), wTexto.end());
		_tprintf(L"Resultado: %s\n", wTexto.c_str());
	}

	void AcrescentarItem(wstring Texto, char Acrescentar, bool Inicio, bool Final)
	{
		wstring wTexto = Texto;

		if (Inicio == true)
			wTexto.insert(wTexto.begin(), Acrescentar);//Irá acrescentar a letra ou número no início da frase.

		if (Final == true)
			wTexto.insert(wTexto.end(), Acrescentar);//Irá acrescentar a letra ou número no final da frase.

		_tprintf(L"Resultado: %s\n", wTexto.c_str());
	}

	void Quantidade(wstring Texto)
	{
		wstring wTexto = Texto;

		int iQuantidade = 0;
		iQuantidade = wTexto.length();

		cout << "Quantidade de caracteres na frase: " << iQuantidade << "\n";
	}

	void GerarTextoAleatorio(int Quantidade)
	{
		wstring wTexto;
		char Alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";

		for (int i = 0; i < Quantidade; i++)
			wTexto += Alfabeto[rand() % (sizeof(Alfabeto) - 1)];

		_tprintf(L"Resultado aleatório: %s\n", wTexto.c_str());
	}

}Funcoes;

int main()
{

	cout << "O assistente está formatando strings...\n";

	wstring Texto = L"Teste";

	Funcoes.TextoNormal(Texto);
	Funcoes.TextoGRANDE(Texto);
	Funcoes.Textopequeno(Texto);
	Funcoes.RemoverItem(L"Teste", 'T');
	Funcoes.AcrescentarItem(L"Teste", 'E', true, true);
	Funcoes.Quantidade(L"abcdefghi");
	Funcoes.GerarTextoAleatorio(15);
	Funcoes.GerarTextoAleatorio(15);

	system("pause");
}