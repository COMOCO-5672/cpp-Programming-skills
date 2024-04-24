#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
int main() {
    // 创建共享内存的key
    key_t key = ftok("shared_mem_example", 1234);
 
    // 创建共享内存区域
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create shared memory segment.");
        return 1;
    }
 
    // 将共享内存映射到进程的地址空间
    int* shared_data = (int*)shmat(shmid, NULL, 0);
    if (shared_data == (int*)-1) {
        printf("Failed to attach shared memory segment.");
        return 1;
    }
 
    // 写入数据到共享内存
    *shared_data = 42;
 
    // 断开与共享内存的连接
    if (shmdt(shared_data) == -1) {
        printf("Failed to detach shared memory segment.");
        return 1;
    }
 
    // 删除共享内存
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Failed to delete shared memory segment.");
        return 1;
    }
 
    return 0;
}