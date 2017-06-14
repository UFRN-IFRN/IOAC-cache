/**
 * @file  files.cpp
 * @brief Codigo fonte com a implementacao de funcoes para leitura do 
          arquivo com os dados de entrada
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @since 07/06/2017
 * @date  14/06/2017
 */   
#include "files.h"

/**
 * @brief Funcao que le arquivo e joga numa variavel do tipo Cache
 * @param file Arquivo
 * @return Uma Cache
 */
Cache* lerArquivo(std::string file){
	std::string linha;

  	std::ifstream input_file;

  	input_file.open(file, std::ios::in); 

  int tamBloco;
	int numLinhas;
	int numBlocos;
	int mapeamento;
	int numConjuntos;
	int politicaSubs;

  	int cont = 0;

  	if(input_file.is_open()) { 		
  		while(std::getline(input_file, linha)) {
  			if(cont % 6 == 0) tamBloco = std::stoi(linha);
  			else if(cont % 6 == 1) numLinhas = std::stoi(linha);
  			else if(cont % 6 == 2) numBlocos = std::stoi(linha);
  			else if(cont % 6 == 3) mapeamento = std::stoi(linha);
  			else if(cont % 6 == 4) numConjuntos = std::stoi(linha);
  			else if(cont % 6 == 5) {
  				politicaSubs = std::stoi(linha);
  				Cache* cache = new Cache(tamBloco, numLinhas, numBlocos, mapeamento, numConjuntos, politicaSubs);
  				return cache;
  			}
  			cont++;
	  	} 	
	  	input_file.close(); 
  	} 	

  	else std::cout << "ALGO DEU ERRADO. IMPOSSÍVEL ABRIR O ARQUIVO:" << file << std::endl;

  	return NULL;
}