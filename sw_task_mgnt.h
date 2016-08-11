/************************************************************************/
/* Name     : SW_CTRL.H                     */
/* Description  : Task Module Declare             */
/* Product  : EtherDevice                       */
/* Module   : Ap-Switch_Control                         */
/* Author   : Henry Kung                     */
/* Date     : 08-01-2016                        */
/************************************************************************/
#ifndef TASK_MGNT_H
#define TASK_MGNT_H

#include    <stdio.h>
#include    <stdlib.h>
#include    <network.h>
#include    <pthread.h>
#include    "system.h"

typedef struct thread_info_s {
    int             priority;
    void            (*entry)();
    int             entry_parameter;
    char            *name;
    void            *stack_base;
    int             stack_size;
    cyg_handle_t    *thread_handle;
    cyg_thread      *thread_data;
}thread_info;

typedef struct task_info_s {
    int task_enum;
    int (*init)();
    thread_info *thread_info;
    int (*start)();
    int (*stop)();
    int (*destory)();
}task_info;

typedef enum service_name_s {
    TASK_EXAMPLE,
} service_name;

void service_create(service_name name);
void service_start(service_name name);
void service_stop(service_name name);
void service_destory(service_name name);

#endif /* TASK_MGNT_H */