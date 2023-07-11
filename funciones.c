#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"


void Usuario_Ingresar() {
    struct Usuario paciente;

    FILE *Pacientes;
    Pacientes = fopen("Paciente.txt", "a+");
    if (Pacientes == NULL) {
        printf("No se pudo leer el archivo\n");
    } else {
        printf("------------Creacion de Usuarios------------\n");

        printf("Ingrese el Nombre: ");
        fgets(paciente.login, sizeof paciente.login, stdin);
        paciente.login[strcspn(paciente.login,"\n")]=0;
        if (Usuario_buscar(paciente.login) == 0) {
            printf("Ingrese el Login: ");
            fgets(paciente.nombre, sizeof paciente.nombre, stdin);
            paciente.nombre[strcspn(paciente.nombre,"\n")]=0;

            printf("Ingrese el password: ");
            fgets(paciente.password, sizeof paciente.password, stdin);
            paciente.password[strcspn(paciente.password,"\n")]=0;
            do {
                printf("Ingrese el tipo de usuario\n-1 para paciente y 2 para medico: ");
                scanf("%d", &paciente.tipo);
                getchar();
            } while (paciente.tipo != 1 && paciente.tipo != 2);

            printf("----¿Desea crear el usuario(s/n)?---- ");
            char respuesta[2];
            fgets(respuesta, sizeof respuesta, stdin);

            if (strcmp(respuesta, "s") == 0) {
                fprintf(Pacientes,"%s %s %s %d\n",paciente.nombre,paciente.login,paciente.password,paciente.tipo );
                printf("Usuario creado correctamente\n");
            } else {
                printf("Creación de usuario cancelado\n");
            }
        } else {
            printf("Usuario\n");
        }
        fclose(Pacientes);
    }
}
int Usuario_buscar(char login[30]) {
    int caracter;
    FILE *buscausuarios;
    buscausuarios = fopen("Paciente.txt", "r");
    if (buscausuarios == NULL) {
        printf("No se pudo leer el archivo\n");
    } else {
        while ((caracter = fgetc(buscausuarios)) != EOF) {

            char linea[100];
            char primeraPalabra[50];
            while (fgets(linea, sizeof(linea), buscausuarios) != NULL) {
                if (sscanf(linea, "%s", primeraPalabra) == 1) {
                    if(strcmp(primeraPalabra,login)==0){
                        printf("Usuario existente, pruebe con otro ");
                        fclose(buscausuarios);
                        return 1;
                    }
                }
            }

        }
    }
    fclose(buscausuarios);
    return 0;
}
int Inicio_menu(char login[30], char password[30]) {
    struct Usuario Usua;

    FILE *buscamenu;
    buscamenu = fopen("Paciente.txt", "r");
    if (buscamenu == NULL) {
        printf("No se pudo leer el archivo\n");
    } else {
        char linea[100];
        char primeraPalabra[50],segundaPalabra[50],terceraPalabra[50],cuartaPalabra[50];
        while (fgets(linea, sizeof(linea), buscamenu) != NULL) {
            if (sscanf(linea, "%s", primeraPalabra) == 1 ) {
                sscanf(linea, "%*s %*s %s", terceraPalabra);

                if(strcmp(primeraPalabra,login)==0 && strcmp(terceraPalabra,password)==0){

                    if (sscanf(linea, "%*s %*s %*s %s", cuartaPalabra) == 1 ) {
                        if(strcmp(cuartaPalabra,"1")==0){
                            sscanf(linea, "%*s %s", segundaPalabra);
                            printf("Bienvenido Usuario paciente %s\n", segundaPalabra);
                            fclose(buscamenu);
                            return 1;
                        }else {
                            sscanf(linea, "%*s %s", segundaPalabra);
                            printf("Bienvenido Usuario medico %s\n", segundaPalabra);
                            fclose(buscamenu);
                            return 2;

                        }

                    }
                }
            }}
    }
    fclose(buscamenu);
    printf("Credenciales incorrectas\n");
    return 0;
}
void Comprar_medicamentos() {
    struct Recetario Receta;

    int i = 0;

    FILE *r;
    r = fopen("Recetas.txt", "a+");
    if (r == NULL) {
        printf("No se pudo abrir el archivo\n");
    } else {
        system("cls");

        printf("Ingrese su cedula: ");
        fgets(Receta.ID, sizeof Receta.ID, stdin);
        Receta.ID[strcspn(Receta.ID,"\n")]=0;
        printf("Ingrese su Nombre: ");
        fgets(Receta.Nombre, sizeof Receta.Nombre, stdin);
        Receta.Nombre[strcspn(Receta.Nombre,"\n")]=0;
        printf("Ingrese su Apellido: ");
        fgets(Receta.Apellido, sizeof Receta.Apellido, stdin);
        Receta.Apellido[strcspn(Receta.Apellido,"\n")]=0;

        printf("\n-------Medicamentos-------\n");
        printf("Escoja el medicamento que desea:\n1.Paracetamol - 15/10/2026 \n2.Aspirina - 10/09/2025\n3.Omeprazol - 11/02/2028\n(Escriba el numero): ");
        int opcion;
        scanf("%i", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                strcpy(Receta.Medicamentos[i], "Paracetamol");
                strcpy(Receta.Fecha_Caducidad[i], "15/10/2026");
                break;

            case 2:
                strcpy(Receta.Medicamentos[i], "Aspirina");
                strcpy(Receta.Fecha_Caducidad[i], "10/09/2025");
                break;

            case 3:
                strcpy(Receta.Medicamentos[i], "Omeprazol");
                strcpy(Receta.Fecha_Caducidad[i], "11/02/2028");
                break;

            default:
                printf("Opción invalida, no se agregara medicamento.\n");

                break;
        }
        if (opcion == 1 || opcion == 2 || opcion == 3) {
            printf("Ingrese la cantidad: ");
            scanf("%d", &Receta.Cantidad[i]);
            getchar();
            i++;
        }

        printf("Ingrese el nombre del medico: ");
        fgets(Receta.Medico, sizeof Receta.Medico, stdin);
        Receta.Medico[strcspn(Receta.Medico,"\n")]=0;
        fprintf(r,"%s %s %s %s ",Receta.Nombre,Receta.Apellido,Receta.ID,Receta.Medico );
        for (int j = 0; j < i; ++j) {
            fprintf(r,"%s %d %s ",Receta.Medicamentos[j],Receta.Cantidad[j],Receta.Fecha_Caducidad[j]);
        }
        fprintf(r,"\n");

        printf("Receta guardada correctamente\n");

        fclose(r);
    }
}
void Imprimir_Recetario() {
    struct Recetario Receta;

    FILE *r;
    r = fopen("Recetas.txt", "r");
    if (r == NULL) {
        printf("No se pudo leer el archivo\n");
    } else {
            printf("\n\n-----RECETA MEDICA-----\n");

            char linea[100];
            char Nombre[50];
            char Apellido[50];
            char Cedula[50];
            char Doctor[50];
            char Medicamentos[50];
            int Cantidad;
            char Fecha[50];
            while (fgets(linea, sizeof(linea), r) != NULL) {
                sscanf(linea, "%s %s %s %s %s %d %s",Nombre,Apellido,Cedula,Doctor,Medicamentos,&Cantidad,Fecha );
                printf("\nNombre: %s\nApellido: %s\nCedula: %s\nDoctor: %s\nMedicamentos: %s\nCantidad: %d\nFecha caducidad: %s", Nombre,Apellido,Cedula,Doctor,Medicamentos,Cantidad,Fecha);
                printf("\n-----------------------\n");
            }



    }
    fclose(r);
}
void Agregar_medicamento() {
    struct Medicamento nuevo_medicamento;

    printf("Agregar Medicamento\n");
    printf("Ingrese el nombre del medicamento: ");
    fgets(nuevo_medicamento.nombre, sizeof nuevo_medicamento.nombre, stdin);

    printf("Ingrese la cantidad en stock: ");
    scanf("%d", &nuevo_medicamento.stock);
    getchar();

    FILE *file_medicamentos = fopen("Medicamentos.txt", "a");
    if (file_medicamentos == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fprintf(file_medicamentos, "%s %d\n", nuevo_medicamento.nombre, nuevo_medicamento.stock);

    fclose(file_medicamentos);

    printf("Medicamento agregado correctamente.\n");
}
void Imprimir_pacientes(){
    FILE *Imprimirusuarios;
    Imprimirusuarios = fopen("Recetas.txt", "r");
    int cont=1;
    char linea[100];
    char Nombre[50];
    char Apellido[50];
    while (fgets(linea, sizeof(linea), Imprimirusuarios) != NULL) {

        sscanf(linea, "%s %s", Nombre, Apellido);
        printf("\nPaciente N-%d\nNombre: %s %s",cont,Nombre,Apellido);
        printf("\n--------------\n");
        cont++;
    }
    fclose(Imprimirusuarios);
}
