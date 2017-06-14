/**
 * @file	cache.cpp
 * @brief	Arquivo cabecalho com a implementacao de um simulador cache
 * @author	Bianca Santiago (bianca.santiago72@gmail.com)
 * @since	07/06/2017
 * @date	14/06/2017
 */
#ifndef CACHE_H
#define CACHE_H

/**
 * @class Cache
 * @brief Classe para Cache.
 */
class Cache {
	private:

		/**
		 * Tamanho do bloco
		 */
		int tamBloco;
		
		/**
		 * Numero de linhas na Cache
		 */
		int numLinhas;
		
		/**
		 * Numeros de blocos na memoria
		 */
		int numBlocos;

		/**
		 * Tipo de mapeamento(direto, totalmente associativo ou parcialmente associativo)
		 */
		int mapeamento;

		/**
		 * Numero de conjuntos  (se for mapeamento parcialmente associativo)
		 */
		int numConjuntos;

		/**
		 * tipo de politica de substituicao (aleatorio, fifo, lfu ou lru)
		 */
		int politicaSubs;

	public:

		/**
		 * @brief      Construtor
		 */	
		Cache(int tamBloco, int numLinhas, int numBlocos, int mapeamento, int numConjuntos, int politicaSubs);

		/**
		 * @brief Pega o tamanho do bloco.
		 * @return Tamanho do bloco.
		 */
		int getTamBloco();

		/**
		 * @brief Pega o numero de linhas.
		 * @return Numero de linhas.
		 */
		int getNumLinhas();

		/**
		 * @brief Pega o numero de blocos.
		 * @return O numero de blocos.
		 */
		int getNumBlocos();

		/**
		 * @brief Pega o mapeamento.
		 * @return Mapeamento.
		 */
		int getMapeamento();

		/**
		 * @brief Pega o numero de conjuntos.
		 * @return Numero de conjuntos.
		 */
		int getNumConjuntos();

		/**
		 * @brief Pega a politica substituicao.
		 * @return Politica de substituicao.
		 */
		int getPoliticaSubs();
};

#endif