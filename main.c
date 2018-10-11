#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int arr[1000] , k=1;
    int sum=0;
    int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);
    pipe(fd6);
    pipe(fd7);
    pipe(fd8);
    pipe(fd9);
    pipe(fd10);
    for(int i=0;i<1000;i++)
    {
        arr[i]=k;
        k++;
    }
    for(int i=0;i<1000;i++)
    {
        sum=sum+arr[i];
    }
    int cpid1=fork();
    if (cpid1==0){
        for(int i=0;i<100;i++)
            {
                sum=sum+arr[i];
            }
            write(fd1[1], &sum , sizeof(sum));
            close(fd1[1]);
            exit(0);
    }
    else {
        int cpid2=fork();
        if(cpid2==0){
            for(int i=100;i<200;i++)
            {
                sum=sum+arr[i];
            }
            write(fd2[1], &sum , sizeof(sum));
            close(fd2[1]);
            exit(0);
        }
        else {
            int cpid3=fork();
            if(cpid3==0){
                for(int i=100;i<200;i++)
            {
                sum=sum+arr[i];
            }
            write(fd3[1], &sum , sizeof(sum));
            close(fd3[1]);
            exit(0);
            }
            else {
                int cpid4=fork();
                if(cpid4==0)
                {
                    for(int i=200;i<300;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd4[1], &sum , sizeof(sum));
                    close(fd4[1]);
                    exit(0);
                }
                else {
                int cpid5=fork();
                if(cpid5==0)
                {
                    for(int i=300;i<400;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd5[1], &sum , sizeof(sum));
                    close(fd5[1]);
                    exit(0);
                }
                else {
                int cpid6=fork();
                if(cpid6==0)
                {
                    for(int i=400;i<500;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd6[1], &sum , sizeof(sum));
                    close(fd6[1]);
                    exit(0);
                }
                else {
                int cpid7=fork();
                if(cpid7==0)
                {
                    for(int i=500;i<600;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd7[1], &sum , sizeof(sum));
                    close(fd7[1]);
                    exit(0);
                }
                else {
                int cpid8=fork();
                if(cpid8==0)
                {
                    for(int i=600;i<700;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd8[1], &sum , sizeof(sum));
                    close(fd8[1]);
                    exit(0);
                }
                else {
                int cpid9=fork();
                if(cpid9==0)
                {
                    for(int i=700;i<800;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd9[1], &sum , sizeof(sum));
                    close(fd9[1]);
                    exit(0);
                }
                else {
                int cpid10=fork();
                if(cpid10==0)
                {
                    for(int i=800;i<900;i++)
                    {
                        sum=sum+arr[i];
                    }
                    write(fd10[1], &sum , sizeof(sum));
                    close(fd10[1]);
                    exit(0);
                }
                }

            }
        }
    }
        }
    }
            }
        }
    }
   for(int i =0;i<10;i++) wait(NULL);
    int res=0,total=0;
    read(fd1[0],&res,sizeof(int));
    close(fd1[0]);
    total=total+res;
    read(fd2[0],&res,sizeof(int));
    close(fd2[0]);
    total=total+res;
    read(fd3[0],&res,sizeof(int));
    close(fd3[0]);
    total=total+res;
    read(fd4[0],&res,sizeof(int));
    close(fd4[0]);
    total=total+res;
    read(fd5[0],&res,sizeof(int));
    close(fd5[0]);
    total=total+res;
    read(fd6[0],&res,sizeof(int));
    close(fd6[0]);
    total=total+res;
    read(fd7[0],&res,sizeof(int));
    close(fd7[0]);
    total=total+res;
    read(fd8[0],&res,sizeof(int));
    close(fd8[0]);
    total=total+res;
    read(fd9[0],&res,sizeof(int));
    close(fd9[0]);
    total=total+res;
    read(fd10[0],&res,sizeof(int));
    close(fd10[0]);
    total=total+res;
    printf("%d ",total);
    return 0;
}
