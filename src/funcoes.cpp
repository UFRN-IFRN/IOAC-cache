/**
 * @file   funcoes.cpp
 * @brief  Codigo fonte com a implementacao de funcoes de 
 			um simulador cache
 * @author Bianca Santiago (bianca.santiago72@gmail.com)
 * @since  07/06/2017
 * @date   14/06/2017
 */ 	
#include "funcoes.h"

/**
 * @brief Inicializa Cache
 * @param tamanho Tamanho da Cache
 * @return Tamanho das linhas da cache
 */
int* inicializaCache(int tamanho) {
	int *v = new int[tamanho];

	for(int i = 0; i < tamanho; i++) {
		v[i] = -1;
	}
	return v;
}

/**
 * @brief Calcula o maior valor dentro de um ponteiro se for Mapeamento direto ou totalmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O maior valor
 */ 
int calculaMaiorDiretoTotalmenteAssociativo(Cache* cache, int* c) {
	int maior = 0;

	for(int j = 0; j < cache->getNumLinhas(); j++) {
		if(maior < c[j]) maior = c[j];
	}
	return maior;
}

/**
 * @brief Calcula o maior valor dentro de um ponteiro se for Mapeamento Parcialmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O maior valor
 */
int calculaMaiorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca) {
	int maior = 0;

	for(int j = inicioBusca; j < (inicioBusca + (cache->getNumLinhas() / cache->getNumConjuntos())); j++){
		if(maior < c[j]) maior = c[j];
	}
	return maior;
}

/**
 * @brief Calcula o menor valor dentro de um ponteiro se for mapeamento direto ou totalmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O menor valor
 */
int calculaMenorDiretoTotalmenteAssociativo(Cache* cache, int* c){
	int menor = c[0];

	for(int j = 0; j < cache->getNumLinhas(); j++) {
		if(c[j] == 0) return 0;
	}

	for(int i = 1; i < cache->getNumLinhas(); i++) {
		if(c[i] < menor) menor = c[i];
	}
	return menor;
}

/**
 * @brief Calcula o menor valor dentro de um ponteiro se for mapeamento parcialmente associativo
 * @param  cache Cache
 * @param c Ponteiro
 * @return O menor valor
 */
int calculaMenorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca) {
	int menor = c[inicioBusca];

	for(int i = inicioBusca; i < (inicioBusca + (cache->getNumLinhas() / cache->getNumConjuntos())); i++) {
		if(c[i] == 0) return 0;
	}

	for(int i = inicioBusca + 1; i < (inicioBusca + (cache->getNumLinhas() / cache->getNumConjuntos())); i++) {
		if(c[i] < menor) menor = c[i];
	}
	return menor;
}

/**
 * @brief Calcula a menor hora dentro de um ponteiro se for mapeamento Totalmente Associativo
 * @param cache Cache
 * @param c Ponteiro de minutos
 * @param d Ponteiro de segundos
 * @return O local com menor horario ou horario mais antigo
 */
int calculaMenorHoraTotalmenteAssociativo(Cache* cache, int* c, int* d) {
	int menorMin = c[0];
	int menorSeg = d[0];
	int auxMin = 0;
	int retorno = 0;

	for(int i = 1; i < cache->getNumLinhas(); i++) {
		if(menorMin == c[i]) { 
			if(menorSeg < d[i])	retorno = auxMin;
			else if(menorSeg > d[i]) {
				menorMin = c[i];
				menorSeg = d[i];
				auxMin = i;
				retorno = auxMin;
			}
		}
		else if(menorMin < c[i]) retorno = auxMin;
		else if(menorMin > c[i]) {
			menorMin = c[i];
			menorSeg = d[i];
			auxMin = i;
			retorno = auxMin;
		}
	}
	return retorno;
}

/**
 * @brief Calcula a menor hora dentro de um ponteiro se for Mapeamento Parcialmente Associativo
 * @param cache Cache
 * @param c Ponteiro de minutos
 * @param d Ponteiro de segundos
 * @return O local aonde está o menor horário ou horário mais velho
 */
int calculaMenorHoraParcialmenteAssociativo(Cache* cache, int* c, int* d, int inicioBusca) {
	int menorMin = c[inicioBusca];
	int menorSeg = d[inicioBusca];
	int auxMin = inicioBusca;
	int retorno = inicioBusca;

	for(int i = inicioBusca + 1; i < (inicioBusca + (cache->getNumLinhas() / cache->getNumConjuntos())); i++) {
		if(menorMin == c[i]) {
			if(menorSeg < d[i]) retorno = auxMin;
			else if(menorSeg > d[i]) {
				menorMin = c[i];
				menorSeg = d[i];
				auxMin = i;
				retorno = auxMin;
			}
		}
		else if(menorMin < c[i]) retorno = auxMin;
		else if(menorMin > c[i]) {
			menorMin = c[i];
			menorSeg = d[i];
			auxMin = i;
			retorno = auxMin;
		}
	}
	return retorno;
}

