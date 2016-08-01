//
//  PascalExports.cpp
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//

#include "SQLiteWrapper.hpp"

/** SQLiteContext **/

SQLiteContext SQLiteContext_Aggregate(SQLiteContext* self, int nBytes)
{
    return self->aggregate_context(nBytes);
}

int SQLiteContext_Count(SQLiteContext* self)
{
    return self->aggregate_count();
}

SQLite SQLiteContext_DBHandle(SQLiteContext* self)
{
    return self->db_handle();
}

/** SQLiteBackup **/

int SQLiteBackup_Finish(SQLiteBackup* self)
{
    return self->finish();
}

int SQLiteBackup_PageCount(SQLiteBackup* self)
{
    return self->pagecount();
}

int SQLiteBackup_Remaining(SQLiteBackup* self)
{
    return self->remaining();
}

int SQLiteBackup_Step(SQLiteBackup* self, int nPage)
{
    return self->step(nPage);
}


/** SQLiteValue **/

SQLiteBlob SQLiteValue_BlobValue(SQLiteValue* self)
{
    return self->blobValue();
}

int SQLiteValue_BytesValue(SQLiteValue* self)
{
    return self->bytesValue();
}

double SQLiteValue_DoubleValue(SQLiteValue* self)
{
    return self->doubleValue();
}

int SQLiteValue_IntValue(SQLiteValue* self)
{
    return self->intValue();
}

sqlite3_int64 SQLiteValue_Int64Value(SQLiteValue* self)
{
    return self->int64Value();
}

const unsigned char* SQLiteValue_TextValue(SQLiteValue* self)
{
    return self->textValue();
}

int SQLiteValue_Type(SQLiteValue* self)
{
    return self->type();
}

int SQLiteValue_NumericType(SQLiteValue* self)
{
    return self->numeric_type();
}


/** SQLiteStatement **/

int SQLiteStatement_BindBlob(SQLiteStatement* self, int i, void* zData, int nData, void(*xDel)(void*))
{
    return self->bind_blob(i, zData, nData, xDel);
}

int SQLiteStatement_BindBlob64(SQLiteStatement* self, int i, void* zData, sqlite3_uint64 nData, void(*xDel)(void*))
{
    return self->bind_blob64(i, zData, nData, xDel);
}

int SQLiteStatement_BindDouble(SQLiteStatement* self, int i, double rValue)
{
    return self->bind_double(i, rValue);
}

int SQLiteStatement_BindInt(SQLiteStatement* self, int i, int iValue)
{
    return self->bind_int(i, iValue);
}

int SQLiteStatement_BindInt64(SQLiteStatement* self, int i, sqlite_int64 iValue)
{
    return self->bind_int64(i, iValue);
}

int SQLiteStatement_BindNull(SQLiteStatement* self, int i)
{
    return self->bind_null(i);
}

int SQLiteStatement_BindParameterCount(SQLiteStatement* self)
{
    return self->bind_parameter_count();
}

const char* SQLiteStatement_BindParameterName(SQLiteStatement* self, int i)
{
    return self->bind_parameter_name(i);
}

int SQLiteStatement_BindParameterIndex(SQLiteStatement* self, const char* zName)
{
    return self->bind_parameter_index(zName);
}

int SQLiteStatement_BindText(SQLiteStatement* self, int i, const char *zData, int nData, void (*xDel)(void*))
{
    return self->bind_text(i, zData, nData, xDel);
}

int SQLiteStatement_BindText64(SQLiteStatement* self, int i, const char *zData, sqlite3_uint64 nData, void (*xDel)(void*), unsigned char enc)
{
    return self->bind_text64(i, zData, nData, xDel, enc);
}

int SQLiteStatement_BindValue(SQLiteStatement* self, int i, const sqlite3_value *pValue)
{
    return self->bind_value(i, pValue);
}

int SQLiteStatement_BindZeroBlob(SQLiteStatement* self, int i, int n)
{
    return self->bind_zeroblob(i, n);
}

int SQLiteStatement_BindZeroBlob64(SQLiteStatement* self, int i, sqlite3_uint64 n)
{
    return self->bind_zeroblob64(i, n);
}

int SQLiteStatement_ClearBindings(SQLiteStatement* self)
{
    return self->clear_bindings();
}

