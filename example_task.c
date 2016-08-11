#include <sw_task_mgnt.h>

/* Thread Infomation */
#define SERVICE_ENUM            TASK_EXAMPLE
#define SERVICE_PRIORITY        DSYS_TASK_PRIORITY_HIGH9
#define SERVICE_NAME            "Example task"
#define SERVICE_STACK_SIZE      CYGNUM_HAL_STACK_SIZE_TYPICAL + (1024 * 8)

#define SERVICE_ENTRY_PARAMETER 0
static  char                    SERVICE_STACK[SERVICE_STACK_SIZE] ALIGN32;
static  cyg_handle_t            SERVICE_HANDLE;
static  cyg_thread              SERVICE_DATA;

/* Thread flag */
int running_flag;
int destory_flag;

/* Thread function */
void service_init(){
    destory_flag = 0;
    running_flag = 0;
}

void resume(){
    running_flag = 1;
}

void suspend(){
    running_flag = 0;
}

void destory(){
    destory_flag = 1;
}

void entry(cyg_thread_entry_t arg){

    while(1){

        Ssys_msDelay(100);

        if (destory_flag) {
            printf("task destory\r\n");
            break;
        }

        if (!running_flag) {
            printf("task suspend\r\n");
            continue; 
        }

        printf("task start\r\n");
    }
}

/* Thread Structure */
thread_info EXAMPLE_THREAD = {
    SERVICE_PRIORITY,
    entry,
    SERVICE_ENTRY_PARAMETER,
    SERVICE_NAME,
    &SERVICE_STACK[0],
    SERVICE_STACK_SIZE,
    &SERVICE_HANDLE,
    &SERVICE_DATA
};

task_info EXAMPLE_TASK = {
    SERVICE_ENUM,
    service_init,
    &EXAMPLE_THREAD,
    resume,
    suspend,
    destory,
};