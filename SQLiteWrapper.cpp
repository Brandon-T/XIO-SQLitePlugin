//
//  SQLiteWrapper.cpp
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//

#include "SQLiteWrapper.hpp"
#include "sqlite3.h"
#include <cstring>


/** CONTEXT **/

SQLiteContext::SQLiteContext(sqlite3_context* context) : context(context)
{
}

#ifdef SQLITE_HEAP_ALLOCATIONS
SQLiteContext* SQLiteContext::aggregate_context(int nBytes)
{
    sqlite3_context* context = static_cast<sqlite3_context*>(sqlite3_aggregate_context(this->context, nBytes));
    return new SQLiteContext(context);
}
#else
SQLiteContext SQLiteContext::aggregate_context(int nBytes)
{
    sqlite3_context* context = static_cast<sqlite3_context*>(sqlite3_aggregate_context(this->context, nBytes));
    return SQLiteContext(context);
}
#endif

int SQLiteContext::aggregate_count()
{
    return sqlite3_aggregate_count(this->context);
}

#ifdef SQLITE_HEAP_ALLOCATIONS
SQLite* SQLiteContext::db_handle()
{
    sqlite3* handle = sqlite3_context_db_handle(this->context);
    return new SQLite(handle);
}
#else
SQLite SQLiteContext::db_handle()
{
    sqlite3* handle = sqlite3_context_db_handle(this->context);
    return SQLite(handle);
}
#endif



/** BACKUP **/

SQLiteBackup::SQLiteBackup(sqlite3_backup* backup) : backup(backup)
{
}

int SQLiteBackup::finish()
{
    return sqlite3_backup_finish(this->backup);
}

int SQLiteBackup::pagecount()
{
    return sqlite3_backup_pagecount(this->backup);
}

int SQLiteBackup::remaining()
{
    return sqlite3_backup_remaining(this->backup);
}

int SQLiteBackup::step(int nPage)
{
    return sqlite3_backup_step(this->backup, nPage);
}




/** VALUE **/

SQLiteValue::SQLiteValue(sqlite3_value* value) : value(value)
{
}

#ifdef SQLITE_HEAP_ALLOCATIONS
SQLiteBlob* SQLiteValue::blobValue()
{
    const void* result = sqlite3_value_blob(this->value);
    return new SQLiteBlob(const_cast<sqlite3_blob*>(static_cast<const sqlite3_blob*>(result)));
}
#else
SQLiteBlob SQLiteValue::blobValue()
{
    const void* result = sqlite3_value_blob(this->value);
    return SQLiteBlob(const_cast<sqlite3_blob*>(static_cast<const sqlite3_blob*>(result)));
}
#endif

int SQLiteValue::bytesValue()
{
    return sqlite3_value_bytes(this->value);
}

double SQLiteValue::doubleValue()
{
    return sqlite3_value_double(this->value);
}

int SQLiteValue::intValue()
{
    return sqlite3_value_int(this->value);
}

sqlite3_int64 SQLiteValue::int64Value()
{
    return sqlite3_value_int64(this->value);
}

const unsigned char* SQLiteValue::textValue()
{
    return sqlite3_value_text(this->value);
}

int SQLiteValue::type()
{
    return sqlite3_value_type(this->value);
}

int SQLiteValue::numeric_type()
{
    return sqlite3_value_numeric_type(this->value);
}




/** STATEMENT **/

SQLiteStatement::SQLiteStatement(sqlite3_stmt* statement) : statement(statement)
{
}

int SQLiteStatement::bind_blob(int i, const void *zData, int nData, void (*xDel)(void *))
{
    return sqlite3_bind_blob(this->statement, i, zData, nData, xDel);
}

int SQLiteStatement::bind_blob64(int i, const void* zData, sqlite3_uint64 nData, void (*xDel)(void*))
{
    return sqlite3_bind_blob64(this->statement, i, zData, nData, xDel);
}

int SQLiteStatement::bind_double(int i, double rValue)
{
    return sqlite3_bind_double(this->statement, i, rValue);
}

int SQLiteStatement::bind_int(int i, int iValue)
{
    return sqlite3_bind_int(this->statement, i, iValue);
}

int SQLiteStatement::bind_int64(int i, sqlite_int64 iValue)
{
    return sqlite3_bind_int64(this->statement, i, iValue);
}

int SQLiteStatement::bind_null(int i)
{
    return sqlite3_bind_null(this->statement, i);
}

