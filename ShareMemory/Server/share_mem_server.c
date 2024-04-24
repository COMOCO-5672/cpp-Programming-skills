#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
int main() {
    // 获取共享内存的key
    key_t key = ftok("shared_mem_example", 1234);
 
    // 获取共享内存区域
    int shmid = shmget(key, sizeof(int), 0666);
    if (shmid == -1) {
        printf("Failed to get shared memory segment.\r\n");
        return 1;
    }
 
    // 将共享内存映射到进程的地址空间
    int* shared_data = (int*)shmat(shmid, NULL, 0);
    if (shared_data == (int*)-1) {
        printf("Failed to attach shared memory segment.\r\n");
        return 1;
    }
 
    // 从共享内存读取数据
    int data = *shared_data;
    printf("Data from shared memory: ");
 
    // 断开与共享内存的连接
    if (shmdt(shared_data) == -1) {
        printf("Failed to detach shared memory segment.\r\n");
        return 1;
    }
 
    return 0;
}