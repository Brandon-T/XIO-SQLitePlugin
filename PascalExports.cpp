//
//  PascalExports.cpp
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//

#include "SQLiteWrapper.hpp"

#if defined _WIN32 || defined _WIN64
#define EXPORT_FUNC extern "C" __declspec(dllexport)
#else
#define EXPORT_FUNC extern "C"
#endif

/** SQLiteContext **/

EXPORT_FUNC SQLiteContext SQLiteContext_Aggregate(SQLiteContext* self, int nBytes)
{
    return self->aggregate_context(nBytes);
}

EXPORT_FUNC int SQLiteContext_Count(SQLiteContext* self)
{
    return self->aggregate_count();
}

EXPORT_FUNC SQLite SQLiteContext_DBHandle(SQLiteContext* self)
{
    return self->db_handle();
}

/** SQLiteBackup **/

EXPORT_FUNC int SQLiteBackup_Finish(SQLiteBackup* self)
{
    return self->finish();
}

EXPORT_FUNC int SQLiteBackup_PageCount(SQLiteBackup* self)
{
    return self->pagecount();
}

EXPORT_FUNC int SQLiteBackup_Remaining(SQLiteBackup* self)
{
    return self->remaining();
}

EXPORT_FUNC int SQLiteBackup_Step(SQLiteBackup* self, int nPage)
{
    return self->step(nPage);
}


/** SQLiteValue **/

EXPORT_FUNC SQLiteBlob SQLiteValue_BlobValue(SQLiteValue* self)
{
    return self->blobValue();
}

EXPORT_FUNC int SQLiteValue_BytesValue(SQLiteValue* self)
{
    return self->bytesValue();
}

EXPORT_FUNC double SQLiteValue_DoubleValue(SQLiteValue* self)
{
    return self->doubleValue();
}

EXPORT_FUNC int SQLiteValue_IntValue(SQLiteValue* self)
{
    return self->intValue();
}

EXPORT_FUNC sqlite3_int64 SQLiteValue_Int64Value(SQLiteValue* self)
{
    return self->int64Value();
}

EXPORT_FUNC const unsigned char* SQLiteValue_TextValue(SQLiteValue* self)
{
    return self->textValue();
}

EXPORT_FUNC int SQLiteValue_Type(SQLiteValue* self)
{
    return self->type();
}

EXPORT_FUNC int SQLiteValue_NumericType(SQLiteValue* self)
{
    return self->numeric_type();
}


/** SQLiteStatement **/

EXPORT_FUNC int SQLiteStatement_BindBlob(SQLiteStatement* self, int i, void* zData, int nData, void(*xDel)(void*))
{
    return self->bind_blob(i, zData, nData, xDel);
}

EXPORT_FUNC int SQLiteStatement_BindBlob64(SQLiteStatement* self, int i, void* zData, sqlite3_uint64 nData, void(*xDel)(void*))
{
    return self->bind_blob64(i, zData, nData, xDel);
}

EXPORT_FUNC int SQLiteStatement_BindDouble(SQLiteStatement* self, int i, double rValue)
{
    return self->bind_double(i, rValue);
}

EXPORT_FUNC int SQLiteStatement_BindInt(SQLiteStatement* self, int i, int iValue)
{
    return self->bind_int(i, iValue);
}

EXPORT_FUNC int SQLiteStatement_BindInt64(SQLiteStatement* self, int i, sqlite_int64 iValue)
{
    return self->bind_int64(i, iValue);
}

EXPORT_FUNC int SQLiteStatement_BindNull(SQLiteStatement* self, int i)
{
    return self->bind_null(i);
}

EXPORT_FUNC int SQLiteStatement_BindParameterCount(SQLiteStatement* self)
{
    return self->bind_parameter_count();
}

EXPORT_FUNC const char* SQLiteStatement_BindParameterName(SQLiteStatement* self, int i)
{
    return self->bind_parameter_name(i);
}

EXPORT_FUNC int SQLiteStatement_BindParameterIndex(SQLiteStatement* self, const char* zName)
{
    return self->bind_parameter_index(zName);
}

EXPORT_FUNC int SQLiteStatement_BindText(SQLiteStatement* self, int i, const char *zData, int nData, void (*xDel)(void*))
{
    return self->bind_text(i, zData, nData, xDel);
}

EXPORT_FUNC int SQLiteStatement_BindText64(SQLiteStatement* self, int i, const char *zData, sqlite3_uint64 nData, void (*xDel)(void*), unsigned char enc)
{
    return self->bind_text64(i, zData, nData, xDel, enc);
}

EXPORT_FUNC int SQLiteStatement_BindValue(SQLiteStatement* self, int i, const sqlite3_value *pValue)
{
    return self->bind_value(i, pValue);
}

EXPORT_FUNC int SQLiteStatement_BindZeroBlob(SQLiteStatement* self, int i, int n)
{
    return self->bind_zeroblob(i, n);
}

EXPORT_FUNC int SQLiteStatement_BindZeroBlob64(SQLiteStatement* self, int i, sqlite3_uint64 n)
{
    return self->bind_zeroblob64(i, n);
}

EXPORT_FUNC int SQLiteStatement_ClearBindings(SQLiteStatement* self)
{
    return self->clear_bindings();
}

