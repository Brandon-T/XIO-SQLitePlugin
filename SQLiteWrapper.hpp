//
//  SQLiteWrapper.hpp
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//

#ifndef SQLite_Wrapper_hpp
#define SQLite_Wrapper_hpp

#include <cstdio>
#include "sqlite3.h"

struct SQLite;
struct SQLiteBlob;

struct SQLiteContext
{
private:
    sqlite3_context* context;

public:
    SQLiteContext() = default;
    SQLiteContext(sqlite3_context* context);

    #ifdef SQLITE_HEAP_ALLOCATIONS
    SQLiteContext* aggregate_context(int nBytes);
    #else
    SQLiteContext aggregate_context(int nBytes);
    #endif
    
    [[deprecated]] int aggregate_count();
    
    #ifdef SQLITE_HEAP_ALLOCATIONS
    SQLite* db_handle();
    #else
    SQLite db_handle();
    #endif
};

struct SQLiteBackup
{
private:
    sqlite3_backup* backup;

public:
    SQLiteBackup() = default;
    SQLiteBackup(sqlite3_backup* backup);
    int finish();
    int pagecount();
    int remaining();
    int step(int nPage);
};

struct SQLiteValue
{
private:
    sqlite3_value* value;

public:
    SQLiteValue() = default;
    SQLiteValue(sqlite3_value* value);

    #ifdef SQLITE_HEAP_ALLOCATIONS
    SQLiteBlob* blobValue();
    #else
    SQLiteBlob blobValue();
    #endif
    
    int bytesValue();
    double doubleValue();
    int intValue();
    sqlite3_int64 int64Value();
    const unsigned char* textValue();
    int type();
    int numeric_type();
};

struct SQLiteStatement
{
private:
    sqlite3_stmt* statement;

public:
    SQLiteStatement() = default;
    SQLiteStatement(sqlite3_stmt* statement);

    int bind_blob(int i, const void* zData, int nData, void (*xDel)(void*));
    int bind_blob64(int i, const void* zData, sqlite3_uint64 nData, void (*xDel)(void*));
    int bind_double(int i, double rValue);

    int bind_int(int i, int iValue);
    int bind_int64(int i, sqlite_int64 iValue);
    int bind_null(int i);
    int bind_parameter_count();
    int bind_parameter_index(const char* zName);
    const char* bind_parameter_name(int i);

    int bind_text(int i, const char *zData, int nData, void (*xDel)(void*));
    int bind_text64(int i, const char *zData, sqlite3_uint64 nData, void (*xDel)(void*), unsigned char enc);
    int bind_value(int i, const sqlite3_value *pValue);
    int bind_zeroblob(int i, int n);
    int bind_zeroblob64(int i, sqlite3_uint64 n);

    int clear_bindings();

    const void* column_blob(int iCol);
    int column_bytes(int iCol);
    int column_count();

    #ifdef SQLITE_ENABLE_COLUMN_METADATA
    const char* column_database_name(int iCol);
    #endif

    const char* column_decltype(int iCol);
    double column_double(int iCol);
    int column_int(int iCol);
    sqlite3_int64 column_int64(int iCol);
    const char* column_name(int N);

    #ifdef SQLITE_ENABLE_COLUMN_METADATA
    const char* column_origin_name(int N);
    const char* column_table_name(int N);
    #endif

    const unsigned char* column_text(int iCol);
    int column_type(int iCol);
    
    #ifdef SQLITE_HEAP_ALLOCATIONS
    SQLiteValue* column_value(int iCol);
    #else
    SQLiteValue column_value(int iCol);
    #endif

    int data_count();
    int finalize();
    int reset();

    int step();
};

struct SQLiteBlob
{
private:
    sqlite3_blob* blob;

public:
    SQLiteBlob() = default;
    SQLiteBlob(sqlite3_blob* blob);

    int bytes();
    int close();
    int read(void *z, int n, int iOffset);
    int reopen(sqlite3_int64 iRow);
    int write(const void *z, int n, int iOffset);
};

struct SQLite
{
private:
    sqlite3* sqlite;

public:
    SQLite() = default;
    SQLite(sqlite3* sqlite);

    #ifdef SQLITE_HEAP_ALLOCATIONS
    SQLiteBackup* backup(SQLite* pDestDb, const char *zDestDb);
    #else
    SQLiteBackup backup(SQLite* pDestDb, const char *zDestDb);
    #endif

    int changes();
    int close();

    int complete(const char* zSql);

    int create_collation(const char *zName, int enc, void* pCtx, int(*xCompare)(void*,int,const void*,int,const void*), void(*xDel)(void*));

    int create_function(const char *zFunc, int nArg, int enc, void *p, void (*xSFunc)(sqlite3_context*,int,sqlite3_value **), void (*xStep)(sqlite3_context*,int,sqlite3_value **), void (*xFinal)(sqlite3_context*), void (*xDestroy)(void *));

    int cacheflush();
    const char* filename(const char *zDbName);

    int errcode();
    const char* errmsg();
    const char* errstr(int rc);
    int exec(const char *zSql, sqlite3_callback xCallback, void *pArg, char **pzErrMsg);

    sqlite_int64 last_insert_rowid();
    const char* libversion();
    int libversion_number();

    int open(const char *filename, int flags);

    #ifdef SQLITE_HEAP_ALLOCATIONS
    int prepare(const char *zSql, int nBytes, SQLiteStatement **ppStmt, const char **pzTail);
    #else
    int prepare(const char *zSql, int nBytes, SQLiteStatement *ppStmt, const char **pzTail);
    #endif
};

#endif /* SQLite_Wrapper_hpp */
