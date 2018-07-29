#ifndef _LRASPSERVER_H
#define _LRASPSERVER_H

#define BUFFER_SIZE 1024
#define LIB_VERSION "lib raspserver v1.0"
#define TRUE	    1
#define FALSE	    0
#define ERROR	    -1
#define OK	    0

/*
 * Available struct for thread variables
 */
struct lib_threads = {

};


/*
 * Struct for stored lib information
 */
struct lib_config = {
	char *ip;
	int  port;
	char *buffer[BUFFER_SIZE];
	int  buffer_size = BUFFER_SIZE;

	struct lib_threads lib_threads;
};

/*
 * 
 */
int send_data(struct lib_config, const char *msg,
	      void *arg);
int receive_data();

#endif
