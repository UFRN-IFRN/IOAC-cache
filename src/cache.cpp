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
Cache::Cache(int tamBloco, int numLinhas, int numBlocos, int mapeamento, int numConjuntos, int politicaSubs)
{
	this->tamBloco = tamBloco;
	this->numLinhas = numLinhas;
	this->numBlocos = numBlocos;
	this->mapeamento = mapeamento;
	this->numConjuntos = numConjuntos;
	this->politicaSubs = politicaSubs;
}

/**
* @brief      Gets o tamanho do bloco.
*
* @return     The tamanho do bloco.
*/
int Cache::getTamBloco()
{
	return this->tamBloco;
}

/**
* @brief      Gets the number linhas.
*
* @return     The number of linhas.
*/
int Cache::getNumLinhas()
{
	return this->numLinhas;
}

/**
* @brief      Gets the number blocos.
*
* @return     The number of blocos.
*/
int Cache::getNumBlocos()
{
	return this->numBlocos;
}

/**
* @brief      Gets o mapeamento.
*
* @return     The mapeamento.
*/
int Cache::getMapeamento()
{
	return this->mapeamento;
}

/**
* @brief      Gets the number conjuntos.
*
* @return     The number of conjuntos.
*/
int Cache::getNumConjuntos()
{
	return this->numConjuntos;
}

/**
* @brief      Gets the politica subs.
*
* @return     The politica subs.
*/
int Cache::getPoliticaSubs()
{
	return this->politicaSubs;
}