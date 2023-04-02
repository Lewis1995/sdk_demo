#include "user.h"

void * callback(void * arg) {
    printf("----> %s()\n", __func__);
    printf("child thread...\n");
    printf("arg value: %d\n", *(int *)arg);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int num = 2000;

    printf("----> %s()\n", __func__);

    // 创建一个子线程
    int ret = pthread_create(&tid, NULL, callback, (void *)&num);
 
    if(ret != 0) {
        char * errstr = strerror(ret);
        printf("error : %s\n", errstr);
    }

    for(int i = 0; i < 5; i++) {
        printf("---- [%d]\n", i);
    }

    sleep(1);

    // coding in dev
    // ...
    // ...
    // fix bug 101

    os_system("test");
    get_network();

    return 0;
}

