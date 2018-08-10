#include <stdlib.h>
#include <stdio.h>

#include "lraspserver.h"

int send_data(struct socket_config, const char *msg)
{

}

int receive_data(struct socket_config socket)
{
    int tmp=0;

    /* Receiving data size */         
    tmp = recv(socket.fd, socket.data, sizeof(socket.data), 0);

    /* Return error code 03 */
    if (tmp < 0) {
        memset(socket.data, 0, MAX_BUFFER_SIZE);
        return 3;
    }

    /* Size of data to be received */
    tmp = atoi(socket.data);

    /* Setting total data size*/
    socket.data_size = tmp;

    /* Free socket.data */
    memset(socket.data, 0 MAX_BUFFER_SIZE);

    /* Formats buffer to confirm data size */
    sprintf(socket.data, "%8d", tmp);

    /* Confirm number of bytes to be received */
    tmp = send(socket.fd, socket.data, MAX_BUFFER_SIZE, 0);

    /* Return error code 01 */
    if (tmp < 0)
        return 1;

    /* Init received size */
    socket.received_size = 0;

    /* 
     * Receiving and storing data
     */

    do {
        /* Free data block */    
        memset(socket.data, 0, MAX_BUFFER_SIZE);

        /* Storing received size of data */
        tmp = recv(socket.fd, socket.data, MAX_BUFFER_SIZE, 0);

        /* Return error code 03 */
        if (tmp < 0) {
            memset(socket.data, 0, MAX_BUFFER_SIZE);
            return 3;
        }

        /* Update received size */
        socket.received_size += tmp;

        /* Stop condition */
        if (socket.received_size == socket.data_size)
            return SUCESS; 

    } while (tmp > 0);
}
