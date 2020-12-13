/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Francisco F. Martín Vide
 * @date 8.diciembre.2020
 * @brief La finalidad de este programa será encriptar y/o desencriptar ficheros de texto mediante dos métodos 
 *        (Encriptado de xor o Cifrado de César) e imprimir el contenido resultante en otro fichero de texto.
 * @see stoi http://www.cplusplus.com/reference/string/stoi/
 * @see https://www.learncpp.com/cpp-tutorial/186-basic-file-io/
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "funciones_cripto.h"
using namespace std;

int main(int argc, char* argv[]){
  Usage(argc, argv);
  
  string operacion{argv[5]};
  string metodo{argv[3]};
  
  /*string clave{argv[4]};
  char cstr[clave.size() + 1];
  strcpy(cstr, clave.c_str());*/


  string strEntrada;

  ifstream fichero_entrada;
  fichero_entrada.open({argv[1]});

  ofstream fichero_salida;
  fichero_salida.open({argv[2]});

  if (!fichero_entrada){
    cerr << "Uh oh, " << argv[1] << " no se pudo abrir." << endl;
    return 1;
  }

    getline(fichero_entrada, strEntrada);
    string textoaencriptar = strEntrada;
    char* caracter = &*textoaencriptar.begin();
    cout << "Texto a encriptar: " << caracter << endl;
  
    if(metodo == "1" && operacion == "+"){
      cout << "Texto encriptado: " << XOR(strEntrada) << endl;
      fichero_salida << XOR(strEntrada);
      fichero_salida.close();

    } 
    if(metodo == "1" && operacion == "-"){
      cout << "Texto desencriptado: " << XOR(strEntrada) << endl;
      fichero_salida << XOR(strEntrada);
      fichero_salida.close();

    }
    if(metodo == "2" && operacion == "+"){
      int clave = stoi(argv[4]);
      cout << "Texto encriptado: " << CesarEncriptar(strEntrada, clave) << endl;
      fichero_salida << CesarEncriptar(caracter, clave);
      fichero_salida.close();
    }

    if(metodo == "2" && operacion == "-"){
      int clave = stoi(argv[4]);
      cout << "Texto desencriptado: " << CesarDesencriptar(strEntrada, clave) << endl;
      fichero_salida << CesarDesencriptar(caracter, clave);
      fichero_salida.close();
    }
  
}