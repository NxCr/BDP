#ifndef BDP_UDP_SOCKET
#define BDP_UDP_SOCKET
#include "platform.h"
#ifdef __cplusplus
extern "C" {
#endif

#if ISWINDOWS
    typedef unsigned long long socket_type;
#elif ISPOSIX
    typedef int socket_type;
#endif
typedef enum {
    UDP,
    TCP
} socket_protocol;

typedef enum {
    IPV4,
    IPV6
} ip_version;


// 0 on success, otherwise error code
int initialize_socket_lib();
void uninitialize_socket_lib();
int create_socket(socket_type* socket_out, socket_protocol type);

#ifdef __cplusplus
}
#endif
#endif