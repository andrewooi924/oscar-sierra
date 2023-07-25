/**
 *fileutil.c: A multipurpose file utility that can be used to output words from a text file or append words from from one
 *text file to another. The program accepts user-specified numbers for the functions as well.
 *Name: Ooi Yu Zhang
 *Start Date: 19/8/2022
 *Last Modified: 23/8/2022, 6:13p.m.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h> 		/* change to <sys/fcntl.h> for System V */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 *  Function that displays the first 10 words of the specified text file 
 *  *source: The text file to be read from
 *  Returns nothing as it only displays the words in the file
 */
void viewFile(char *source) {

  //Instance variables
  int outfile;
  int i = 0;
  char *ch[100];
  int wordCount = 0;
  
  //Check for invalid arguments
  if (strcmp(source, "-a") == 0){
    write(2, "Invalid argument!\n", 18);
    exit(1);
  }
  
  //Check if file exists
  if ((outfile = open(source, O_RDONLY)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Check if file is empty or if pointer is at EOF
  while (read(outfile, &ch, 1)){
    
    //Check for spaces, tabs and newlines
    while (!(isalnum(*ch))) {
      lseek(outfile, (long) i++, SEEK_SET); //Reposition file offset
      read(outfile, &ch, 1); //Read current character
      write(1, ch, 1); //Output current character
    }
    
    //Output the current word
    while (isalnum(*ch) || ispunct(*ch)) {
      lseek(outfile, (long) i++, SEEK_SET); //Reposition file offset
      read(outfile, &ch, 1); //Read current character
      write(1, ch, 1); //Output current character
    }
    
    //Increment word count
    wordCount++;
    
    //If current word count is greater or equal to 10 or at EOF, break out of while loop
    if (wordCount >= 10 || !(read(outfile, &ch, 1))) {
      break;
    }
  }
  
  //Close the outfile;
  close(outfile);
}

/**
 *  Function that appends the first 10 words from the source file to the destination file 
 *  *source: The text file to be read from
 *  *dest: The text file to be written to 
 *  Returns nothing as it only modifies the given destination file
 */
void appendFile(char *source, char *dest) {
  
  //Instance variables
  int infile, outfile;
  int i = 0;
  char *ch[100];
  int wordCount = 0;
  
  //Open the source file for reading
  if ((infile = open(source, O_RDONLY)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Open the destination file for writing
  if ((outfile = open(dest, O_WRONLY | O_CREAT, 0.664)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Reading and writing the first 10 words from source file to destination file
  //Check if file is empty or if pointer is at EOF
  while (read(infile, &ch, 1)){
  
    //Reading and writing spaces, tabs and newlines
    while (!(isalnum(*ch))) {
      lseek(infile, (long) i++, SEEK_SET); //Reposition infile offset
      lseek(outfile, 0, SEEK_END); //Reposition outfile offset
      read(infile, &ch, 1); //Read current character
      write(outfile, ch, 1); //Append current character
    }
    
    //Reading and writing the current word to destination file
    while (isalnum(*ch) || ispunct(*ch)) {
      lseek(infile, (long) i++, SEEK_SET); //Reposition infile offset
      lseek(outfile, 0, SEEK_END); //Reposition outfile offset
      read(infile, &ch, 1); //Read current character
      write(outfile, ch, 1); //Append current character
    }
    
    //Increment word count
    wordCount++;
    
    //If current word count is greater or equal to 10 or at EOF, break out of while loop
    if (wordCount >= 10 || !(read(infile, &ch, 1))) {
      break;
    }
  }
  
  //Close infile and outfile
  close(infile);
  close(outfile);
}

/**
 *  Function that displays a user-specified number of words from the specified text file 
 *  *source: The text file to be read from
 *  *n: The user-specified number of words to be read
 *  Returns nothing as it only displays the words in the file
 */
void customView(char *source, char *n) {
  
  //Instance variables
  int outfile;
  int i = 0;
  char *ch[100];
  int wordCount = 0;
  
  //Check if file exists
  if ((outfile = open(source, O_RDONLY)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Check if file is empty or if pointer is at EOF
  while (read(outfile, ch, 1)){
  
    //Check for spaces, tabs and newlines
    while (!(isalnum(*ch))) {
      lseek(outfile, (long) i++, SEEK_SET); //Reposition file offset
      read(outfile, ch, 1); //Read current character
      write(1, ch, 1); //Output current character
    }
    
    //Output the current word
    while (isalnum(*ch) || ispunct(*ch)) {
      lseek(outfile, (long) i++, SEEK_SET); //Reposition file offset
      read(outfile, ch, 1); //Read current character
      write(1, ch, 1); //Output current character
    }
    
    //Increment word count
    wordCount++;
    
    //If current word count is greater or equal to n or at EOF, break out of while loop
    if (wordCount >= atoi(n) || !(read(outfile, &ch, 1))) {
      break;
    }
  }
  
  //Close the outfile;
  close(outfile);
}

/**
 *  Function that appends a user-specified number of words from a text file to another
 *  *source: The text file to be read from
 *  *dest: The text file to be written to
 *  *n: The user-specified number to words to be read and written
 *  Returns nothing as it only modifies the given destination file
 */
void customAppend(char *source, char *dest, char *n){
  
  //Instance variables
  int infile, outfile;
  int i = 0;
  char *ch[100];
  int wordCount = 0;
  
  //Open the source file for reading
  if ((infile = open(source, O_RDONLY)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Open the destination file for writing
  if ((outfile = open(dest, O_WRONLY | O_CREAT, 0.664)) < 0) {
    write(2, "File does not exist!\n", 21);
    exit(1);
  }
  
  //Check if given numwords is a digit
  if (!(isdigit(*n))) {
    write(2, "Invalid argument!\n", 19);
    exit(1);
  }
  
  //Reading and writing the first 10 words from source file to destination file
  //Check if file is empty or if pointer is at EOF
  while (read(infile, &ch, 1)){
  
    //Reading and writing spaces, tabs and newlines
    while (!(isalnum(*ch))) {
      lseek(infile, (long) i++, SEEK_SET); //Reposition infile offset
      lseek(outfile, 0, SEEK_END); //Reposition outfile offset
      read(infile, &ch, 1); //Read current character
      write(outfile, ch, 1); //Append current character
    }
    
    //Reading and writing the current word to destination file
    while (isalnum(*ch)) {
      lseek(infile, (long) i++, SEEK_SET); //Reposition infile offset
      lseek(outfile, 0, SEEK_END); //Reposition outfile offset
      read(infile, &ch, 1); //Read current character
      write(outfile, ch, 1); //Append current character
    }
    
    //Increment word count
    wordCount++;
    
    //If current word count is equal to n or at EOF, break out of while loop
    if (wordCount >= atoi(n) || !(read(infile, &ch, 1))) {
      break;
    }
  }
  
  //Close infile and outfile
  close(infile);
  close(outfile);
}

/**
 * The main function where the program runs
 * argc: The number of arguments
 * *argv[]: An array containing the arguments
 * Returns 0 or 1 indicating if the program ran successfully. 0 if successful and 1 otherwise
 */
int main(int argc, char *argv[]) {
  
  //Instance variables
  char c;

  //Check argument count
  if (argc > 6){
    write(2, "Please refer to user manual on how to use this program!\n", 56); 
    exit(1);
  }
  
  //One argument (./fileutil)
  if (argc == 1) {
    viewFile("sample.txt");
    write(1, "\n", 1);
  }
  //Two arguments (./fileutil sourcefile)
  else if (argc == 2) {
    //Check for invalid arguments
    if ((strcmp(argv[1], "-a")) && (strcmp(argv[1], "-n"))) {
      viewFile(argv[1]);
      write(1, "\n", 1);
    }
    else {
      write(2, "Invalid argument!\n", 19);
      exit(1);
    }
  }
  //Three arguments
  else if (argc == 3) {
    //Append from sample.txt to destination file
    if (strcmp(argv[1], "-a") == 0) {
      appendFile("sample.txt", argv[2]);
      write(1, "Append successful\n", 19);
    }
    //View custom number of words in sample.txt
    else if(strcmp(argv[1], "-n") == 0) {
      customView("sample.txt", argv[2]);
      write(1, "\n", 1);
    }
    //Otherwise, it's an invalid argument
    else {
      write(2, "Invalid argument!\n", 19);
      exit(1);
    }
  }
  //Four arguments
  else if (argc == 4) {
    //Append from user-specified source file to destination file
    if (strcmp(argv[2], "-a") == 0) {
      appendFile(argv[1], argv[3]);
      write(1, "Append successful\n", 19);
    }
    //View custom number of words from user-specified source file (3rd and 4th arguments are -n numwords)
    else if (strcmp(argv[2], "-n") == 0) {
      customView(argv[1], argv[3]);
      write(1, "\n", 1);
    }
    //View custom number of words from user-specified source file (2nd and 3rd arguments are -n numwords)
    else if (strcmp(argv[1], "-n") == 0) {
      customView(argv[3], argv[2]);
      write(1, "\n", 1);
    }
    //Otherwise, it's an invalid argument
    else {
      write(2, "Invalid argument!\n", 19);
      exit(1);
    }
  }
  //Five arguments (Only possible utility here is to append a user-specified number of words from sample.txt to destfile)
  else if (argc == 5) {
    //2nd argument is -a
    if (strcmp(argv[1], "-a") == 0) {
      //Check if 3rd argument is -n
      if (strcmp(argv[2], "-n") == 0) {
        write(2, "Invalid argument!\n", 19);
        exit(1);
      }
      //3rd argument is destfile
      else {
        //Check if 4th argument is -n and 5th argument is an integer
        if (strcmp(argv[3], "-n") == 0 && isdigit(argv[4])) {
          customAppend("sample.txt", argv[2], argv[4]);
          write(1, "Append successful\n", 19);
        }
        else {
          write(2, "Invalid argument!\n", 19);
          exit(1);
        }
      }
    }
    //2nd argument is -n and 3rd argument is numwords
    else if (strcmp(argv[1], "-n") == 0 && isdigit(argv[2])) {
      //Check if 4th argument is -a
      if (strcmp(argv[3], "-a") == 0) {
        customAppend("sample.txt", argv[4], argv[2]);
        write(1, "Append successful\n", 19);
      }
      //4th argument is destfile
      else {
        write(2, "Invalid argument!\n", 19);
        exit(1);
      }
    }
    //Otherwise, it's an invalid argument
    else {
      write(2, "Invalid argument!\n", 19);
      exit(1);
    }
  }
  //Six arguments (Only possible utility here is to append a user-specified number of words from sourcefile to destfile)
  else {
    //2nd argument must be sourcefile
    //Check if 3rd argument is -a
    if (strcmp(argv[2], "-a") == 0) {
      //Check if 4th argument is -n
      if (strcmp(argv[3], "-n") == 0) {
        write(2, "Invalid argument!\n", 19);
        exit(1);
      }
      //4th argument is destfile
      else {
        customAppend(argv[1], argv[3], argv[5]);
        write(1, "Append successful\n", 19);
      }
    }
    //Check if 3rd argument is -n
    else if (strcmp(argv[2], "-n") == 0) {
      //Check if 5th argument is -a
      if (strcmp(argv[4], "-a") == 0) {
        customAppend(argv[1], argv[5], argv[3]);
        write(1, "Append successful\n", 19);
      }
      //5th argument is destfile
      else {
        write(2, "Invalid argument!\n", 19);
        exit(1);
      }
    }
    //3rd argument is destfile
    else {
      write(2, "Invalid argument!\n", 19);
      exit(1);
    }
  }
  
  //Exit the program
  exit(0);
}
