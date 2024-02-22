#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int PORT;
int MAX_BUFFER;

void handle_client(int client_socket);
void get_env_vars();

#endif // HELPER_H
