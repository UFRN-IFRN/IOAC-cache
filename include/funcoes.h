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
 * @brief      Inicializa Cache
 * @param[in]  tamanho  Tamanho da Cache
 * @return     Um ponteiro do tamanho das linhas da cache
 */
int* inicializaCache(int tamanho);

/**
 * @brief      Calcula o maior valor dentro de um ponteiro se for Mapeamento Totalmente associativo
 * @param      cache  The cache
 * @param      c      Ponteiro
 * @return     O maior valor
 */
int calculaMaiorDiretoTotalmenteAssociativo(Cache* cache, int* c);

/**
 * @brief      Calcula o maior valor dentro de um ponteiro se for Mapeamento Parcialmente associativo
 * @param      cache  The cache
 * @param      c      Ponteiro
 * @return     O maior valor
 */
int calculaMaiorcalculaMaiorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca);

/**
 * @brief      Calcula o menor valor dentro de um ponteiro
 * @param      cache  The cache
 * @param      c      Ponteiro
 * @return     O menor valor
 */
int calculaMenorDiretoTotalmenteAssociativo(Cache* cache, int* c);

/**
 * @brief      Calcula o menor valor dentro de um ponteiro se for mapeamento parcialmente associativo
 * @param      cache  The cache
 * @param      c      Ponteiro
 * @return     O menor valor
 */
int calculaMenorParcialmenteAssociativo(Cache* cache, int* c, int inicioBusca);

/**
 * @brief      Calcula a menor hora dentro de um ponteiro se for Mapeamento Totalmente Associativo
 * @param      cache  The cache
 * @param      c      Ponteiro de minutos
 * @param      d      Ponteiro de segundos
 * @return     O local aonde está o menor horário ou horário mais velho
 */
int calculaMenorHoraTotalmenteAssociativo(Cache* cache, int* c, int* d);

/**
 * @brief      Calcula a menor hora dentro de um ponteiro se for Mapeamento Parcialmente Associativo
 * @param      cache  The cache
 * @param      c      Ponteiro de minutos
 * @param      d      Ponteiro de segundos
 * @return     O local aonde está o menor horário ou horário mais velho
 */
int calculaMenorHoraParcialmenteAssociativo(Cache* cache, int* c, int* d, int inicioBusca);

/**
 * @brief      Printa a Cache se for Mapeamento direto ou Totalmente Associativo
 * @param      cache  The cache
 * @param      v      Ponteiro da cache
 */
void mostraDiretoTotalmenteAssociativo(Cache* cache, int* v, int* conteudo);

/**
 * @brief      Printa a Cache se for Mapeamento Parcialmente associativo
 * @param      cache  The cache
 * @param      v      Ponteiro da cache
 */
void mostraParcialmenteAssociativo(Cache* cache, int* v, int* conteudo);

/**
 * @brief      Mapeamento direto
 * @param      cache    The cache
 * @param[in]  palavra  The palavra
 * @param      v        Ponteiro da cache
 */
void Direto(Cache* cache, int palavra, int* v);

/**
 * @brief      Mapeamento totalmente associativo
 * @param      cache    The cache
 * @param[in]  palavra  The palavra
 * @param      v        Ponteiro da cache
 * @param      cont     Ponteiro de contadores
 * @param      min      Ponteiro de minutos
 * @param      seg      Ponteiro de segundos
 * @param      cheio    Booleano para dizer se a cache está cheia
 * @return     return 0
 */
int totalmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio);

/**
 * @brief      Mapeamento parcialmente associativo
 * @param      cache    The cache
 * @param[in]  palavra  The palavra
 * @param      v        Ponteiro da cache
 * @param      cont     Ponteiro de contadores
 * @param      min      Ponteiro de minutos
 * @param      seg      Ponteiro de segundos
 * @param      cheio    Booleano para dizer se a cache está cheia
 * @return     return 0
 */
int parcialmenteAssociativo(Cache* cache, int palavra, int* v, int* cont, int* min, int* seg, bool &cheio);

#endif