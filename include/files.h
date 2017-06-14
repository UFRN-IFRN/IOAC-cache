/**
 * @file   files.h
 * @brief  Arquivo cabecalho com a definicao de funcoes para leitura do 
          	arquivo com os dados de entrada
 * @author Bianca Santiago (bianca.santiago72@gmail.com)
 * @since  07/06/2017
 * @date   14/06/2017
 */  
#ifndef FILES_H
#define FILES_H

#include "cache.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
#include <fstream>
using std::ifstream;
using std::string;
using std::getline;

/**
 * @brief Funcao que le arquivo e joga numa variavel do tipo Cache
 * @param file Arquivo
 * @return Uma Cache
 */
Cache* lerArquivo(string file);

#endif