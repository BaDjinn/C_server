#include "helper.h"
#include "post.h"
#include "get.h"
#include "patch.h"
#include "delete.h"

void handle_client(int client_socket) {
    char *buffer = malloc(MAX_BUFFER);
    read(client_socket, buffer, MAX_BUFFER - 1);
    printf("Richiesta del client: %s\n", buffer);

    char method[8];
    sscanf(buffer, "%s", method);

    if (strcmp(method, "POST") == 0) {
        handle_post(client_socket, buffer);
    } else if (strcmp(method, "GET") == 0) {
        handle_get(client_socket, buffer);
    } else if (strcmp(method, "PATCH") == 0) {
        handle_patch(client_socket, buffer);
    } else if (strcmp(method, "DELETE") == 0) {
        handle_delete(client_socket, buffer);
    } else {
        printf("Metodo HTTP non supportato: %s\n", method);
    }

    free(buffer);
}

void get_env_vars() {
    FILE *file = fopen(".env", "r");
    if (file == NULL) {
        perror("Impossibile aprire il file .env");
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "PORT=%d\nMAX_BUFFER=%d", &PORT, &MAX_BUFFER) != 2) {
        perror("Impossibile leggere le variabili d'ambiente dal file .env");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}
