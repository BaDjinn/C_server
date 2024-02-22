#include "helper.h"
#include "patch.h"

void handle_patch(int client_socket, char *payload) {
    printf("PATCH ricevuto: %s\n", payload);
    // Qui potresti fare qualcosa con il payload, come aggiornare un record in un database
}
