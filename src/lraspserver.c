#include <stdlib.h>
#include <stdio.h>

#include "lraspserver.h"

int send_data(struct socket_config, const char *msg)
{

}

int receive_data(struct socket_config socket)
{
    int ret=0;
    uint16_t data_counter=0;
    uint16_t ack=0;

    /*
     * First send numer of bytes
     */
    ret = send(socket.fd, socket.data_size,MAX_BUFFER_SIZE,0);

    if (ret < 0)
        goto error_block;

    memset(buffer, 0, MAX_BUFFER_SIZE);

error_block:
    return ERROR;
}
