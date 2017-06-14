/**
 * @file  files.h
 * @brief Arquivo cabecalho com a definicao de funcoes para leitura do 
          arquivo com os dados de entrada
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @since 07/06/2017
 * @date  14/06/2017
 */  
#ifndef FILE_IO_H
#define FILE_IO_H

#include "cache.h"
#include <iostream>
#include <fstream>

/**
 * @brief      Função que lê arquivo e joga numa variável do tipo Cache
 *
 * @param[in]  arq   Arquivo
 *
 * @return     Uma Cache
 */
Cache* ler_arquivo(std::string arq);


#endif