#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

void createDataBase(){
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

 sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
      "Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
      "NAME           TEXT    NOT NULL," \
      "SURNAME        TEXT    NOT NULL);"; \

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

   sqlite3_close(db);
}
