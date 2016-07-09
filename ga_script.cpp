/* 
 * File:   ga_script.cpp
 * Author: macbook
 *
 * Created on 4 de julio de 2016, 23:49
 */

#include <iostream>
#include <cstdlib>
#include <bitset>
#include <time.h>

//Tamaño de la poblacion
#define P_LENGTH 10
//Largo del array de cromosomas
#define C_LENGTH 5
//Número máximo de soluciones a encontrar
#define C_MAX 31

/*
 * Estructura para cada sujeto de la poblacion
 */
typedef struct {
    unsigned int sujeto_id;
    char cromosomas[C_LENGTH];
    unsigned int x;
    unsigned int f_x;
}EstructuraPoblacion;

//Función que genera la población inicial
void ini_poblacion(EstructuraPoblacion *poblacion);
//Función para mostrar la población generada
void muestra_poblacion(EstructuraPoblacion *poblacion);

//Función para generar los cromosomas que representan una solución (individuo)
void genera_cromosomas(unsigned int x, char *cromosomas);
//Función para determinar el valor de X
unsigned int f_x(unsigned int x);
//Función para generar un número aleatorio
unsigned int ranged_rand(int min, int max);

//Funcion main
int main(int argc, char** argv) {
    srand(time(NULL));
    EstructuraPoblacion  poblacion[P_LENGTH];
    ini_poblacion(poblacion);
    muestra_poblacion(poblacion);
    return 0;
}

void muestra_poblacion(EstructuraPoblacion *poblacion){
    for(int i = 0; i < P_LENGTH; i++){
        std::cout << "SUJETO ID >> " << poblacion[i].sujeto_id << std::endl;
        std::cout << "X >> " << poblacion[i].x << std::endl;
        std::cout << "F(X) >> " << poblacion[i].f_x << std::endl;
        std::cout << "CROMOSOMAS >> " << poblacion[i].cromosomas << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ini_poblacion(EstructuraPoblacion *poblacion){
    for(int i = 0; i < P_LENGTH; i++){
        poblacion[i].sujeto_id = i + 1;
        poblacion[i].x = ranged_rand(1, C_MAX);
        poblacion[i].f_x = f_x(poblacion[i].x);
        genera_cromosomas(poblacion[i].x, poblacion[i].cromosomas);
    }
}

void genera_cromosomas(unsigned int x, char *cromosomas){
    strlcpy(cromosomas, std::bitset<C_LENGTH>(x).to_string().c_str(), sizeof(cromosomas));
}

unsigned int f_x(unsigned int x){
    return x * x;
}

unsigned int ranged_rand(int min, int max){
    return min + ((int)(max - min) * (rand() / (RAND_MAX + 1.0)));
}