#ifndef _LRASPSERVER_H
#define _LRASPSERVER_H

#define MAX_BUFFER_SIZE 0x400 //1024
#define LIB_VERSION "lib raspserver v1.0"
#define TRUE     1
#define FALSE    0
#define ERROR   -1
#define SUCESS   0

#include <sys/socket>

char *error_msg[4] = {
    "Init list error",
    "Erro 01 - Erro ao enviar a confirmacao de recebimento dos bytes de dados",
    "Erro 02 - Divergencia entre os dados recebidos pelo socket",
    "Erro 03 - Erro ao receber dados do socket"
}

/*
 * Available struct for thread variables
 */
struct threads_config = {
    pthread_t t_id;
    pthread_mutex_t t_mutex;
};


/*
 * Struct for stored lib information
 */
struct socket_config = {
    int fd;
    int port;
    uint16_t received_size;
    uint16_t data_size;
    char *ip;
    char data[MAX_BUFFER_SIZE];
    
    struct sockaddr_in server;
    struct sockaddr_in client;
    struct threads_config threads;
};

/*
 * Send data with socket TCP IP
 */
int send_data(struct socket_config, const char *msg);

/*
 * Receive data from socket
 */
int receive_data(struct socket_config);

#endif
