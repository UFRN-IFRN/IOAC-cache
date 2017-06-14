/**
 * @file 	   cache.h
 * @brief      Definição da classe Cache
 * @author     Bruno Matheus de Lima Cabral
 */
#ifndef CACHE_H
#define CACHE_H

/**
 * @class 	   Cache
 * @brief      Classe para Cache.
 */
class Cache
{
	private:
		/**
		 * Quantas palavras cabem no bloco
		 */
		int tamBloco;
		/**
		 * Número de linhas na Cache
		 */
		int numLinhas;
		/**
		 * Números de blocos na memória
		 */
		int numBlocos;
		/**
		 * Mapeamento(direto, totalmente e parcialmente associativo)
		 */
		int mapeamento;
		/**
		 * Número de conjuntos se for parcialmente associativo
		 */
		int numConjuntos;
		/**
		 * ALEATORIO, FIFO, LFU OU LRU
		 */
		int politicaSubs;

	public:
		/**
		 * @brief      Construtor
		 */	
		Cache(int tamBloco, int numLinhas, int numBlocos, int mapeamento, int numConjuntos, int politicaSubs);

		/**
		 * @brief      Gets o tamanho do bloco.
		 *
		 * @return     The tamanho do bloco.
		 */
		int getTamBloco();

		/**
		 * @brief      Gets the number linhas.
		 *
		 * @return     The number of linhas.
		 */
		int getNumLinhas();

		/**
		 * @brief      Gets the number blocos.
		 *
		 * @return     The number of blocos.
		 */
		int getNumBlocos();

		/**
		 * @brief      Gets o mapeamento.
		 *
		 * @return     The mapeamento.
		 */
		int getMapeamento();

		/**
		 * @brief      Gets the number conjuntos.
		 *
		 * @return     The number of conjuntos.
		 */
		int getNumConjuntos();

		/**
		 * @brief      Gets the politica subs.
		 *
		 * @return     The politica subs.
		 */
		int getPoliticaSubs();
};

#endif