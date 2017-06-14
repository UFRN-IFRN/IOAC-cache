/**
 * @file	cache.cpp
 * @brief	Codigo fonte com a implementacao de um simulador cache
 * @author	Bianca Santiago (bianca.santiago72@gmail.com)
 * @since	07/06/2017
 * @date	14/06/2017
 */
#include "cache.h"
#include <iostream>

/**
* @brief      Construtor
*/	
Cache::Cache(int tamBloco, int numLinhas, int numBlocos, int mapeamento, int numConjuntos, int politicaSubs) {
	this->tamBloco = tamBloco;
	this->numLinhas = numLinhas;
	this->numBlocos = numBlocos;
	this->mapeamento = mapeamento;
	this->numConjuntos = numConjuntos;
	this->politicaSubs = politicaSubs;
}

/**
* @brief Pega o tamanho do bloco.
* @return Tamanho do bloco.
*/
int Cache::getTamBloco(){
	return this->tamBloco;
}

/**
* @brief Pega o numero linhas.
* @return Numero linhas.
*/
int Cache::getNumLinhas() {
	return this->numLinhas;
}

/**
* @brief Pega o numero de blocos.
* @return Numero de blocos.
*/
int Cache::getNumBlocos() {
	return this->numBlocos;
}

/**
* @brief Pega o mapeamento.
* @return Mapeamento.
*/
int Cache::getMapeamento() {
	return this->mapeamento;
}

/**
* @brief Pega o numero de conjuntos.
* @return Numero de conjuntos.
*/
int Cache::getNumConjuntos() {
	return this->numConjuntos;
}

/**
* @brief Pega a politica de substituicao.
* @return Politica de substituicao.
*/
int Cache::getPoliticaSubs() {
	return this->politicaSubs;
}