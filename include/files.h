/**
 * @file  files.h
 * @brief Arquivo cabecalho com a definicao de funcoes para leitura do 
          arquivo com os dados de entrada
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @since 07/06/2017
 * @date  14/06/2017
 */  
#ifndef FILES_H
#define FILES_H

#include "cache.h"
#include <iostream>
#include <fstream>

/**
 * @brief Funcao que le arquivo e joga numa variavel do tipo Cache
 * @param file Arquivo
 * @return Uma Cache
 */
Cache* lerArquivo(std::string file);

#endif