int SQLiteStatement::bind_parameter_count()
{
    return sqlite3_bind_parameter_count(this->statement);
}

const char* SQLiteStatement::bind_parameter_name(int i)
{
    return sqlite3_bind_parameter_name(this->statement, i);
}

int SQLiteStatement::bind_parameter_index(const char* zName)
{
    return sqlite3_bind_parameter_index(this->statement, zName);
}

int SQLiteStatement::bind_text(int i, const char *zData, int nData, void (*xDel)(void*))
{
    return sqlite3_bind_text(this->statement, i, zData, nData, xDel);
}

int SQLiteStatement::bind_text64(int i, const char *zData, sqlite3_uint64 nData, void (*xDel)(void*), unsigned char enc)
{
    return sqlite3_bind_text64(this->statement, i, zData, nData, xDel, enc);
}

int SQLiteStatement::bind_value(int i, const sqlite3_value *pValue)
{
    return sqlite3_bind_value(this->statement, i, pValue);
}

int SQLiteStatement::bind_zeroblob(int i, int n)
{
    return sqlite3_bind_zeroblob(this->statement, i, n);
}

int SQLiteStatement::bind_zeroblob64(int i, sqlite3_uint64 n)
{
    return sqlite3_bind_zeroblob64(this->statement, i, n);
}

int SQLiteStatement::clear_bindings()
{
    return sqlite3_clear_bindings(this->statement);
}

const void* SQLiteStatement::column_blob(int iCol)
{
    return sqlite3_column_blob(this->statement, iCol);
}

int SQLiteStatement::column_bytes(int iCol)
{
    return sqlite3_column_bytes(this->statement, iCol);
}

int SQLiteStatement::column_count()
{
    return sqlite3_column_count(this->statement);
}

#ifdef SQLITE_ENABLE_COLUMN_METADATA
const char* SQLiteStatement::column_database_name(int iCol)
{
    return sqlite3_column_database_name(this->statement, iCol);
}
#endif

const char* SQLiteStatement::column_decltype(int iCol)
{
    return sqlite3_column_decltype(this->statement, iCol);
}

double SQLiteStatement::column_double(int iCol)
{
    return sqlite3_column_double(this->statement, iCol);
}

int SQLiteStatement::column_int(int iCol)
{
    return sqlite3_column_int(this->statement, iCol);
}

sqlite3_int64 SQLiteStatement::column_int64(int iCol)
{
    return sqlite3_column_int64(this->statement, iCol);
}

const char* SQLiteStatement::column_name(int iCol)
{
    return sqlite3_column_name(this->statement, iCol);
}

#ifdef SQLITE_ENABLE_COLUMN_METADATA
const char* SQLiteStatement::column_origin_name(int iCol)
{
    return sqlite3_column_origin_name(this->statement, iCol);
}

const char* SQLiteStatement::column_table_name(int iCol)
{
    return sqlite3_column_table_name(this->statement, iCol);
}
#endif

const unsigned char* SQLiteStatement::column_text(int iCol)
{
    return sqlite3_column_text(this->statement, iCol);
}

int SQLiteStatement::column_type(int iCol)
{
    return sqlite3_column_type(this->statement, iCol);
}

#ifdef SQLITE_HEAP_ALLOCATIONS
SQLiteValue* SQLiteStatement::column_value(int iCol)
{
    return new SQLiteValue(sqlite3_column_value(this->statement, iCol));
}
#else
SQLiteValue SQLiteStatement::column_value(int iCol)
{
    return SQLiteValue(sqlite3_column_value(this->statement, iCol));
}
#endif

int SQLiteStatement::data_count()
{
    return sqlite3_data_count(this->statement);
}

int SQLiteStatement::finalize()
{
    return sqlite3_finalize(this->statement);
}

int SQLiteStatement::reset()
{
    return sqlite3_reset(this->statement);
}

int SQLiteStatement::step()
{
    return sqlite3_step(this->statement);
}


/** BLOB **/

SQLiteBlob::SQLiteBlob(sqlite3_blob* blob) : blob(blob)
{
}

int SQLiteBlob::bytes()
{
    return sqlite3_blob_bytes(this->blob);
}

int SQLiteBlob::close()
{
    return sqlite3_blob_close(this->blob);
}

int SQLiteBlob::read(void *z, int n, int iOffset)
{
    return sqlite3_blob_read(this->blob, z, n, iOffset);
}

int SQLiteBlob::reopen(sqlite3_int64 iRow)
{
    return sqlite3_blob_reopen(this->blob, iRow);
}

