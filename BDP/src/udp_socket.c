#include "udp/udp_socket.h"
#include "platform.h"
#include "types.h"

#if ISWINDOWS
    #include <winsock2.h>
    #pragma comment(lib, "ws2_32.lib") // get winsocks
    #include <Ws2ipdef.h>
#endif 

#if ISWINDOWS
static int wsaisinitialized = 0; 
#endif

// 0 on success, otherwise error code
int initialize_socket_lib(){
    #if ISWINDOWS
    if (!wsaisinitialized){
        WSADATA wsa;
        int ec = WSAStartup(MAKEWORD(2, 2), &wsa);
        if (!ec) wsaisinitialized = 1;
        return ec;
    }
    #elif ISUNIX
        return 0;
    #endif
}
void uninitialize_socket_lib(){
    if (wsaisinitialized){
        WSACleanup();
        wsaisinitialized = 0;
    }
}

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (socket_type)(-1)
#endif


typedef struct {
    u16 protocol_type;
    u16 port;
    union{
        struct {
            struct {
                union {
                    u32 value;
                    u8 bytes[4];
                    u16 words[2];
                };
            } addr;
            u8 zero[8];
        } v4;
        struct {         
            u32  flowinfo;
            struct {
                union {
                    u8  bytes[16];
                    u16 words[8];
                };
            } addr;
            union {
                struct {
                    u32 zone : 28;
                    u32 level : 4;
                };
                u32 id;
            } scope;
        } v6;
    };
} ip_address;

int create_socket(socket_type* socket_out, socket_protocol protocol){
    socket_type s;
    switch (protocol){
        case UDP: s = socket(AF_INET, SOCK_DGRAM, 0); break;
        case TCP: s = socket(AF_INET, SOCK_STREAM, 0); break;
    }
    int a6 = sizeof(struct sockaddr_in6);
    int a4 = sizeof(struct sockaddr_in);
    int a = sizeof(ip_address);
}