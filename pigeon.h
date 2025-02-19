/* pigeon.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;


// what is an email?

struct s_email {
    // sender and receiver mail addresses
    char src[64];
    char dest[64];
    // message id
    char id[64];
    // subject line
    char subject[128];
    // sender domain
    char* domain;
    // data (message)
    char data[];
};
typedef struct s_email Email;

struct s_server{
    // email domain
    char domain[64];
    // server
    char server[64];
    // ip adresses
    int32 ip;

};

typedef struct s_server Server;


#define $8 (int8 *)
#define $6 (int16)
#define $2 (int32)
#define $4 (int64)
#define $c (char *)
#define $i (int)



bool sendEmail(Email* email, Server* server);
bool sendMailHelper(char* from_addr, char* server_addr, char* server_ip);

int main(int,char**); 