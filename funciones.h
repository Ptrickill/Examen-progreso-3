#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UNTITLED1_FUNCIONES_H
#define UNTITLED1_FUNCIONES_H
void Usuario_Ingresar();
int Usuario_buscar(char[30]);
int Inicio_menu(char[30], char[30]);
void Comprar_medicamentos();
void Imprimir_Recetario();
void Agregar_medicamento();
void Imprimir_pacientes();

struct Usuario {
    char nombre[50];
    char login[30];
    char password[30];
    int tipo;
};
struct Recetario {
    char ID[50];
    char Nombre[30];
    char Apellido[30];
    int Cantidad[30];
    char Fecha_Caducidad[15][30];
    char Medicamentos[15][30];
    char Medico[20];
};
struct Medicamento {
    char nombre[30];
    int stock;
};
#endif //UNTITLED1_FUNCIONES_H