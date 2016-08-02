#ifndef HN_DBLOGIN_H_INCLUDED
#define HN_DBLOGIN_H_INCLUDED

#define Status int
#define Status_OK 200
#define Status_Forbidden 403

Status db_login(MYSQL *);

#endif // HN_DBLOGIN_H_INCLUDED