//
//  main.cpp
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//


#if defined _WIN32 || defined _WIN64
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#ifdef _MSC
#define _CRT_SECURE_NO_WARNINGS
#endif

#if defined _WIN32 || defined _WIN64
#define EXPORT_FUNC extern "C" __declspec(dllexport)
HMODULE module = NULL;
#else
#define EXPORT_FUNC extern "C"
#define __stdcall
#endif

#include <cstdint>
#include <cstdio>
#include <iostream>
#include "PascalTypes.h"



/*********************************************************************************************************************/

void* allocate_memory(int32_t size, int32_t element_size, void* (*SimbaAllocator)(int size))
{
    int32_t new_size = size * element_size;
    new_size += (sizeof(int32_t) * 2);

    void* ptr = SimbaAllocator(new_size);
    *((int*)ptr) = 1; //reference count.
    ptr = ((int*)ptr) + 1;
    *((int*)ptr) = size - 1; //size.
    ptr = ((int*)ptr) + 1;
    return ptr;
}

int32_t pascal_length(void* arr)
{
    return (*((int32_t*)arr) - 1) + 1;
}


/*********************************************************************************************************************/




static const int ABI_VERSION = 2;

static const char* PascalExports[] =
{
    "SQLiteContext_Aggregate", "function SQLiteContext.aggregate(nBytes: Integer): SQLiteContext;",
    "SQLiteContext_Count", "function SQLiteContext.count(): Integer;",
    "SQLiteContext_DBHandle", "function SQLiteContext.dbHandle(): SQLite;",

    "SQLiteBackup_Finish", "function SQLiteBackup.finish(): Integer;",
    "SQLiteBackup_PageCount", "function SQLiteBackup.pageCount(): Integer;",
    "SQLiteBackup_Remaining", "function SQLiteBackup.remaining(): Integer",
    "SQLiteBackup_Step", "function SQLiteBackup.step(nPage: Integer): Integer;",

    "SQLiteValue_BlobValue", "function SQLiteValue.blobValue(): SQLiteBlob;",
    "SQLiteValue_BytesValue", "function SQLiteValue.bytesValue(): Integer;",
    "SQLiteValue_DoubleValue", "function SQLiteValue.doubleValue(): Double;",
    "SQLiteValue_IntValue", "function SQLiteValue.intValue(): Integer;",
    "SQLiteValue_Int64Value", "function SQLiteValue.int64Value(): Int64;",
    "SQLiteValue_TextValue", "function SQLiteValue.textValue(): PChar;",
    "SQLiteValue_Type", "function SQLiteValue.valueType(): Integer;",
    "SQLiteValue_NumericType", "function SQLiteValue.numericType(): Integer;",

    "SQLiteStatement_BindBlob", "function SQLiteStatement.bindBlob(I: Integer; zData: Pointer; nData: Integer; xDel: procedure(ptr: Pointer)): Integer;",
    "SQLiteStatement_BindBlob64", "function SQLiteStatement.bindBlob64(I: Integer; zData: Pointer; nData: UInt64; xDel: procedure(ptr: Pointer)): Integer;",
    "SQLiteStatement_BindDouble", "function SQLiteStatement.bindDouble(I: Integer; rValue: Double): Integer;",
    "SQLiteStatement_BindInt", "function SQLiteStatement.bindInt(I: Integer; iValue: Integer): Integer;",
    "SQLiteStatement_BindInt64", "function SQLiteStatement.bindInt64(I: Integer; iValue: Int64): Integer;",
    "SQLiteStatement_BindNull", "function SQLiteStatement.bindNull(I: Integer): Integer;",
    "SQLiteStatement_BindParameterCount", "function SQLiteStatement.bindParameterCount(): Integer;",
    "SQLiteStatement_BindParameterIndex", "function SQLiteStatement.bindParameterIndex(name: String): Integer;",
    "SQLiteStatement_BindParameterName", "function SQLiteStatement.bindParameterName(i: Integer): PChar;",
    "SQLiteStatement_BindText", "function SQLiteStatement.bindText(I: Integer; zData: String; nData: Integer; xDel: procedure(ptr: Pointer)): Integer;",
    "SQLiteStatement_BindText64", "function SQLiteStatement.bindText64(I: Integer; zData: String; nData: Int64; xDel: procedure(ptr: Pointer); encoding: UInt8): Integer;",
    "SQLiteStatement_BindValue", "function SQLiteStatement.bindValue(I: Integer; value: SQLiteValue): Integer;",
    "SQLiteStatement_BindZeroBlob", "function SQLiteStatement.bindZeroBlob(i: Integer; n: Integer): Integer;",
    "SQLiteStatement_BindZeroBlob64", "function SQLiteStatement.bindZeroBlob64(i: Integer; n: Int64): Integer;",
    "SQLiteStatement_ClearBindings", "function SQLiteStatement.clearBindings(): Integer;",
    "SQLiteStatement_ColumnBlob", "function SQLiteStatement.columnBlob(iCol: Integer): Pointer;",
    "SQLiteStatement_ColumnBytes", "function SQLiteStatement.columnBytes(iCol: Integer): Integer;",
    "SQLiteStatement_ColumnCount", "function SQLiteStatement.columnCount(): Integer;",
    "SQLiteStatement_ColumnDecltype", "function SQLiteStatement.columnDeclType(N: Integer): PChar;",
    "SQLiteStatement_ColumnDouble", "function SQLiteStatement.columnDouble(iCol: Integer): Double;",
    "SQLiteStatement_ColumnInt", "function SQLiteStatement.columnInt(iCol: Integer): Integer;",
    "SQLiteStatement_ColumnInt64", "function SQLiteStatement.columnInt64(iCol: Integer): Int64;",
    "SQLiteStatement_ColumnName", "function SQLiteStatement.columnName(iCol: Integer): PChar;",
    "SQLiteStatement_Text", "function SQLiteStatement.columnText(iCol: Integer): PChar;",
    "SQLiteStatement_ColumnType", "function SQLiteStatement.columnType(iCol: Integer): Integer;",
    "SQLiteStatement_ColumnValue", "function SQLiteStatement.columnValue(iCol: Integer): SQLiteValue;",
    "SQLiteStatement_DataCount", "function SQLiteStatement.dataCount(): Integer;",
    "SQLiteStatement_Finalize", "function SQLiteStatement.finalize(): Integer;",
    "SQLiteStatement_Reset", "function SQLiteStatement.reset(): Integer;",
    "SQLiteStatement_Step", "function SQLiteStatement.step(): Integer;",

    "SQLiteBlob_Bytes", "function SQLiteBlob.bytes(): Integer;",
    "SQLiteBlob_Close", "function SQLiteBlob.close(): Integer;",
    "SQLiteBlob_Read", "function SQLiteBlob.read(z: Pointer; n: Integer; iOffset: Integer): Integer;",
    "SQLiteBlob_Reopen", "function SQLiteBlob.reopen(iRow: Integer): Integer;",
    "SQLiteBlob_Write", "function SQLiteBlob.write(z: Pointer; n: Integer; iOffset: Integer): Integer;",

    "SQLite_Backup", "function SQLite.backup(pDestDb: SQLite; zDestDb: String): SQLiteBackup;",
    "SQLite_Changes", "function SQLite.changes(): Integer;",
    "SQLite_Close", "function SQLite.close(): Integer;",
    "SQLite_CreateFunction", "function SQLite.createFunction(zFunc: String; nArg: Integer; enc: Integer; pCtx: Pointer; xSFunc: procedure(ctx: pointer; i: Integer; value: pointer); xDestroy: procedure(ptr: pointer)): Integer;",
    "SQLite_CacheFlush", "function SQLite.cacheFlush(): Integer;",
    "SQLite_ErrorCode", "function SQLite.errorCode(): Integer;",
    "SQLite_ErrorMessage", "function SQLite.errorMessage(): PChar;",
    "SQLite_ErrorString", "function SQLite.errorString(errorCode: Integer): PChar;",
    "SQLite_Exec", "function SQLite.exec(sql: String): Integer;",
    "SQLite_LastInsertRowId", "function SQLite.lastInsertedRowId(): Int64;",
    "SQLite_LibVersion", "function SQLite.libVersion(): PChar;",
    "SQLite_LibVersionNumber", "function SQLite.libVersionNumber(): Integer;",
    "SQLite_Open", "function SQLite.open(fileName: String; flags: Integer): Integer;",
    "SQLite_Prepare", "function SQLite.prepare(sql: String; nBytes: Integer; var statement: SQLiteStatement): Integer;"
};

