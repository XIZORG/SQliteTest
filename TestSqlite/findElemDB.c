#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

void findElement(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return;
    }
    
    char *sql = "SELECT Id, Name, surname FROM COMPANY WHERE name = ?";
        
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);


    int i = 1;
    
    if (rc == SQLITE_OK) {
        
        for (int i = 1; i < 4; i++) {
            sqlite3_bind_text(res, i, "lol", strlen("lol"), NULL);
            int step = sqlite3_step(res);
            if (step == SQLITE_ROW) {
            
                printf("%d: ", sqlite3_column_int(res, 0));
                printf("%s ", sqlite3_column_text(res, 1));
                printf("%s\n", sqlite3_column_text(res, 2));

            }
        }

    } else {
        
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return;
}