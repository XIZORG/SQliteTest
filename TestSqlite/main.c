#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

void findElement(void);
void createDataBase();
void insertDataBase(char *name, char *surname);
void deleteDataBase();

int main(int argc, char* argv[]) {
   if (argc == 3) {
      createDataBase();
      insertDataBase(argv[1], argv[2]);
      findElement();
   } else if (argc == 2) {
      deleteDataBase();ты гандон
   } else {
      createDataBase();
      findElement();
   }
   return 0;
}
