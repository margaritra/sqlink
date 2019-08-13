/* fputs example */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int * get_frequency(FILE * pFile);
void print_frequency(int * letters_frequency);
int read_lines_pos(FILE* pFile,int* lines_pos,int max_bytes);
int get_last_index(FILE* pFILE);
int read_from_to(FILE* pFile,int from,int to,int max);


int main ()
{
  FILE * pFile;
  int capacity =256;
  int N = 3;
  int count_lines = 0;
  int readFrom = 0;
  int readTo = 0;
  
  int* place_of_line= malloc(sizeof(int)*capacity);



  pFile = fopen ("/home/ubuntu/Rita/Programming/real_time/files/file.txt","r");
  if(pFile == NULL){
    return 0;
  }
  count_lines = read_lines_pos(pFile,place_of_line,256);
  for(int i=0;i<count_lines;i++){
    printf("%d\n",place_of_line[i]);
  }
  if(N>count_lines){
    printf("problem N too high");
    return 0;
  }
  readFrom = place_of_line[count_lines-N-1];
  readTo = get_last_index(pFile);
  
  read_from_to(pFile,readFrom,readTo,10000);
  print_frequency(get_frequency(pFile));
  
  
  
  
   fclose (pFile);
   free(place_of_line);
   return 0;
}

int read_lines_pos(FILE* pFile,int* lines_pos,int max_bytes)
{
  int index=0;
  char *sentence = malloc(max_bytes*sizeof(char));

  while(fgets(sentence,max_bytes,pFile)!=NULL)
  {
    lines_pos[index] = ftell(pFile);    
    index++;
  }
  free(sentence);
  return index;

}


int get_last_index(FILE* pFILE){
  fseek(pFILE, 0L, SEEK_END);
  return ftell(pFILE);
}



int read_from_to(FILE* pFile,int from,int to,int max)
{
  int result=0;
  char *buffer = (char*) malloc (sizeof(char)*256);

  if (buffer == NULL) 
  {
    printf("Memory error"); 
    return 0;
  }
  fseek(pFile, from, SEEK_SET);
  // copy the file into the buffer:
  result = fread (buffer,1,to-from,pFile);
  if (result == to-from) 
  {
    printf("%s",buffer);
    free(buffer);
    return 1;
  }
  else{
    printf("error");
    free(buffer);
    return 0;
  }
  
}
int * get_frequency(FILE * pFile)
{
  int *letters_frequency = (int*) malloc (sizeof(int)*26);  
  int file_size = get_last_index(pFile);
  char letter ='!';
  int ascii=0;

  fseek(pFile, 0L, SEEK_SET);
  memset(letters_frequency, 0, 26*4);
  
  for(int i = 0; i < file_size; i++) {
       fread(&letter, 1, 1, pFile);
       ascii = (int) tolower(letter);
      if (ascii>=97 && ascii<=122){
        letters_frequency[ascii-97]++;
      }
  }
  return letters_frequency;

}
void print_frequency(int * letters_frequency){
  for(int i =0;i<26;i++){
    printf("%c %d\n",97+i,letters_frequency[i]);
  }
}
