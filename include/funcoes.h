/**
 * @file   funcoes.h
 * @brief  Arquivo cabecalho com a definicao de funcoes de 
 			um simulador cache
 * @author Bianca Santiago (bianca.santiago72@gmail.com)
 * @since  07/06/2017
 * @date   14/06/2017
 */ 	
#ifndef FUNCOES_H
#define FUNCOES_H

#include "cache.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

/**
 * @brief Inicializa Cache
 * @param tamanho Tamanho da Cache
 * @return Tamanho das linhas da cache
 */
int* inicializaCache(int tamanho);

/**
 * @brief Calcula o maior valor dentro de um ponteiro se for Mapeamento direto ou totalmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O maior valor
 */ 
int calculaMaiorDiretoTotalmenteAssociativo(Cache* cache, int* c);

/**
 * @brief Calcula o maior valor dentro de um ponteiro se for Mapeamento Parcialmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O maior valor
 */
int calculaMaiorcalculaMaiorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca);

/**
 * @brief Calcula o menor valor dentro de um ponteiro se for mapeamento direto ou totalmente associativo
 * @param cache Cache
 * @param c Ponteiro
 * @return O menor valor
 */
int calculaMenorDiretoTotalmenteAssociativo(Cache* cache, int* c);

/**
 * @brief Calcula o menor valor dentro de um ponteiro se for mapeamento parcialmente associativo
 * @param  cache Cache
 * @param c Ponteiro
 * @return O menor valor
 */
int calculaMenorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca);

/**
 * @brief Calcula a menor hora dentro de um ponteiro se for mapeamento Totalmente Associativo
 * @param cache Cache
 * @param c Ponteiro de minutos
 * @param d Ponteiro de segundos
 * @return O local com menor horario ou horario mais antigo
 */
int calculaMenorHoraTotalmenteAssociativo(Cache* cache, int* c, int* d);

/**
 * @brief Calcula a menor hora dentro de um ponteiro se for Mapeamento Parcialmente Associativo
 * @param cache Cache
 * @param c Ponteiro de minutos
 * @param d Ponteiro de segundos
 * @return O local aonde está o menor horário ou horário mais velho
 */
int calculaMenorHoraParcialmenteAssociativo(Cache* cache, int* c, int* d, int inicioBusca);

/**
 * @brief Mostra a Cache e a Memoria Principal se for Mapeamento direto ou Totalmente Associativo
 * @param cache Cache
 * @param v Ponteiro da cache
 */
void mostraDiretoTotalmenteAssociativo(Cache* cache, int* v, int* conteudo);

/**
 * @brief Mostra a Cache e a Memoria Principal se for Mapeamento Parcialmente associativo
 * @param cache Cache
 * @param v Ponteiro da cache
 */
void mostraParcialmenteAssociativo(Cache* cache, int* v, int* conteudo);

/**
 * @brief Mapeamento direto
 * @param cache A cache
 * @param palavra A palavra
 * @param v Ponteiro da cache
 */
void Direto(Cache* cache, int palavra, int* v);

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
int totalmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio);

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
int parcialmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio);

#endif