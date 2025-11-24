#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

typedef struct{
    char nombre[30];
    char apellido[30];
    char telefono[20];
    char tipo_tel[20];
    int dia;
    int mes; 
}Persona;

typedef struct Persona Contacto;

typedef struct Agenda{
    Contacto contactos[MAX];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *a);
void agregar_contacto(Agenda *a);
int buscar_contacto(const Agenda *a, const char *nombre[]);
int buscar_contacto_x_telefono(const Agenda *a, const char *telefono[]);
void ordenar_contactos(Agenda *a);
void ordenar_contactos_inv(Agenda *a);
void mostrar_contactos(const Agenda *a);
void cargar_contactos(Agenda *a, const char *nombreArchivo);
void guardar_contactos(const Agenda *a, const char *nombreArchivo);

#endif // __AGENDA_H_
