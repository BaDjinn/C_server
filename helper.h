#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int MAX_BUFFER;

void handle_client(int client_socket) {
    char *buffer = malloc(MAX_BUFFER);
    read(client_socket, buffer, MAX_BUFFER - 1);
    printf("Richiesta del client: %s\n", buffer);
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    write(client_socket, response, sizeof(response) - 1);
    close(client_socket);
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

#endif // HELPER_H
