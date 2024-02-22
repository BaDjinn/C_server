#include "patch.h"
#include <time.h>

void handle_patch(int client_socket, char *payload) {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Rimuove il newline alla fine

    printf("PATCH ricevuto: %s\nData e ora: %s\n", payload, time_str);
    // Qui potresti fare qualcosa con il payload, come aggiornare un record in un database
}
