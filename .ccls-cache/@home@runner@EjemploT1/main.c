#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Datos de cada paciente
typedef struct{
  char nombre[20];
  int edad;
  char sintoma[20];
  char prioridad[10];
  //hora de llegada

}Paciente;

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
  puts("7) Mostrar sin orden");
  
}

void registrar_paciente(List *pacientes) {
  printf("Registrar nuevo paciente\n");
  // Aquí implementarías la lógica para registrar un nuevo paciente
  Paciente *p = (Paciente *) malloc(sizeof(Paciente));
  printf("\nIngrese el nombre del paciente: ");
  scanf("%s", p->nombre);
  printf("Ingrese edad: ");
  scanf("%d", &p->edad);
  printf("Ingrese el sintoma: ");
  scanf("%s", p->sintoma);
  strcpy(p->prioridad, "Bajo");
  
  list_pushBack(pacientes, p);
}

void asignar_prioridad(List *pacientes){
  //Buscar paciente en la lista y asignar prioridad
  //Si no existe, mostrar un aviso
  Paciente *p = list_first(pacientes);
  printf("Ingrese nombre del paciente: ");
  char nombre[20];
  char prioridad[10];
  scanf("%s", nombre);
  
  while(p){
    if(strcmp(p->nombre, nombre) == 0){
      printf("Ingrese nueva prioridad: ");
      scanf("%s", prioridad);
      if(strcmp(p->prioridad, prioridad) == 0) 
        return;
      else{
        strcpy(p->prioridad, prioridad);
        list_popCurrent(pacientes);
      }
      list_pushBack(pacientes, p);
    }
    else{
      printf("No existe tal paciente."); 
    }
    p = list_next(pacientes);
  }  
}

void mostrarNormal(List *pacientes){
  Paciente *p = list_first(pacientes);
  while(p){
    printf("Nombre: %s\n", p->nombre);
    printf("Edad: %d\n", p->edad);
    printf("Sintoma: %s\n", p->sintoma);
    printf("Prioridad: %s\n", p->prioridad);

    p = list_next(pacientes);
  }

  return;
}

void mostrar_lista_pacientes(List *pacientes) {
  // Mostrar pacientes en la cola de espera
  printf("Pacientes en espera: \n");
  Paciente *p = list_first(pacientes);
  //List *cola = list_create();
  /*while(p){
    if(strcmp(p->prioridad, "Alto") == 0){
      
    }
  }*/
  // Aquí implementarías la lógica para recorrer y mostrar los pacientes
}

int main() {
  char opcion;
  List *pacientes = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("\nIngrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_paciente(pacientes);
      break;
    case '2':
    // Lógica para asignar prioridad
      asignar_prioridad(pacientes);
      break;
    case '3':
      //mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    case '7':
      mostrarNormal(pacientes);
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(pacientes);

  return 0;
}
