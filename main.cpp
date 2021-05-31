/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL670 - Linguagens de Programação
 * Prof. Miguel
 * Autor: Leticia Tavares
 * Descricao: Laboratório 7 - arquivo principal
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "catalogo.h"

using namespace std;


/*****************************************************************************************************/

void writeToFile(Catalogo &c){
  ofstream file;
  file.open("catalogo.txt");
  file << c;
  file.close();
}

/*****************************************************************************************************/

void inserirFilme (Catalogo &c){
  Filme fTemp;
  int num, opcao;
  cout<<" Digite 1 para inserir um novo filme ou 2 para inserir mais de um: ";
  cin >> opcao;

  switch (opcao){
        case 1:{
          cin >> fTemp;
          cout <<endl;
          c+= fTemp;
          break;
        }
        case 2:{
          cout << "Quantos filmes deseja inserir? " << endl;
          cin >> num;
          for (int indice = 0; indice < num; indice++){
            cin >> fTemp;
            cout << endl;
            c += fTemp;
          }
          break;
        }
        default:{
          cout << "Entrada inválida! Por favor, tente novamente: "<< endl;
          inserirFilme(c);
        }
  }
}

void removerFilme(Catalogo &c){
  string nomeRemover;
  cout << "Digite o nome do filme a ser removido: ";
  cin.ignore();
  getline(cin, nomeRemover);
  Filme *filme = c(nomeRemover);
  c -= *filme;
}

/*****************************************************************************************************/

int main (){
  int opcao = 0; //default do switch
  Catalogo catalogo;
  ifstream fileRD;
  fileRD.open("catalogo.txt");

  if (!fileRD.is_open()){
    cout << "Erro: arquivo não encontrado." << endl;
    ofstream fileWR;
    fileWR.open("catalogo.txt");
    fileWR << catalogo;
    fileWR.close();
  }

  else{
    catalogo.readFromFile(fileRD);
    fileRD.close();
  }
  cout << "\n\n--------------- G E R E N C I A D O R  D E  C A T Á L O G O ---------------" << endl;

  while(opcao != -1){
    cout << "\n1 - Inserir filme no catálogo" <<endl;
    cout << "\n2 - Remover um filme do catálogo" << endl;
    cout << "\n3 - Buscar filme no catálogo" << endl;
    cout << "\n4 - Atualizar nome de um filme" <<endl;
    cout << "\n5 - Atualizar nome da produtora de um filme" << endl;
    cout << "\n6 - Atualizar nota de um filme" << endl;
    cout << "\n7 - Exibir filme com maior nota" << endl;
    cout << "\n8 - Exibir catálogo por completo" << endl;
    cout << "\n-1 - Terminar programa" << endl;

    cout << "\nEntre com a opção desejada: ";
    cin >> opcao;

    switch(opcao){
      case -1:{ //terminar programa
        cout<< "Salvando dados no arquivo catalogo.txt..."<<endl;
        cout<< "\n--------------- F I M ---------------"<<endl;
        writeToFile(catalogo);
      }
      return 0;
      case 1:{ //inserir filme

        cout<< "\n--------------- INSERIR FILME---------------"<<endl;
        inserirFilme(catalogo);
        cout << endl;

        cout << "------------------------------" << endl;
        break;
      }
      case 2:{//remover filme
        cout<< "\n--------------- REMOVER FILME ---------------"<<endl;
        removerFilme(catalogo);
        cout << endl;
        cout << "------------------------------" << endl;
        break;
      }
      case 3:{ //buscar filme no catálogo
        cout<< "\n--------------- BUSCAR FILME ---------------"<<endl;
        string nome;
        cout<< "Digite o nome do filme que deseja buscar: ";
        cin.ignore();
        getline (cin, nome);

        Filme *filme = catalogo(nome);
        if (filme != NULL) {
          cout<< *filme << endl;
        }
        else{
          cout << "Não existe no catálogo." << endl;
        }
        cout << "------------------------------" << endl;
        break;
      }
      case 4:{//atualizar nome de um filme
        cout<< "\n--------------- ATUALIZAR NOME---------------"<<endl;
        string nomeAtual, novoNome;
        cout<< "Insira o nome do filme que queira editar: ";
        cin.ignore();
        getline (cin,nomeAtual);
        cout<< "Insira o novo nome do filme: ";
        getline(cin, novoNome);

        catalogo(nomeAtual,novoNome);
        cout << "------------------------------" << endl;
        break;
      }
      case 5:{ //atualizar nome da produtora
        cout<< "\n--------------- ATUALIZAR PRODUTORA ---------------"<<endl;
        string nomeAtual, produtoraNova;
        cout<< "Insira o nome do filme que queira editar: ";
        cin.ignore();
        getline (cin,nomeAtual);
        cout<< "Insira a nova produtora do filme: ";
        getline(cin, produtoraNova);
        catalogo(nomeAtual,produtoraNova, 1);
        cout << "------------------------------" << endl;
        break;
      }
      case 6:{ //atualizar nota
        cout<< "\n--------------- ATUALIZAR NOTA ---------------"<<endl;
        string nomeAtual;
        double novaNota;
        cout<< "Insira o nome do filme que queira editar: ";
        cin.ignore();
        getline (cin,nomeAtual);
        cout << endl;
        cout<< "Insira a nova nota do filme: " << endl;

        cout << endl;
        cin >> novaNota;

        catalogo(nomeAtual, novaNota);
        cout << "------------------------------" << endl;
        break;
      }
      case 7:{ //buscar filme com maior nota
        cout<< "\n--------------- MAIOR NOTA ---------------"<<endl;
        cout << *(catalogo.filmeComMaiorNota());
        cout << "------------------------------" << endl;
        break;
      }
      case 8:{ //exibir catálogo
        cout<< "\n--------------- CATÁLOGO ---------------"<<endl;
        cout << catalogo;
        cout << "------------------------------" << endl;
        break;
      }
      default:{
        cout << "Entrada inválida! Por favor, tente novamente:" << endl;
        cin >> opcao;
      }
    }
  }
  cout<< "\nSalvando dados no arquivo catalogo.txt..."<<endl;
  writeToFile(catalogo);

  return 0; //OK
}
