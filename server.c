#include "helper.h"
#include "post.c"
#include "get.c"
#include "patch.c"
#include "delete.c"

int main() {
    get_env_vars();

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Impossibile creare il socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Impossibile fare il bind del socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("Impossibile ascoltare sul socket");
        exit(EXIT_FAILURE);
    }

    printf("Server in ascolto sulla porta %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);
        if (client_socket == -1) {
            perror("Impossibile accettare la connessione del client");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }

    return 0;
}
