#include "helper.h"
#include "post.h"

void handle_post(int client_socket, char *payload) {
    printf("POST ricevuto: %s\n", payload);
    // Qui potresti fare qualcosa con il payload, come salvarlo in un database
}