EXPORT_FUNC const void* SQLiteStatement_ColumnBlob(SQLiteStatement* self, int iCol)
{
    return self->column_blob(iCol);
}

EXPORT_FUNC int SQLiteStatement_ColumnBytes(SQLiteStatement* self, int iCol)
{
    return self->column_bytes(iCol);
}

EXPORT_FUNC int SQLiteStatement_ColumnCount(SQLiteStatement* self)
{
    return self->column_count();
}

EXPORT_FUNC const char* SQLiteStatement_ColumnDecltype(SQLiteStatement* self, int iCol)
{
    return self->column_decltype(iCol);
}

EXPORT_FUNC double SQLiteStatement_ColumnDouble(SQLiteStatement* self, int iCol)
{
    return self->column_double(iCol);
}

EXPORT_FUNC int SQLiteStatement_ColumnInt(SQLiteStatement* self, int iCol)
{
    return self->column_int(iCol);
}

EXPORT_FUNC sqlite3_int64 SQLiteStatement_ColumnInt64(SQLiteStatement* self, int iCol)
{
    return self->column_int64(iCol);
}

EXPORT_FUNC const char* SQLiteStatement_ColumnName(SQLiteStatement* self, int iCol)
{
    return self->column_name(iCol);
}

EXPORT_FUNC const unsigned char* SQLiteStatement_ColumnText(SQLiteStatement* self, int iCol)
{
    return self->column_text(iCol);
}

EXPORT_FUNC int SQLiteStatement_ColumnType(SQLiteStatement* self, int iCol)
{
    return self->column_type(iCol);
}

SQLiteValue SQLiteStatement_ColumnValue(SQLiteStatement* self, int iCol)
{
    return self->column_value(iCol);
}

EXPORT_FUNC int SQLiteStatement_DataCount(SQLiteStatement* self)
{
    return self->data_count();
}

EXPORT_FUNC int SQLiteStatement_Finalize(SQLiteStatement* self)
{
    return self->finalize();
}

EXPORT_FUNC int SQLiteStatement_Reset(SQLiteStatement* self)
{
    return self->reset();
}

EXPORT_FUNC int SQLiteStatement_step(SQLiteStatement* self)
{
    return self->step();
}


/** SQLiteBlob **/


EXPORT_FUNC int SQLiteBlob_Bytes(SQLiteBlob* self)
{
    return self->bytes();
}

EXPORT_FUNC int SQLiteBlob_Close(SQLiteBlob* self)
{
    return self->close();
}

EXPORT_FUNC int SQLiteBlob_Read(SQLiteBlob* self, void *z, int n, int iOffset)
{
    return self->read(z, n, iOffset);
}

EXPORT_FUNC int SQLiteBlob_Reopen(SQLiteBlob* self, sqlite3_int64 iRow)
{
    return self->reopen(iRow);
}

EXPORT_FUNC int SQLiteBlob_Write(SQLiteBlob* self, const void *z, int n, int iOffset)
{
    return self->write(z, n, iOffset);
}


/** SQLite **/

EXPORT_FUNC SQLiteBackup SQLite_Backup(SQLite* self, SQLite pDestDb, const char* zDestDb)
{
    return self->backup(&pDestDb, zDestDb);
}

EXPORT_FUNC int SQLite_Changes(SQLite* self)
{
    return self->changes();
}

EXPORT_FUNC int SQLite_Close(SQLite* self)
{
    return self->close();
}

EXPORT_FUNC int SQLite_CreateFunction(SQLite* self, const char *zFunc, int nArg, int enc, void *p, void (*xSFunc)(sqlite3_context*,int,sqlite3_value **), void (*xStep)(sqlite3_context*,int,sqlite3_value **), void (*xFinal)(sqlite3_context*), void (*xDestroy)(void *))
{
    return self->create_function(zFunc, nArg, enc, p, xSFunc, xStep, xFinal, xDestroy);
}

EXPORT_FUNC int SQLite_CacheFlush(SQLite *self)
{
    return self->cacheflush();
}

EXPORT_FUNC int SQLite_ErrorCode(SQLite* self)
{
    return self->errcode();
}

EXPORT_FUNC const char* SQLite_ErrorMessage(SQLite* self)
{
    return self->errmsg();
}

EXPORT_FUNC const char* SQLite_ErrorString(SQLite* self, int errorCode)
{
    return self->errstr(errorCode);
}

EXPORT_FUNC int SQLite_Exec(SQLite* self, const char *zSql)
{
    return self->exec(zSql, nullptr, nullptr, nullptr);
}

EXPORT_FUNC sqlite3_int64 SQLite_LastInsertRowId(SQLite* self)
{
    return self->last_insert_rowid();
}

EXPORT_FUNC const char* SQLite_LibVersion(SQLite* self)
{
    return self->libversion();
}

EXPORT_FUNC int SQLite_LibVersionNumber(SQLite* self)
{
    return self->libversion_number();
}

EXPORT_FUNC int SQLite_Open(SQLite* self, const char* fileName, int flags)
{
    return self->open(fileName, flags);
}

EXPORT_FUNC int SQLite_Prepare(SQLite* self, const char* sql, int nBytes, SQLiteStatement* statement)
{
    return self->prepare(sql, nBytes, statement, nullptr);
}
