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


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contactos(Contacto);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename);
void guardar_contactos(char *filename);

#endif // __AGENDA_H_
