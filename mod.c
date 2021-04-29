#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


void parent(){
 printf("Job is done.\n");
}

int main(void){

char name[10];

 for(int i=0; i<4; i++){
  int pid=fork();

  if(pid==0){
   printf("Enter your name: ");
   scanf("%[^\n]%*c", name);
   printf("Your name is %s\n", name);
   exit(0);
  }
  else
   if(pid>0)
   wait(NULL);
 }

 parent();
 return EXIT_SUCCESS;
}
