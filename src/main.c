#include "agenda.h"
#include "agenda.c"

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
