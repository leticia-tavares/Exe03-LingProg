/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 7 - implementação da classe catalogo
 *
 */

#include "catalogo.h"

using namespace std;

/*****************************************************************************/

ostream &operator<< (ostream &out, const Catalogo &c) { //impressão do catálogo
    for (size_t i = 0; i < c.getFilmesDoCatalogo().size(); i++){
      out << c.getFilmesDoCatalogo().at(i) << endl;
    }
    return out;
}

/*****************************************************************************/

Catalogo::Catalogo(){//construtor da classe
}

/*****************************************************************************/

Catalogo& Catalogo::operator+= (Filme &novoFilme) { //inserção de filme
  if (filmesDoCatalogo.size() == maxFilmes){
    cout << "Catálogo cheio!" << endl;
    return *this;
  }
  if ( (*this)(novoFilme.nome) != NULL){
    cout << "Filme \"" <<novoFilme.nome << " \" já existe no Catálogo!" <<endl;
    return *this;
  }
  for (size_t i = 0; i < filmesDoCatalogo.size(); i++){
      if (novoFilme < filmesDoCatalogo.at(i)){
        filmesDoCatalogo.insert(filmesDoCatalogo.begin() + i, 1,novoFilme);
        return *this;
      }
  }
  filmesDoCatalogo.push_back(novoFilme);

  return *this;
}

/*****************************************************************************/

Catalogo& Catalogo::operator+= (vector <Filme> &vetorNovo){//inserção de um vetor de filmes
  for (size_t i = 0; i < vetorNovo.size(); i++){
    *this += vetorNovo.at(i);
  }
  return *this;
}

/*****************************************************************************/

Catalogo& Catalogo::operator-= (Filme &removerFilme){//remoção de filme

  if (filmesDoCatalogo.size() == 0){
    cout << "Catálogo vazio!" << endl;
    return *this;
  }
  if ((*this)(removerFilme.nome) == NULL){
    cout <<"Filme " << removerFilme.nome << "não existe neste Catálogo!" << endl;
    return *this;
  }
  for (size_t i = 0; i < filmesDoCatalogo.size(); i++){
    if (filmesDoCatalogo.at(i)== removerFilme){
      string nome = removerFilme.nome;
      filmesDoCatalogo.erase(filmesDoCatalogo.begin() + i);
      cout << "Filme \"" << nome << " \" removido do Catálogo!" <<endl;
      return *this;
    }
  }
  return *this;
}

/*****************************************************************************/

Filme *Catalogo::operator()(const string nomeFilme){ //operador de busca de filme no catálogo a partir do nome
  for (size_t i = 0; i < filmesDoCatalogo.size(); i++){
    if (nomeFilme == filmesDoCatalogo.at(i).nome){
      return &filmesDoCatalogo.at(i);
    }
  }
  return NULL;
}

/*****************************************************************************/

Filme *Catalogo::operator()(const string nomeFilme, const string novoNome){
  string nomeProdutora;
  double notaFilme;

  if ((*this)(nomeFilme) == NULL){
    cout << "Filme não existe no Catálogo!"<< endl;
  }
  else{
    nomeProdutora = (*this)(nomeFilme)->produtora;
    notaFilme = (*this)(nomeFilme)->nota;

    //remover o filme atual e cria um novo
    Filme velho;
    velho = *(*this)(nomeFilme);
    Filme filme;

    (*this) -= velho;
    filme.nome = novoNome;
    filme.produtora = nomeProdutora;
    filme.nota = notaFilme;
    (*this) += filme;

    return (*this)(filme.nome);

  }
  return NULL;
}

/*****************************************************************************/

//operadores de atualização de filme
Filme *Catalogo::operator()(const string nomeFilme, const string nomeProdutora, int fazNada){
  fazNada++; //apenas para mudar o protótipo da função
  if ((*this)(nomeFilme) == NULL){
    cout << "Filme não existe no Catálogo!"<< endl;
  }
  else {
    (*this)(nomeFilme)->produtora = nomeProdutora;
    return (*this)(nomeFilme);
  }
  return NULL;
}

/*****************************************************************************/

Filme *Catalogo::operator()(const string nomeFilme, const double notaFilme){
  if ((*this)(nomeFilme) == NULL){
    cout << "Filme não existe no Catálogo!"<< endl;
  }
  else {
    (*this)(nomeFilme)->nota = notaFilme;
    return (*this)(nomeFilme);
  }
  return NULL;
}

/*****************************************************************************/

Filme *Catalogo::filmeComMaiorNota(){
  double notaMax = 0;
  int posNotaMax = 0;
  if(filmesDoCatalogo.size() == 0){
    cout << "Catálogo vazio!" << endl;
    return NULL;
  }
  for (unsigned pos = 0; pos < filmesDoCatalogo.size(); pos++){
    if (filmesDoCatalogo.at(pos).nota > notaMax){
      notaMax = filmesDoCatalogo.at(pos).nota;
      posNotaMax = pos;
    }
  }
  return &filmesDoCatalogo.at(posNotaMax);
}

/*****************************************************************************/

vector <Filme> Catalogo::getFilmesDoCatalogo() const{
  return filmesDoCatalogo;
}

/*****************************************************************************/

const int Catalogo::getNumeroMaxFilmes(){
  return maxFilmes;
}

/*****************************************************************************/

void Catalogo::readFromFile(ifstream &file){
  string tempNome, tempProdutora, buffer;
  double tempNota;
  int counter = 0;

  while(getline(file, buffer)){
    size_t pos = buffer.find_first_of(" ");
    buffer.erase(buffer.begin(), buffer.begin() + pos + 1);

    if (buffer != ""){
      if (counter == 0){
        tempNome = buffer;
        counter++;
      }else if (counter == 1){
        tempProdutora = buffer;
        counter++;
      }
      else{
        tempNota = stod(buffer);
        Filme filme(tempNome, tempProdutora, tempNota);
        (*this) += filme;
        counter = 0;
      }
    }
  }
}