const void* SQLiteStatement_ColumnBlob(SQLiteStatement* self, int iCol)
{
    return self->column_blob(iCol);
}

int SQLiteStatement_ColumnBytes(SQLiteStatement* self, int iCol)
{
    return self->column_bytes(iCol);
}

int SQLiteStatement_ColumnCount(SQLiteStatement* self)
{
    return self->column_count();
}

const char* SQLiteStatement_ColumnDecltype(SQLiteStatement* self, int iCol)
{
    return self->column_decltype(iCol);
}

double SQLiteStatement_ColumnDouble(SQLiteStatement* self, int iCol)
{
    return self->column_double(iCol);
}

int SQLiteStatement_ColumnInt(SQLiteStatement* self, int iCol)
{
    return self->column_int(iCol);
}

sqlite3_int64 SQLiteStatement_ColumnInt64(SQLiteStatement* self, int iCol)
{
    return self->column_int64(iCol);
}

const char* SQLiteStatement_ColumnName(SQLiteStatement* self, int iCol)
{
    return self->column_name(iCol);
}

const unsigned char* SQLiteStatement_ColumnText(SQLiteStatement* self, int iCol)
{
    return self->column_text(iCol);
}

int SQLiteStatement_ColumnType(SQLiteStatement* self, int iCol)
{
    return self->column_type(iCol);
}

SQLiteValue SQLiteStatement_ColumnValue(SQLiteStatement* self, int iCol)
{
    return self->column_value(iCol);
}

int SQLiteStatement_DataCount(SQLiteStatement* self)
{
    return self->data_count();
}

int SQLiteStatement_Finalize(SQLiteStatement* self)
{
    return self->finalize();
}

int SQLiteStatement_Reset(SQLiteStatement* self)
{
    return self->reset();
}

int SQLiteStatement_step(SQLiteStatement* self)
{
    return self->step();
}


/** SQLiteBlob **/


int SQLiteBlob_Bytes(SQLiteBlob* self)
{
    return self->bytes();
}

int SQLiteBlob_Close(SQLiteBlob* self)
{
    return self->close();
}

int SQLiteBlob_Read(SQLiteBlob* self, void *z, int n, int iOffset)
{
    return self->read(z, n, iOffset);
}

int SQLiteBlob_Reopen(SQLiteBlob* self, sqlite3_int64 iRow)
{
    return self->reopen(iRow);
}

int SQLiteBlob_Write(SQLiteBlob* self, const void *z, int n, int iOffset)
{
    return self->write(z, n, iOffset);
}


/** SQLite **/

SQLiteBackup SQLite_Backup(SQLite* self, SQLite pDestDb, const char* zDestDb)
{
    return self->backup(&pDestDb, zDestDb);
}

int SQLite_Changes(SQLite* self)
{
    return self->changes();
}

int SQLite_Close(SQLite* self)
{
    return self->close();
}

int SQLite_CreateFunction(SQLite* self, const char *zFunc, int nArg, int enc, void *p, void (*xSFunc)(sqlite3_context*,int,sqlite3_value **), void (*xStep)(sqlite3_context*,int,sqlite3_value **), void (*xFinal)(sqlite3_context*), void (*xDestroy)(void *))
{
    return self->create_function(zFunc, nArg, enc, p, xSFunc, xStep, xFinal, xDestroy);
}

int SQLite_CacheFlush(SQLite *self)
{
    return self->cacheflush();
}

int SQLite_ErrorCode(SQLite* self)
{
    return self->errcode();
}

const char* SQLite_ErrorMessage(SQLite* self)
{
    return self->errmsg();
}

const char* SQLite_ErrorString(SQLite* self, int errorCode)
{
    return self->errstr(errorCode);
}

sqlite3_int64 SQLite_LastInsertRowId(SQLite* self)
{
    return self->last_insert_rowid();
}

const char* SQLite_LibVersion(SQLite* self)
{
    return self->libversion();
}

int SQLite_LibVersionNumber(SQLite* self)
{
    return self->libversion_number();
}

int SQLite_Open(SQLite* self, const char* fileName, int flags)
{
    return self->open(fileName, flags);
}

int SQLite_Prepare(SQLite* self, const char* sql, int nBytes, SQLiteStatement* statement)
{
    return self->prepare(sql, nBytes, statement, nullptr);
}
