/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 7 - header da classe catalogo
 *
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

#include "filme.h"

#ifndef CATALOGO_H
#define CATALOGO_H

using namespace std;


class Catalogo{
  friend ostream &operator<<(ostream &, const Catalogo &); //impressão do catálogo inteiro de filmes
  friend ostream &operator<<(ostream &, const Filme &);

  public:
    Catalogo(); //construtor da classe

    Catalogo& operator+= (Filme &); //inserção de filme
    Catalogo& operator+= (vector <Filme> &); //inserção de um vetor de filmes
    Catalogo& operator-= (Filme &);  //remoção de filme

    Filme *operator()(const string); //operador de busca de filme no catálogo
    Filme *operator()(const string, const string); //operador de atualização de filme

    //operadores de atualização de filme
    Filme *operator()(const string, const string, int);
    Filme *operator()(const string, const double);

    Filme *filmeComMaiorNota();

    const int getNumeroMaxFilmes();
    vector <Filme> getFilmesDoCatalogo() const;

    //funções de leitura e escruta do arquivo txt
    void readFromFile(ifstream &);
    //void writeToFile(Catalogo &);

  private:
    static const int maxFilmes = 5;
    vector <Filme> filmesDoCatalogo;
};

#endif
