/************************************************************************/
/* Name     : SW_CTRL.H                     */
/* Description  : Task Module Declare             */
/* Product  : EtherDevice                       */
/* Module   : Ap-Switch_Control                         */
/* Author   : Henry Kung                     */
/* Date     : 08-01-2016                        */
/************************************************************************/ 
#include    "sw_task_mgnt.h"

extern task_info EXAMPLE_TASK;

static task_info *service_info[] = {
    &EXAMPLE_TASK,
};

void create_thread(service_name name){

    Ssys_createTask(
        service_info[name]->thread_info->priority,
        service_info[name]->thread_info->entry,  
        service_info[name]->thread_info->entry_parameter, 
        service_info[name]->thread_info->name,  
        service_info[name]->thread_info->stack_base, 
        service_info[name]->thread_info->stack_size,  
        service_info[name]->thread_info->thread_handle,
        service_info[name]->thread_info->thread_data  
    ); 
}

void service_create(service_name name){

    if (name != service_info[name]->task_enum)
    {
        printf("name != service_info[name]->task_enum \r\n");
        return;
    }

    service_info[name]->init();
    create_thread(name);
}

void service_start(service_name name){
    service_info[name]->start();
}

void service_stop(service_name name){
    service_info[name]->stop();
}

void service_destory(service_name name){
    service_info[name]->destory();
}

