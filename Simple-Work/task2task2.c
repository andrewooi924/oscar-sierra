/* task2.c */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h> 		/* change to <sys/fcntl.h> for System V */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Record {
  int unitid;
  char unitcode[8];
};

char *unitcodes[] = {"FIT2100", "FIT3159", "FIT3142","FIT3165"};

void readWriteFile() {
  int i, file, odd, even;
  struct Record rec;
  
  if ((file = open("recordfile", O_RDONLY)) < 0) {
    exit(1);
  }
  
  if ((odd = open("odd", O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0) {
    exit(1);
  }
  
  if ((even = open("even", O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0) {
    exit(1);
  }
  
  //Reads the Record structs from recordfile in the order 1,0,3,2 and prints out all the unitcodes
  for (i = 1; i >= 0 ; i -= 1) {
    lseek(file, (long) i * sizeof(struct Record), SEEK_SET);
    read(file, &rec, sizeof(struct Record));
    write(1, rec.unitcode, strlen(rec.unitcode));
    write(1, "\n", 1);
    
    if (i == 0) {
      i = 4;
    }
    
    if (i == 2) {
      i = -1;
    }
  }
  
  for (i = 0; i < 4; i++) {
    lseek(file, (long) i * sizeof(struct Record), SEEK_SET);
    read(file, &rec, sizeof(struct Record));
    
    if (rec.unitid % 2 == 0){
      lseek(even, (long) i * sizeof(struct Record), SEEK_SET);
      write(even, &rec, sizeof(struct Record)); 
    }
    else {
      lseek(odd, (long) i * sizeof(struct Record), SEEK_SET);
      write(odd, &rec, sizeof(struct Record)); 
    }
  }
  
  //Writes the unitcodes with an odd unitid to a file called odd
  
  
  close(file);
  close(even);
  close(odd);
}

int main(int argc, char *argv[])
{
  int i, outfile;
  struct Record eachrec;

  if ((outfile = open("recordfile", O_WRONLY | O_CREAT | O_TRUNC, 0664)) < 0) {
    exit(1);
  }

  for (i = 3; i >= 0; i -=2) {
    eachrec.unitid = i;
    strcpy(eachrec.unitcode, unitcodes[i]);

    lseek(outfile, (long) i * sizeof(struct Record), SEEK_SET);
    write(outfile, &eachrec, sizeof(struct Record));

    if (i == 1) {
      i = 4;
    }
  }

  close(outfile);
  
  readWriteFile();
  
  exit(0);
}
