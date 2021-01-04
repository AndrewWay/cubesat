/*
* client_api.h
*
*   purpose: provides API for other subsystems to use the IPC system as clients.
*   author: alex amellal
*
*/

#ifndef CUBESAT_CORE_INCLUDE_IPC_CLIENT_API_H
#define CUBESAT_CORE_INCLUDE_IPC_CLIENT_API_H

// Project headers
#include "settings.h"
#include "immut.h"
#include "client_t.h"

////////////////
//  C Version //
////////////////

#ifdef __cplusplus
extern "C" {
#endif

#include "client_api_old.h"

// Client API
int ipc_connect(const char *name);                                // Initialize client side IPC interface
int ipc_send(const char *dest, char * msg, size_t msg_len);       // Send message to another process
int ipc_recv(const char *src, char * buffer, size_t buffer_len);  // Receive message from another process (blocks)
int ipc_qsend(const char *dest, char * msg, size_t msg_len);      // Adds outgoing message to send queue
int ipc_qrecv(const char *src, char * buf, size_t buf_len);       // Adds incoming message request to recv queue
int ipc_refresh();                                            // Simultaneously reads/writes queued data
int ipc_disconnect();                                         // Close client side IPC interface

#ifdef __cplusplus
}
#endif

//////////////////
//  C++ Version //
//////////////////

#ifdef __cplusplus

#include "client_api.hpp"

#endif

#endif /* end of include guard: CUBESAT_CORE_INCLUDE_IPC_CLIENT_API_H */