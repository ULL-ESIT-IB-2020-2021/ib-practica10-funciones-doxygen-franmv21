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
 * @see http://www.cplusplus.com/reference/cctype/isalpha/
 * 
 */

#include <iostream>
#include <string>
#include <cstring>
#include "funciones_cripto.h"
using namespace std;

void Usage(int argc, char* argv[]){
  if(argc <= 1){
    cout << argv[0] << " -- Cifrado de ficheros" << endl;
    cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << endl;
    cout << "Pruebe " << argv[0] << " --help para más información" << endl;
    exit(EXIT_SUCCESS);
  }
  string parametro{argv[1]};
  if(parametro == "--help"){
    cout << argv[0] << " -- Cifrado de ficheros" << endl;
    cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << endl << endl;
    cout << "fichero_entrada: Fichero a codificar" << endl;
    cout << "fichero_salida:  Fichero codificaco" << endl;
    cout << "método:          Indica el método de encriptado" << endl;
    cout << "                   1: Cifrado XOR" << endl;
    cout << "                   2: Cifrado César" << endl;
    cout << "password:        Letra (mayúscula) secreta en el caso del método 1, Valor de K en el método 2" << endl;
    cout << "operación:       Operación a realizar en el fichero" << endl;
    cout << "                   +: encriptar el fichero" << endl;
    cout << "                   -: desencariptar el fichero" << endl;
    exit(EXIT_SUCCESS);
  }
}    

string XOR(string texto) {
    char clave = 'F';                   ///Solo funciona con letras mayúsculas y no usa la clave introducida por línea de comandos.
    string salida = texto;
    
    for (int i = 0; i < salida.size(); i++)
        salida[i] = salida[i] ^ clave;
    return salida;
}

string CesarEncriptar(string texto, int clave){
  string resultado = "";
  for(int i = 0; i <texto.length(); i++){  
      if(isalpha(texto[i])){
        if(isupper(texto[i])){
          resultado = resultado + char((int(texto[i]+ clave - 'A') % 26) + 'A');
        }   else {
          resultado = resultado + char((int(texto[i]+ clave - 'a') % 26) + 'a');
            }
      }
  }
  return resultado;
}

string CesarDesencriptar(string texto, int clave){
  string resultado = "";
  for(int i = 0; i <texto.length(); i++){
    if(isalpha(texto[i])){
      if(isupper(texto[i])){
      resultado = resultado + char((int(texto[i]- clave - 'A') % 26) + 'A');
    } else {
      resultado = resultado + char((int(texto[i]- clave - 'a') % 26) + 'a');
      }
    } 
  } 
  return resultado;
}
