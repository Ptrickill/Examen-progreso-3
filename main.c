#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int main() {
    char password[30], login[30];
    int opcion, opcion1 = 0;
    while (opcion1 != 1) {
        printf("Farmacia Fundacion Salud\n");
        printf("\nIngrese opcion:\n1.Iniciar sesion\n2.Registrarse\n");
        scanf("%i", &opcion1);
        getchar();
        system("cls");
        if (opcion1 == 2) {
            Usuario_Ingresar();
        }
    }
    printf("Farmacia Fundacion Salud\n");
    printf("Login: ");
    fgets(login, sizeof login, stdin);
    login[strcspn(login,"\n")]=0;
    printf("Contraseña: ");
    fgets(password, sizeof password, stdin);
    password[strcspn(password,"\n")]=0;
    if (Inicio_menu(login, password) == 1) {
        do {
            printf("\nIngrese opcion:\n1.Comprar medicamentos\n2.Mostrar recetario\n""3.Cerrar sesion\n");
            scanf("%i", &opcion);
            getchar();
            switch (opcion) {
                case 1:
                    Comprar_medicamentos();
                    system("cls");
                    break;

                case 2:
                    Imprimir_Recetario();
                    getchar();
                    system("cls");
                    break;

                case 3:
                    printf("Cerrando sesion...\n");
                    break;
            }
        } while (opcion != 3);
    } else if (Inicio_menu(login, password) == 2) {
        do {
        printf("Bienvenido Usuario medico\n");
        printf("\nIngrese opcion:\n1.1)\tMostrar pacientes\n2.2)\tIngresar medicamentos\n""3.Cerrar sesion\n");
        scanf("%i", &opcion);
        getchar();

            switch (opcion) {
                case 1:
                    Imprimir_pacientes();
                    getchar();
                    system("cls");
                    break;
                case 2:
                    Agregar_medicamento();
                    getchar();
                    system("cls");
                    break;
                case 3:
                    printf("Cerrando sesion...");
                    getchar();
                    system("cls");
                    break;
            }
        }while (opcion!=3);

    }
    return 0;
}


