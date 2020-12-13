/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Francisco F. Martín Vide
 * @date 8.diciembre.2020
 * @brief Este archivo declara cuatro funciones
 */

#include <iostream>
#include <string>
using namespace std;


void Usage(int argc, char* argv[]);
string XOR(string texto);
string CesarEncriptar(string texto, int clave);
string CesarDesencriptar(string texto, int clave);