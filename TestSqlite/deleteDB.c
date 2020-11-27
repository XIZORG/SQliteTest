#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string.h>

void deleteDataBase(){
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

    sql = "DELETE from COMPANY where ID = 2";

   rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records deleted successfully\n");
   }

   int last_id = sqlite3_last_insert_rowid(db);
   printf("The last Id of the inserted row is %d\n", last_id);

   sqlite3_close(db);
}
