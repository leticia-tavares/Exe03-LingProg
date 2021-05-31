/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 7 - implementação da struct filme
 *
 */

#include "filme.h"

using namespace std;

/*****************************************************************************/

ostream &operator<<(ostream &out, const Filme &filme){
  out << "Nome: " << filme.nome << endl << "Produtora: " << filme.produtora << endl << "Nota: " << filme.nota << endl;
  return out;
}

/*****************************************************************************/

istream &operator>> (istream &in, Filme &filme){
  cout << "Nome: ";
  in.ignore();

  getline(in, filme.nome);
  cout << "Produtora: ";
  getline(in, filme.produtora);
  cout << "Nota: ";
  in >> filme.nota;
  return in;
}

Filme::Filme(string nome, string produtora, double nota):nome(nome), produtora(produtora), nota(nota){};
/*****************************************************************************/

bool Filme::operator< (const Filme &filme2){
  if ((*this).nome < filme2.nome){
    return true;
  }
  return false;
}

/*****************************************************************************/

bool Filme::operator> (const Filme &filme2){
  if ((*this).nome > filme2.nome){
    return true;
  }
  return false;
}

/*****************************************************************************/

bool Filme::operator== (const Filme &filme2){
  if ((*this).nome == filme2.nome){
    return true;
  }
  return false;
}
