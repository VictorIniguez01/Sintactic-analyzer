#include "scanner.hpp"
#include "parser.hpp"
#include <iostream>


using namespace std;

   
extern char *yytext;
extern int line;

extern FILE *yyin; 


int main(){

    parser prueba;
    string archivo;

    // test.txt
    printf("Nombre del archivo de texto: "); cin >> archivo;
    yyin = fopen(archivo.c_str(), "r");
    
    if(yyin == nullptr) {
        printf("Archivo no encontrado\n");
        return false;
    }

    if(prueba.LL1()) cout << "ok";
    else printf("Error[%c] en la linea: %i", *yytext, line);

    fclose(yyin);

    return 0;
}