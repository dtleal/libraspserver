#include <stdlib.h>
#include <stdio.h>

#include "lraspserver.h"

int send_data(struct socket_config)
{
    int tmp=0;
    uint16_t tmp_size=0;
    char tmp_data[MAX_BUFFER_SIZE]={0};

    /* Storing data size to send */
    sprintf(tmp_data, "%8d", socket.data_size);

    /* Send data size */
    tmp = send(socket.fd, tmp_data, MAX_BUFFER_SIZE, 0);

    /* Return error code 03 */
    if (tmp < 0)
        return 3;

    /* Clean temp data*/
    memset(tmp_data, 0, MAX_BUFFER_SIZE);

    /* Receiving data size to confirm */
    tmp = recv(socket.fd, tmp_data, MAX_BUFFER_SIZE, 0);

    /* Return error code 03*/
    if (tmp < 0)
        return 3;

    /* Cast to get received data size */
    tmp = atoi(tmp_data);

    /* Compare data sizes */
    if (tmp != socket.data_size)         
       return 2;

    /* Get max data size without change original */
    tmp_size = socket.data_size

    /*
     * Send data
     */
    
    while (tmp_size > 0) {
       
        /* Free tmp_data */
        memset(tmp_data, 0, MAX_BUFFER_SIZE);

        /**/
        tmp = send(socket.fd, tmp_data, sizeof(tmp_data), 0);

        if (tmp < 0) {
            memset(tmp_data, 0, MAX_BUFFER_SIZE);
            return 4;
        }

        tmp_size -= tmp;
    }

    return SUCCESS;
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
            return SUCCESS; 

    } while (tmp > 0);
}
