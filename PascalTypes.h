//
//  PascalTypes.h
//  SQLitePlugin
//
//  Created by Brandon T on 2016-08-01.
//  Copyright © 2016 XIO. All rights reserved.
//

#ifndef PascalTypes_h
#define PascalTypes_h

const char* SQLiteContextRecord =
R"(
    packed record
        context: pointer;
    end;
)";

const char* SQLiteBackupRecord =
R"(
    packed record
        context: pointer;
    end;
)";

const char* SQLiteValueRecord =
R"(
    packed record
        context: pointer;
    end;
)";

const char* SQLiteStatementRecord =
R"(
    packed record
        context: pointer;
    end;
)";

const char* SQLiteBlobRecord =
R"(
    packed record
        context: pointer;
    end;
)";

const char* SQLiteRecord =
R"(
    packed record
        context: pointer;
    end;
)";

#endif /* PascalTypes_h */
