/**
 * @file   main.cpp
 * @brief  Arquivo principal do projeto
 * @author Bianca Santiago (bianca.santiago72@gmail.com)
 * @since  07/06/2017
 * @date   14/06/2017
 */ 
#include <iostream>
#include "files.h"
#include "cache.h"
#include "funcoes.h"

/**
 * @brief Funcao principal
 */
int main(){
	srand(time(NULL));

	Cache* cache = lerArquivo("data/config");

	int* v = inicializaCache(cache->getNumLinhas());

	int *cont = new int[cache->getNumLinhas()];
	int *min = new int[cache->getNumLinhas()];
	int *seg = new int[cache->getNumLinhas()];
	int *conteudo = new int[cache->getNumBlocos() * cache->getTamBloco()];

	bool completo = false;

	for(int i = 0; i < cache->getNumLinhas(); i++) {
		cont[i] = 0;
		min[i] = 0;
		seg[i] = 0;
	}

	for(int i = 0; i < cache->getNumBlocos() * cache->getTamBloco(); i++) {
		conteudo[i] = rand() % 100;
	}

	int operacao = 10;

	while(operacao != 0) {
		cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "              1 - read                " << endl;
		cout << "              2 - show                " << endl;
		cout << "              0 - sair:               " << endl;
		cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
		cin >> operacao;

		if(operacao == 1) {
			if(cache->getMapeamento() == 1) {
				int palavra;

				cout << "Informe a palavra: ";
				cin >> palavra;

				if(palavra < 0) return 0;
				else Direto(cache, palavra, v);
				
			}

			else if(cache->getMapeamento() == 2) {
				int palavra;

				cout << "Informe a palavra: ";
				cin >> palavra;

				if(palavra < 0) return 0;
				else totalmenteAssociativo(cache, palavra, v, cont, min, seg, completo);			
			}

			else if(cache->getMapeamento() == 3) {
				int palavra;

				cout << "Informe a palavra: ";
				cin >> palavra;

				if(palavra < 0)	return 0;
				else parcialmenteAssociativo(cache, palavra, v, cont, min, seg, completo);
			}
		}

		else if(operacao == 2) {
			if(cache->getMapeamento() !=3) mostraDiretoTotalmenteAssociativo(cache, v, conteudo);
			else if(cache->getMapeamento() == 3) mostraParcialmenteAssociativo(cache, v, conteudo);
		}

		else return 0;
	}
}