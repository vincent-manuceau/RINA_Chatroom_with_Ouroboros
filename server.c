#define _POSIX_C_SOURCE 199309L

#include <ouroboros/dev.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_SIZE 256



struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;



void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node)); 
   link->data = data;
   link->next = head;
   head = link;
}

/*
void delete(int data) {
   struct node* current = head;
   struct node* previous = NULL;
   if(head == NULL) {
      return NULL;
   }
   while(current->data != data) {
      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }
   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }    
        
  // return current;
}*/




void * receiveMessage(void * flow_fd) {
// char buffer[BUF_SIZE]; 
 int fd;
 char buf[BUF_SIZE];
 fd = (int) flow_fd;
 memset(buf, 0, BUF_SIZE);  
 ssize_t count;

        printf("New flow %d.\n",fd);

        while (true) {
                

                
                printf("Listening to flow...\n");
                count = flow_read(fd, &buf, BUF_SIZE);
                if (count < 0) {
                        printf("Failed to read packet.\n");
                        flow_dealloc(fd);
                        continue;
                }

                printf("Message from client %d is %.*s.\n", fd, (int) count, buf);

                if (strcmp(buf,"quit\n") == 0){
                        flow_dealloc(fd);
                        break;
                }


                struct node * broadcast = head;
                short broadcast_end = 0;
                while( !broadcast_end ){

                        int curFlow = broadcast->data;
                        printf("Broadcasting to flow %d ...",curFlow);
                        if (flow_write(curFlow, buf, count) < 0) {
                                printf("Failed to write packet to %d.\n",curFlow);
                              //  flow_dealloc(fd);
                                //continue;
                        }


                        if (broadcast->next == NULL)
                                broadcast_end = 1;
                        else
                                broadcast = broadcast->next;
                }

                if (flow_write(fd, buf, count) < 0) {
                        printf("Failed to write packet.\n");
                        flow_dealloc(fd);
                        continue;
                }

               
        }
        flow_dealloc(fd);
 



}


int main(){
        pthread_t rThread;

/*	int     fd = 0, 

        int ret;*/
        char    buf[BUF_SIZE];
        ssize_t count = 0;

        pid_t pid = getpid();
        char command[BUF_SIZE] ;

        printf("Starting the server.\n");
        //char pidStr[10];
       // sprintf(pidStr,"%lun", pid);
        /*char *command;
        //executing ls command
        strcpy(command, "ls");
        printf("ls command...\n");*/
     //   system("irm name unregister ochat layer normal_layer");
        sprintf(command,"irm bind proc %lu name ochat", pid);
        system(command);
        system("irm name register ochat layer normal_layer");
        printf("IRM process binding and registering OK !\n");







        while(true){
                int fd = flow_accept(NULL, NULL);
                if (fd < 0) {
                        printf("Failed to accept flow.\n");
           //             break;
                }
                else{
                        insert(fd);
                        int ret = pthread_create(&rThread, NULL, receiveMessage, (void *) head->data);
                }
        }

        



        system("irm name unregister ochat layer normal_layer");
        return 0;
}
