#include "db-man.h"
#include <stdio.h>

sqlite3 *db_open(const char *path)
{
	sqlite3 *db = NULL;
	int rc = sqlite3_open(path, &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "[DB] Cannot open database '%s': %s\n", path, sqlite3_errmsg(db));
		if (db)
			sqlite3_close(db);
		return NULL;
	}
	return db;
}

int db_exec(sqlite3 *db, const char *sql)
{
	char *err_msg = NULL;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &err_msg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "[DB] SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		return rc;
	}
	return 0;
}

sqlite3_stmt *db_prepare(sqlite3 *db, const char *sql)
{
	sqlite3_stmt *stmt = NULL;
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "[DB] Failed to prepare statement: %s\n", sqlite3_errmsg(db));
		return NULL;
	}
	return stmt;
}

void db_finalize(sqlite3_stmt *stmt)
{
	if (stmt)
		sqlite3_finalize(stmt);
}

void db_close(sqlite3 *db)
{
	if (db)
		sqlite3_close(db);
}
