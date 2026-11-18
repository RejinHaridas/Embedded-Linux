#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#define WR_VALUE _IOW('a','a',int32_t)
#define RD_VALUE _IOR('a','b',int32_t)

int value;
int number;
int main() 
{       
        int fd=0;
        fd=open("/dev/etx_device",O_RDWR);
        if(fd<0)
        {
                printf("Unable to open the file\n");
                return 0;
        }
        printf("Enter the value to send\n");
        scanf("%d",&number);
        printf("Passing the value to the device file\n\n");
        ioctl(fd,WR_VALUE,(int32_t*)&number);


        printf("Reading the value from the device file\n");
        ioctl(fd,RD_VALUE,(int32_t*)&value);
        printf("%d\n",value);

        printf("Closing file\n");
        close(fd);

        return 0;
}









 