/**
 * @brief Mostra a Cache e a Memoria Principal se for Mapeamento direto ou Totalmente Associativo
 * @param cache Cache
 * @param v Ponteiro da cache
 */
void mostraDiretoTotalmenteAssociativo(Cache* cache, int* v, int* conteudo) {
	cout << "CACHE L1" << endl;
	cout << "Linha - Bloco - Endereço - Conteúdo" << endl;

	for(int i = 0; i < cache->getNumLinhas(); i++) {
		if(v[i] == -1) {
			for(int j = 0; j < cache->getTamBloco(); j++) {
				cout << i << " - x - x - x" << endl; 
			}
		}

		else {
			for(int j = 0; j < cache->getTamBloco(); j++) {
				cout << i << " - " << v[i] << " - " << v[i] * cache->getTamBloco() + j << " - " << conteudo[(v[i] * cache->getTamBloco()) + j] << endl;
			}
		}
	}

	cout << "\nMEMORIA PRINCIPAL" << endl;
	cout << "Bloco - Endereço - Conteúdo" << endl;

	for(int i = 0; i < cache->getNumBlocos(); i++) {
		for(int j = 0; j < cache->getTamBloco(); j++) {
			cout << i << " - " << (i * cache->getTamBloco()) + j << " - " << conteudo[(i * cache->getTamBloco()) + j] << endl;
		}
	}
}

/**
 * @brief Mostra a Cache e a Memoria Principal se for Mapeamento Parcialmente associativo
 * @param cache Cache
 * @param v Ponteiro da cache
 */
void mostraParcialmenteAssociativo(Cache* cache, int* v, int* conteudo) {
	cout << "CACHE L1" << endl;
	cout << "Linha - Bloco - Endereço - Conteúdo" << endl;

	int linhasPorVia = cache->getNumLinhas() / cache->getNumConjuntos();

	for(int i = 0; i < cache->getNumLinhas(); i++) {
		if(v[i] == -1) {
			for(int j = 0; j < cache->getTamBloco(); j++) {
				cout << i % linhasPorVia << " - x - x - x" << endl;
			}
		}

		else {
			for(int j = 0; j < cache->getTamBloco(); j++) {
				cout << i % linhasPorVia << " - " << v[i] << " - " << v[i] * cache->getTamBloco() + j << " - " << conteudo[v[i] * cache->getTamBloco() + j] << endl;
			}
		}
	}

	cout << "MEMORIA PRINCIPAL" << endl;
	cout << "Bloco - Endereço - Conteúdo" << endl;

	for(int i = 0; i < cache->getNumBlocos(); i++) {
		for(int j = 0; j < cache->getTamBloco(); j++) {
			cout << i << " - " << (i * cache->getTamBloco()) + j << " - " << conteudo[(i * cache->getTamBloco()) + j] << endl;
		}
	}
}

/**
 * @brief Mapeamento direto
 * @param cache A cache
 * @param palavra A palavra
 * @param v Ponteiro da cache
 */
void Direto(Cache* cache, int palavra, int* v) {
	int bloco = palavra / cache->getTamBloco();
	int linha = bloco % cache->getNumLinhas();

	if(v[linha] == bloco) cout << "HIT: linha " << linha << endl;
	else {
		v[linha] = bloco;
		cout << "MISS -> alocado na linha " << linha << endl;
	}
}

/**
 * @brief Mapeamento totalmente associativo
 * @param cache A cache
 * @param palavra A palavra
 * @param v Ponteiro da cache
 * @param cont Ponteiro de contadores
 * @param min Ponteiro de minutos
 * @param seg Ponteiro de segundos
 * @param cheio Informa se a cache esta cheia
 * @return return 0
 */	
int totalmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio) {	
	int subs = cache->getPoliticaSubs();

	int bloco = palavra / cache->getTamBloco();

	//ALEATORIO
	if(subs == 1) {	
		int linha = rand() % cache->getNumLinhas();

		if(v[linha] == bloco) cout << "HIT: linha " << linha << endl;
		else {
			v[linha] = bloco;
			cout << "MISS -> alocado na linha " << linha << endl;
		}
	}

	//FIFO
	else if(subs == 2) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: linha " << i << endl;
				estaCompleta = true;
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na linha ";

			int maior = calculaMaiorDiretoTotalmenteAssociativo(cache, cont);

			for(int j = 0; j < cache->getNumLinhas(); j++) {
				cont[j] += 1;

				if(maior == 0) {
					v[0] = bloco;
					cout << "0" << endl;
					return 0;
				}

				else if(maior != 0) {
					if(v[j] == -1) {
						v[j] = bloco;
						cout << j << endl;
						if(j == cache->getNumLinhas()-1) cheio = true;
						return 0;
					}
				}
			}

			if(maior != 0 && cheio == true) {
				maior = calculaMaiorDiretoTotalmenteAssociativo(cache, cont);

				for(int i = 0; i < cache->getNumLinhas(); i++) {
					if(cont[i] == maior) {
						v[i] = bloco;
						cont[i] = 1;
						cout << i << endl;
						return 0;
					}
				}				
			}
		}
	}

	//LFU
	else if(subs == 3) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: linha " << i << endl;
				estaCompleta = true;
				cont[i] += 1;
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na linha ";

			int menor = calculaMenorDiretoTotalmenteAssociativo(cache, cont);

			for(int j = 0; j < cache->getNumLinhas(); j++) {
				if(menor == 0) {
					if(v[j] == -1) {
						v[j] = bloco;
						cont[j] += 1;
						cout << j << endl;
						if(j == cache->getNumLinhas()-1) cheio = true;
						return 0;
					}
				}
			}

			menor = calculaMenorDiretoTotalmenteAssociativo(cache, cont);

			if(menor != 0 && cheio == true) {
				int aux = 0;
				int aux2;

				for(int i = 0; i < cache->getNumLinhas(); i++) {
					if(cont[i] == menor) {
						aux += 1;
						aux2 = i; 
					}
				}

				if(aux > 1) {
					for(int i = 0; i < cache->getNumLinhas(); i++) {
						if(cont[i] == menor) {
							v[i] = bloco;
							cont[i] = 1;
							cout << i << endl;
							return 0;
						}
					}
				}

				else if(aux == 1) {
					v[aux2] = bloco;
					cont[aux2] = 1;
					cout << aux2 << endl;
					return 0;
				}
			}
		}
	}

	//LRU
	else if(subs == 4) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: linha " << i << endl;
				estaCompleta = true;

				time_t rawtime1;
			    struct tm* timeinfo;
			    char buffer1 [80];
			    char buffer[80];

			    time (&rawtime1);
			    timeinfo = localtime (&rawtime1);

			    strftime (buffer1,80,"%M.",timeinfo);
			    strftime (buffer,80,"%S.",timeinfo);

			    min[i] = stoi(buffer1);
			    seg[i] = stoi(buffer);
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na linha ";

			int menor = calculaMenorHoraTotalmenteAssociativo(cache, min, seg);

			for(int j = 0; j < cache->getNumLinhas(); j++) {
				if(menor == j) {
					if(v[j] == -1) {
						v[j] = bloco;

						time_t rawtime1;
					    struct tm* timeinfo;
					    char buffer1 [80];
					    char buffer[80];

					    time (&rawtime1);
					    timeinfo = localtime (&rawtime1);

					    strftime (buffer1,80,"%M.",timeinfo);
					    strftime (buffer,80,"%S.",timeinfo);

					    min[j] = stoi(buffer1);
					    seg[j] = stoi(buffer);

						cout << j << endl;

						if(j == cache->getNumLinhas()-1) cheio = true;

						return 0;
					}
				}
			}

			menor = calculaMenorHoraTotalmenteAssociativo(cache, min, seg);

			if(cheio == true) {
				v[menor] = bloco;

				time_t rawtime1;
			    struct tm* timeinfo;
			    char buffer1 [80];
			    char buffer[80];

			    time (&rawtime1);
			    timeinfo = localtime (&rawtime1);

			    strftime (buffer1,80,"%M.",timeinfo);
			    strftime (buffer,80,"%S.",timeinfo);

			    min[menor] = stoi(buffer1);
			    seg[menor] = stoi(buffer);

				cout << menor << endl;

				return 0;				
			}
		}
	}

	return 0;
}

/**
 * @brief Mapeamento parcialmente associativo
 * @param cache A cache
 * @param palavra A palavra
 * @param v Ponteiro da cache
 * @param cont Ponteiro de contadores
 * @param min Ponteiro de minutos
 * @param seg Ponteiro de segundos
 * @param cheio Informa se a cache esta cheia
 * @return return 0
 */
int parcialmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio) {
	int subs = cache->getPoliticaSubs();
	int bloco = palavra / cache->getTamBloco();
	int qtVias = cache->getNumConjuntos();
	int via = bloco % qtVias;
	int linhasPorVia = cache->getNumLinhas() / cache->getNumConjuntos();

	//ALEATÓRIO
	if(subs == 1) {
		via = rand() % qtVias;

		int linha = rand() % linhasPorVia;

		for(int i = 0; i < qtVias; i++) {
			if(via == i) {
				if(v[linha + linhasPorVia*via] == bloco) cout << "HIT: via " << via << " - Linha: " << linha << endl;
				else {
					v[linha + linhasPorVia*via] = bloco;
					cout << "HIT: via " << via << " - Linha: " << linha << endl;
				}
			}
		}
	}

	//FIFO
	else if(subs == 2) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: Via: " << i / linhasPorVia << " - Linha: " << i % linhasPorVia << endl;
				estaCompleta = true;
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na via: " << via << " - Linha: ";

			for(int j = via*linhasPorVia; j < ((via*linhasPorVia) + linhasPorVia); j++) {
				cont[j] += 1;

				if(v[j] == -1) {
					v[j] = bloco;
					cout << j % linhasPorVia << endl;
					if(j == ((via*linhasPorVia) + linhasPorVia)-1) cheio = true;
					return 0;
				}
			}

			if(cheio == true) {
				int maior = calculaMaiorParcialmenteAssociativo(cache, cont, (via*linhasPorVia));

				for(int i = via*linhasPorVia; i < ((via*linhasPorVia) + linhasPorVia); i++) {
					if(cont[i] == maior) {
						v[i] = bloco;
						cont[i] = 1;
						cout << i % linhasPorVia << endl;
						return 0;
					}
				}				
			}
		}
	}

	//LFU
	else if(subs == 3) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: Via: " << i / linhasPorVia << " - Linha: " << i % linhasPorVia << endl;
				estaCompleta = true;
				cont[i] += 1;
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na via: " << via << " - Linha: ";

			for(int j = via*linhasPorVia; j < ((via*linhasPorVia) + linhasPorVia); j++) {
				if(v[j] == -1) {
					v[j] = bloco;
					cont[j] += 1;
					cout << j % linhasPorVia << endl;
					if(j == ((via*linhasPorVia) + linhasPorVia)-1) cheio = true;
					return 0;
				}
			}

			if(cheio == true) {
				int menor = calculaMenorParcialmenteAssociativo(cache, cont, (via*linhasPorVia));
				int aux = 0;
				int aux2;

				for(int i = via*linhasPorVia; i < ((via*linhasPorVia) + linhasPorVia); i++){
					if(cont[i] == menor) {
						aux += 1;
						aux2 = i; 
					}
				}

				if(aux > 1) {
					for(int i = via*linhasPorVia; i < ((via*linhasPorVia) + linhasPorVia); i++) {
						if(cont[i] == menor) {
							v[i] = bloco;
							cont[i] = 1;
							cout << i % linhasPorVia << endl;
							return 0;
						}
					}
				}

				else if(aux == 1) {
					v[aux2] = bloco;
					cont[aux2] = 1;
					cout << aux2 % linhasPorVia << endl;
					return 0;
				}
			}
		}
	}

	//LRU
	else if(subs == 4) {
		bool estaCompleta = false;

		for(int i = 0; i < cache->getNumLinhas(); i++) {
			if(v[i] == bloco) {
				cout << "HIT: Via: " << i / linhasPorVia << " - Linha: " << i % linhasPorVia << endl;
				estaCompleta = true;

				time_t rawtime1;
			    struct tm* timeinfo;
			    char buffer1 [80];
			    char buffer[80];

			    time (&rawtime1);
			    timeinfo = localtime (&rawtime1);

			    strftime (buffer1,80,"%M.",timeinfo);
			    strftime (buffer,80,"%S.",timeinfo);

			    min[i] = stoi(buffer1);
			    seg[i] = stoi(buffer);
			}
		}

		if(!estaCompleta) {
			cout << "MISS -> alocado na via: " << via << " - Linha: ";

			for(int j = via*linhasPorVia; j < ((via*linhasPorVia) + linhasPorVia); j++) {
				if(v[j] == -1) {
					v[j] = bloco;

					time_t rawtime1;
				    struct tm* timeinfo;
				    char buffer1 [80];
				    char buffer[80];

				    time (&rawtime1);
				    timeinfo = localtime (&rawtime1);

				    strftime (buffer1,80,"%M.",timeinfo);
				    strftime (buffer,80,"%S.",timeinfo);

				    min[j] = stoi(buffer1);
				    seg[j] = stoi(buffer);

					cout << j % linhasPorVia << endl;

					if(j == cache->getNumLinhas()-1) cheio = true;

					return 0;
				}				
			}

			int menor = calculaMenorHoraParcialmenteAssociativo(cache, min, seg, (via*linhasPorVia));

			if(cheio == true) {
				v[menor] = bloco;

				time_t rawtime1;
			    struct tm* timeinfo;
			    char buffer1 [80];
			    char buffer[80];

			    time (&rawtime1);
			    timeinfo = localtime (&rawtime1);

			    strftime (buffer1,80,"%M.",timeinfo);
			    strftime (buffer,80,"%S.",timeinfo);

			    min[menor] = stoi(buffer1);
			    seg[menor] = stoi(buffer);

				cout << menor % linhasPorVia << endl;

				return 0;				
			}
		}
	}

	return 0;
}