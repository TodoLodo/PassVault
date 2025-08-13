#ifndef DB_MAN_H
#define DB_MAN_H

#include <sqlite3.h>

/**
 * Opens a SQLite database at the given path.
 * Creates it if it doesn't exist.
 *
 * @param path Path to the database file.
 * @return Pointer to sqlite3 instance or NULL on error.
 */
sqlite3 *db_open(const char *path);

/**
 * Executes a single SQL statement that does not return results
 * (e.g., CREATE TABLE, INSERT, UPDATE).
 *
 * @param db SQLite database handle.
 * @param sql SQL statement string.
 * @return 0 on success, non-zero on error.
 */
int db_exec(sqlite3 *db, const char *sql);

/**
 * Prepares a SQL statement for execution.
 * Used for queries that return results.
 *
 * @param db SQLite database handle.
 * @param sql SQL statement string (with optional placeholders).
 * @return sqlite3_stmt pointer or NULL on error.
 */
sqlite3_stmt *db_prepare(sqlite3 *db, const char *sql);

/**
 * Finalizes (cleans up) a prepared statement.
 *
 * @param stmt Prepared statement handle.
 */
void db_finalize(sqlite3_stmt *stmt);

/**
 * Closes an open SQLite database.
 *
 * @param db SQLite database handle.
 */
void db_close(sqlite3 *db);

#endif // DB_MAN_H
