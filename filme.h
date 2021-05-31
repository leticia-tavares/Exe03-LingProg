/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 7 - header struct filme
 *
 */

#include <iostream>
#include <string>
#include <iomanip>

#ifndef FILME_H
#define FILME_H

using namespace std;

struct Filme{
  friend class Catalogo;
  friend ostream &operator<< (ostream &, const Filme &); //impressão do filme
  friend istream &operator>> (istream &, Filme &); //inserção de filme

  string nome, produtora;
  double nota;

  //construtor padrão da struct
  //Filme(const string& nome, const string& produtora, double nota) : nome(nome), produtora(produtora), nota(nota){}
  Filme(const string = "", const string = "", double = 0.0);
  
  //operadores de comparação entre filmes
  bool operator< (const Filme &);
  bool operator> (const Filme &);
  bool operator== (const Filme &);

};

#endif
