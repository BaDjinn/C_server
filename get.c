#include "get.h"
#include <time.h>

void handle_get(int client_socket, char *query) {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Rimuove il newline alla fine

    printf("GET ricevuto: %s\nData e ora: %s\n", query, time_str);

    char response[1024];
    snprintf(response, sizeof(response), "HTTP/1.1 200 OK\nContent-Type: application/json\n\n{\"now\": \"%s\"}", time_str);
    write(client_socket, response, strlen(response));
}
