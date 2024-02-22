#include "helper.h"

void handle_delete(int client_socket, char *payload) {
    printf("DELETE ricevuto: %s\n", payload);
    // Qui potresti fare qualcosa con il payload, come eliminare un record in un database
}
