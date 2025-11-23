#include "agenda.h"

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void menu() {
    printf("1. Iniciar agenda\n");
    printf("2. Agregar contacto\n");
    printf("3. Mostrar contactos\n");
    printf("4. Buscar por nombre\n");
    printf("5. Buscar por telefono\n");
    printf("6. Ordenar contactos\n");
    printf("7. Guardar en archivo\n");
    printf("8. Cargar desde archivo\n");
    printf("9. Salir\n");
    printf("Seleccione una opcion: ");
}
int main(){
    Agenda agenda;
    int opcion;
    char aux[30];

    iniciarAgenda(&agenda);  // Inicializa agenda al inicio
    while (1) {
        menu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                iniciar_agenda(&agenda);
                break;

            case 2:
                agregar_contacto(&agenda);
                break;
                
            case 3:
                mostrar_contactos(&agenda);
                break;

            case 4:
                printf("Nombre a buscar:\n");
                scanf("%s", aux);
                buscar_contacto(&agenda, aux);
                break;

            case 5:
                printf("Telefono a buscar:\n ");
                scanf("%s", aux);
                buscar_contacto_x_telefono(&agenda, aux);
                break;

            case 6:
                ordenar_contactos(&agenda);
                break;

            case 7:
                ordenar_contactos_inv(&Agenda);
                break;
            
            case 8:
                guardar_contactos(&agenda, "agenda.txt");
                break;

            case 9:
                cargar_contactos(&agenda, "agenda.txt");
                break;

            case 10:
                printf("Saliendo...\n");
                return 0;

            default:
                printf("Opcion invalida.\n");
        }
    }
}

void iniciar_agenda(Agenda *agenda){
    a->num_contactos = 0;
    printf("Agenda inicializada.\n");
}

// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if (a->num_contactos >= MAX) {
        printf("La agenda está llena.\n");
        return;
    }
    Persona *p = &a->contactos[a->num_contactos];

    printf("Nombre:\n");
    scanf(" %s", p->nombre);

    printf("Apellido:\n ");
    scanf(" %s", p->apellido);

    printf("Telefono:\n ");
    scanf(" %s", p->telefono);

    printf("Tipo de telefono (fijo/smartphone):\n ");
    scanf(" %s", p->tipo_tel);

    printf("Dia de nacimiento:\n ");
    scanf("%d", &p->dia);

    printf("Mes de nacimiento:\n ");
    scanf("%d", &p->mes);

    a->num_contactos++;

    printf("Contacto agregado correctamente.\n\n");
}

/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    bool encontrado = false;

    for (int i = 0; i < a->num_contactos; i++) {
        if (strcasecmp(a->contactos[i].nombre, nombre) == 0) {
            Persona p = a->contactos[i];
            printf("Encontrado: %s %s | %s (%s) | Nac: %d/%d\n",
                   p.nombre, p.apellido, p.telefono, p.tipo_tel, p.dia, p.mes);
            encontrado = true;
        }
    }

    if (!encontrado)
        printf("No se encontró el nombre: %s\n", nombre);
}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for (int i = 0; i < a->num_contactos; i++) {
        if (strcmp(a->contactos[i].telefono, telefono) == 0) {
            Persona p = a->contactos[i];
            printf("Encontrado: %s %s | Tel: %s (%s)\n",
                   p.nombre, p.apellido, p.telefono, p.tipo_tel);
            return;
        }
    }
    printf("No se encontró ese telefono.\n");
}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contactos(Contacto){
    if (a->num_contactos == 0) {
        printf("No hay contactos.\n");
        return;
    }

    for (int i = 1; i < a->num_contactos; i++) {
        Persona p = a->contactos[i];
        printf("%d. %s %s | %s (%s) | Nac: %d/%d\n",
               i + 1, p.nombre, p.apellido, p.telefono, p.tipo_tel, p.dia, p.mes);
    }
}

/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(archivo, "r");
    if (!f) {
        printf("Archivo no encontrado.\n");
        return;
    }

    Persona p;
    while (fscanf(f, "%[^,],%[^,],%[^,],%[^,],%d,%d\n",
                  p.nombre, p.apellido, p.telefono,
                  p.tipo_tel, &p.dia, &p.mes) == 6)
    {
        if (a->num_contactos >= MAX) break;
        a->contactos[a->num_contactos++] = p;
    }

    fclose(f);
    printf("Contactos cargados correctamente.\n");
}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(archivo, "w");
    if (!f) {
        printf("Error al abrir archivo.\n");
        return;
    }

    for (int i = 0; i < a->num_contactos; i++) {
        Persona p = a->contactos[i];
        fprintf(f, "%s,%s,%s,%s,%d,%d\n",
                p.nombre, p.apellido, p.telefono, p.tipo_tel, p.dia, p.mes);
    }

    fclose(f);
    printf("Contactos guardados correctamente.\n");
}
