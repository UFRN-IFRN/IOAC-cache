# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor o codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

#Objetos
OBJS = main.o cache.o files.o funcoes.o

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc gnuplot run

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init cache
debug: CFLAGS += -g -O0
debug: cache

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define os arquivos main.o cache.o files.o funcoes.o como dependencias
cache: $(OBJ_DIR)/main.o $(OBJ_DIR)/cache.o $(OBJ_DIR)/files.o $(OBJ_DIR)/funcoes.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@.exe $^
	@echo "+++ [Executavel 'cache.exe' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto cache.o
# Define os arquivos cache.cpp e cache.h como dependencias.
$(OBJ_DIR)/cache.o: $(SRC_DIR)/cache.cpp $(INC_DIR)/cache.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto files.o
# Define os arquivos files.cpp e files.h como dependencias.
$(OBJ_DIR)/files.o: $(SRC_DIR)/files.cpp $(INC_DIR)/files.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto funcoes.o
# Define os arquivos funcoes.cpp e funcoes.h como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/funcoes.cpp $(INC_DIR)/funcoes.h 
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
#doxy:
#	$(RM) $(DOC_DIR)/*
#	doxygen -g

#doc:
#	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*
	$(RM) $(DAT_DIR)/output/*
