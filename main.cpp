// Resaltador de Sintaxis
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Token.h"

// Variables Globales
std::vector<std::string> COMENTARIOS 
{ "//" };

std::vector<std::string> PALABRAS_RESERVADAS 
{ "if", "else", "do", "while", "break", "return" };

std::vector<std::string> OPERADORES 
{ "+", "-", "++", "--", "*", "**", "/", "%" };

std::vector<std::string> ASIGNACION 
{ "=" };

std::vector<std::string> COMPARADORES_BOOLEANOS 
{ "==", "&&", "||", "!=" };

std::vector<std::string> LIMITE 
{ ";" };

// Metodos Auxiliares
void print_256_colours_txt()
{
    for (int i = 0; i < 256; i++)
    {
        if (i % 16 == 0 && i != 0)
            std::cout << std::endl;
        printf("\033[38;5;%dm %3d\033[m", i, i);
    }
}

void print_color(std::string word, int color) {
	
}

Token siguiente_token(std::string cadena) {
    std::string token = "";
    Token res;

    return res;
}

std::vector<std::string> cadenas_en_linea (std::string linea) {
    std::vector<std::string> lista_palabras;
    std::string cadena = "";

    for (char letra : linea) {
        if (cadena == "//") {
            // Ignorando comentario
            cadena = "";
            break;
        }
        else if (letra != ' ' && letra != 9) {
            cadena += letra;
        }
        else {
            if (cadena != "") {
                lista_palabras.push_back(cadena);
                cadena = "";
            }
        }
    }
    if (cadena != "") {
        lista_palabras.push_back(cadena);
        cadena = "";
    }

    return lista_palabras;
}

std::vector<Token> analisis_lexico(std::string nombre_archivo) {
    // Lisat de tokens por regresar
    std::vector<Token> lista_tokens;
    std::vector<std::string> cadenas;

    // Leyendo desde archivo
    std::ifstream Lector(nombre_archivo);
    std::string linea;

    // Revisando las lineas del programa
    while (std::getline(Lector, linea))
    {
        cadenas = cadenas_en_linea(linea);
        for (std::string cadena : cadenas) {
            std::cout << cadena << std::endl;
        }
    }
    return lista_tokens;
}

int main(int argc, char const *argv[])
{
    std::string nombre_archivo = "programa.txt";
    analisis_lexico(nombre_archivo);

    
    // Lectura de codigo desde archivo
	std::cout << "Hello world" << std::endl;
    // printf("\033[38;5;%dm %3d\033[m", 118, 'a');
    Token if_tk;
    if_tk.print();

    return 0;
}
