#define _POSIX_C_SOURCE 199309L

#include <ouroboros/dev.h>

#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define BUF_SIZE 256


void * receiveMessage(void * flow_fd) {
// char buffer[BUF_SIZE]; 
 int fd;
 char buf[BUF_SIZE];
 fd = (int) flow_fd;
 memset(buf, 0, BUF_SIZE);  
 ssize_t count;


 for (;;) {
/* 	fd = flow_alloc("ochat", NULL, NULL);
  if (fd < 0) {
          printf("Failed to allocate flow.\n");
          return -1;
  }*/

 	count = flow_read(fd, buf, BUF_SIZE);
  if (count < 0) {
    printf("Failed to read packet.\n");
    flow_dealloc(fd);
    return NULL;
  }
  printf("Server replied with %.*s\n", (int) count, buf);  
 	//flow_dealloc(fd);
 }
}




int main(){
  int     fd,ret;
	char    buf[BUF_SIZE];
	char 		message[BUF_SIZE];
	ssize_t count;
	pthread_t rThread;
  

  

  printf("Flow allocation OK !");

  //ret = pthread_create(&rThread, NULL, receiveMessage, (void *) fd);

  
  fd = flow_alloc("ochat", NULL, NULL);
	  if (fd < 0) {
	          printf("Failed to allocate flow.\n");
	          return -1;
	  }


	ret = pthread_create(&rThread, NULL, receiveMessage, (void *) fd);

  while(true){
  	

    printf("\n%d Text : ",fd);
    fgets(message, BUF_SIZE, stdin);
    //printf("\n%s",message);

    
    
    if (flow_write(fd, message, strlen(message) + 1) < 0) {
            printf("Failed to write packet.\n");
            flow_dealloc(fd);
            return -1;
    }

    /*count = flow_read(fd, buf, BUF_SIZE);
    if (count < 0) {
            printf("Failed to read packet.\n");
            flow_dealloc(fd);
            return -1;
    }
    printf("Server replied with %.*s\n", (int) count, buf);  */

    if (strcmp(message,"\n") == 0 || strcmp(message,"quit\n") == 0)
      break;

    //if (strcmp(message,"stop\n") == 0)
    // 	break;

     
  }

  flow_dealloc(fd);
 
  return 0;
}
