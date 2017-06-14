/**
 * @file  main.cpp
 * @brief Arquivo principal do projeto
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @since 07/06/2017
 * @date  14/06/2017
 */ 
#include <iostream>
#include "files.h"
#include "cache.h"
#include "funcoes.h"

/**
 * @brief      Função principal
 *
 * @return     0
 */
int main()
{
	srand(time(NULL));

	Cache* cache = ler_arquivo("../data/input/config");

	int* v = inicializaCache(cache->getNumLinhas());

	int *cont = new int[cache->getNumLinhas()];
	int *min = new int[cache->getNumLinhas()];
	int *seg = new int[cache->getNumLinhas()];
	int *conteudo = new int[cache->getNumBlocos() * cache->getTamBloco()];

	bool cheio = false;

	for(int i = 0; i < cache->getNumLinhas(); i++)
	{
		cont[i] = 0;
		min[i] = 0;
		seg[i] = 0;
	}

	for(int i = 0; i < cache->getNumBlocos() * cache->getTamBloco(); i++)
	{
		conteudo[i] = rand() % 100;
	}

	int escolha = 10;

	while(escolha != 0)
	{
		std::cout << "Escolha 1 para read, 2 para show, 0 para sair: " << std::endl;
		std::cin >> escolha;

		if(escolha == 1)
		{
			if(cache->getMapeamento() == 1)
			{
				int palavra;

				std::cout << "Digite a palavra que você deseja buscar: " << std::endl;
				std::cin >> palavra;

				if(palavra < 0)
				{
					return 0;
				}

				else
				{
					Direto(cache, palavra, v);
				}
				
			}

			else if(cache->getMapeamento() == 2)
			{
				int palavra;

				std::cout << "Digite a palavra que você deseja buscar: " << std::endl;
				std::cin >> palavra;

				if(palavra < 0)
				{
					return 0;
				}

				else
				{
					totalmenteAssociativo(cache, palavra, v, cont, min, seg, cheio);
				}				
			}

			else if(cache->getMapeamento() == 3)
			{
				int palavra;

				std::cout << "Digite a palavra que você deseja buscar: " << std::endl;
				std::cin >> palavra;

				if(palavra < 0)
				{
					return 0;
				}

				else
				{
					parcialmenteAssociativo(cache, palavra, v, cont, min, seg, cheio);
				}
			}
		}

		else if(escolha == 2)
		{
			if(cache->getMapeamento() !=3)
				showDiretoTotalmente(cache, v, conteudo);

			else if(cache->getMapeamento() == 3)
				showParcialmente(cache, v, conteudo);
		}

		else
		{
			return 0;
		}
	}
}