int SQLiteBlob::write(const void *z, int n, int iOffset)
{
    return sqlite3_blob_write(this->blob, z, n, iOffset);
}





/** SQLITE **/

SQLite::SQLite(sqlite3* sqlite) : sqlite(sqlite)
{
}

#ifdef SQLITE_HEAP_ALLOCATIONS
SQLiteBackup* SQLite::backup(SQLite* pDestDb, const char *zDestDb)
{
    sqlite3_backup* backup = sqlite3_backup_init(pDestDb->sqlite, zDestDb, this->sqlite, zDestDb);
    return new SQLiteBackup(backup);
}
#else
SQLiteBackup SQLite::backup(SQLite* pDestDb, const char *zDestDb)
{
    sqlite3_backup* backup = sqlite3_backup_init(pDestDb->sqlite, zDestDb, this->sqlite, zDestDb);
    return SQLiteBackup(backup);
}
#endif

int SQLite::changes()
{
    return sqlite3_changes(this->sqlite);
}

int SQLite::close()
{
    int result = sqlite3_close_v2(this->sqlite);
    if (result == SQLITE_OK)
    {
        this->sqlite = nullptr;
    }
    return result;
}

int SQLite::complete(const char* zSql)
{
    return sqlite3_complete(zSql);
}

int SQLite::create_collation(const char *zName, int enc, void* pCtx, int(*xCompare)(void*,int,const void*,int,const void*), void(*xDel)(void*))
{
    return sqlite3_create_collation_v2(this->sqlite, zName, enc, pCtx, xCompare, xDel);
}

int SQLite::create_function(const char *zFunc, int nArg, int enc, void *p, void (*xSFunc)(sqlite3_context*,int,sqlite3_value **), void (*xStep)(sqlite3_context*,int,sqlite3_value **), void (*xFinal)(sqlite3_context*), void (*xDestroy)(void *))
{
    return sqlite3_create_function_v2(this->sqlite, zFunc, nArg, enc, p, xSFunc, xStep, xFinal, xDestroy);
}

int SQLite::cacheflush()
{
    return sqlite3_db_cacheflush(this->sqlite);
}

const char* SQLite::filename(const char *zDbName)
{
    return sqlite3_db_filename(this->sqlite, zDbName);
}

int SQLite::errcode()
{
    return sqlite3_errcode(this->sqlite);
}

const char* SQLite::errmsg()
{
    return sqlite3_errmsg(this->sqlite);
}

const char* SQLite::errstr(int rc)
{
    return sqlite3_errstr(rc);
}

int SQLite::exec(const char *zSql, sqlite3_callback xCallback, void *pArg, char **pzErrMsg)
{
    return sqlite3_exec(this->sqlite, zSql, xCallback, pArg, pzErrMsg);
}

sqlite_int64 SQLite::last_insert_rowid()
{
    return sqlite3_last_insert_rowid(this->sqlite);
}

const char* SQLite::libversion()
{
    return sqlite3_libversion();
}

int SQLite::libversion_number()
{
    return sqlite3_libversion_number();
}

int SQLite::open(const char *filename, int flags)
{
    if (this->sqlite)
    {
        sqlite3_close_v2(this->sqlite);
        this->sqlite = nullptr;
    }

    int result = sqlite3_open_v2(filename, &this->sqlite, flags, nullptr);

    if (result != SQLITE_OK)
    {
        sqlite3_close_v2(this->sqlite);
        this->sqlite = nullptr;
    }

    return result;
}

#ifdef SQLITE_HEAP_ALLOCATIONS
int SQLite::prepare(const char *zSql, int nBytes, SQLiteStatement **ppStmt, const char **pzTail)
{
    sqlite3_stmt* statement = nullptr;
    int result = sqlite3_prepare_v2(this->sqlite, zSql, nBytes, &statement, pzTail);

    if (result == SQLITE_OK && statement)
    {
        *ppStmt = new SQLiteStatement(statement);
    }
    return result;
}
#else
int SQLite::prepare(const char *zSql, int nBytes, SQLiteStatement *ppStmt, const char **pzTail)
{
    sqlite3_stmt* statement = nullptr;
    int result = sqlite3_prepare_v2(this->sqlite, zSql, nBytes, &statement, pzTail);

    if (result == SQLITE_OK && statement)
    {
        SQLiteStatement stmt = {statement};
        std::memcpy(ppStmt, &stmt, sizeof(stmt));
    }
    return result;
}
#endif
