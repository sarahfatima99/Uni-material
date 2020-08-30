#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>

int main(void) {
  // creating a FILE variable
  FILE *fptr;
  
  // integer variable
  int id, score;
  int i, s;
  
  // character variable
  char name[255];
  char n[255];
  char nu[888];
  // open the file in write mode
  //fptr = fopen("student", "w");
  
  /*if (fptr != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    // exit status for OS that an error occured
    return -1;
  }
  
  // get student detail
  printf("Enter student name: ");
  gets(name);
  printf("Enter student ID: ");
  scanf("%d", &id);
  printf("Enter student score: ");
  scanf("%d", &score);
  
  // write data in file
  fprintf(fptr, "%d %d %s", id, score, name);
  /*\*/
  // close connection
 // fclose(fptr);
  
  // open file for reading
  fptr = fopen("student", "r");
  
  // display detail
  printf("\nStudent Details:\n");
  fscanf(fptr, "%d %d %[^\n]s %[^\n]s", &i, &s, n,nu);
  printf("ID: %d\n", i);
  printf("Name: %s\n\n%s", n,nu);
  printf("Score: %d\n", s);
  
  printf("\nEnd of file.\n");
  
  // close connection
  fclose(fptr);
  
  return 0;
}
