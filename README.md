# SW_TASK_MNGT


1. 統一task coding style
2. create task不要各寫各的function, 統一使用task api

與之前討論不同的地方

1. 不使用running_flag, 直接將resume()跟suspend()的function pointer丟出來使用 (原因:可能在暫停或開始的時候做其他事情, 所以由各個task自行定義)

外部使用task api對task進行控制

1. service_create(service_name name)  - init & create task
2. service_start(service_name name)   - task start
3. service_stop(service_name name)    - task suspend
4. service_destory(service_name name) - task destory

Step

1. 在sw_task_mgnt.h註冊service_name
		typedef enum service_name_s {
    		TASK_EXAMPLE,
		} service_name;
2. 在sw_task_mgnt.c新增 service_info[] 加入自己的task_info pointer
static task_info *service_info[] = {
    &EXAMPLE_TASK,
};
3. 複製example_task.c 修改Thread information
#define SERVICE_ENUM            TASK_EXAMPLE
#define SERVICE_PRIORITY        DSYS_TASK_PRIORITY_HIGH9
#define SERVICE_NAME            "Example task"
#define SERVICE_STACK_SIZE      CYGNUM_HAL_STACK_SIZE_TYPICAL + (1024 * 8)
task_info EXAMPLE_TASK