static const char* PascalTypes[] =
{
    "SQLiteContext", SQLiteContextRecord,
    "SQLiteBackup", SQLiteBackupRecord,
    "SQLiteValue", SQLiteValueRecord,
    "SQLiteStatement", SQLiteStatementRecord,
    "SQLiteBlob", SQLiteBlobRecord,
    "SQLite", SQLiteRecord
};





void onLoad()
{
    //Do any initialisation here..
}

void onUnload()
{
    //Do any de-initialisation here..
}



/**********************************************************************************************************/



#if defined _WIN32 || defined _WIN64

EXPORT_FUNC BOOL __stdcall DllMain(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch(fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hInstDLL);
            module = hInstDLL;
            onLoad();
            break;

        case DLL_PROCESS_DETACH:
            onUnload();
            break;
    }
    return true;
}

#else

void __attribute__((constructor)) load()
{
    onLoad();
}

void __attribute__((destructor)) unload()
{
    onUnload();
}

#endif




/********************************************************************************************************************/


EXPORT_FUNC int GetPluginABIVersion();
EXPORT_FUNC int GetFunctionCount();
EXPORT_FUNC int GetTypeCount();
EXPORT_FUNC int GetFunctionInfo(int Index, void** Address, char** Definition);
EXPORT_FUNC int GetTypeInfo(int Index, char** Type, char** Definition);
EXPORT_FUNC int GetFunctionCallingConv(int Index);


int GetPluginABIVersion()
{
    return ABI_VERSION;
}

int GetFunctionCount()
{
    return sizeof(PascalExports) / (sizeof(PascalExports[0]) * 2);
}

int GetTypeCount()
{
    return sizeof(PascalTypes) / (sizeof(PascalExports[0]) * 2);
}

int GetFunctionInfo(int Index, void** Address, char** Definition)
{
    if (Index < GetFunctionCount())
    {
        #if defined _WIN32 || defined _WIN64
        *Address = (void*)GetProcAddress(module, PascalExports[Index * 2]);
        #else
        *Address = (void*)dlsym(RTLD_DEFAULT, PascalExports[Index * 2]);
        #endif
        strcpy(*Definition, PascalExports[Index * 2 + 1]);
        return Index;
    }
    return -1;
}

int GetTypeInfo(int Index, char** Type, char** Definition)
{
    if (Index < GetTypeCount())
    {
        strcpy(*Type, PascalTypes[Index * 2 + 0]);
        strcpy(*Definition, PascalTypes[Index * 2 + 1]);
        return Index;
    }
    return -1;
}

int GetFunctionCallingConv(int Index)
{
    if (Index < GetFunctionCount())
    {
        return ABI_VERSION;
    }
    return -1;
}
