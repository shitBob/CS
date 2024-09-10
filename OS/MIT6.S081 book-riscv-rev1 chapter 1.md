本文为自学用途，主要参考MIT6.S081 book-riscv-rev1第一章
# 前置知识--进程函数

## 1 wait 函数 
在一个父进程中，使用wait函数将使父进程开始等待，直到他的一个子进程关闭。

成功执行时，返回值为孩子的PID，执行失败或者没有孩子时，返回-1。

同时可以根据status参数查看**子进程**exit的情况
```c
int pid;
int status;
pid =wait(&status);
```
## 2 fork 函数
复制一模一样的子进程。
父进程返回孩子的pid，子进程返回0
```c
pid_t pid = fork();
```
## 3 exec 函数 
exec让本程序跳到另外一个程序去，**并不回头了。**
第一个参数是执行的地址，第二个参数是执行的命令
```c
 char *argv[3];
 argv[0] = "echo";
 argv[1] = "hello";
 argv[2] = 0;
 exec("/bin/echo", argv);
 printf("exec error\n");   
```
原代码若成功执行，将不会执行printf("exec error\n"); 

---
# 前置知识 --文件描述符 
文件描述符是一种流的一种抽象，它是一个数字，和具体的对象发生连接，它背后是一个指针，指向目标文件。

默认情况下 0 标识标准输入流，1是标准输出流，2是标准错误流

注意，**每个进程都有自己独立的文件描述符**，存放在自己独立的file table中
##  1 read 函数

```c
read(fd,buf,n)
```
对文件描述符fd的连接对象进行读至多n个字节的读操作，to buf，并返回读取的字节数

错误时会返回-1 

offset机制：从文件的offset处读取数据，读一个offset往后移动一个地址，感觉是类似指针的东西，write也用到该机制
## 2 write 函数

```c
write(fd,buf,n)
```
对文件描述符fd的连接对象中进行写n个字节操作，from buf，并返回写的字节数。


## 例1 命令行中cat的实现 

```c
if (fork()==0)
{
   close(0);
   open("xxxx.txt",O_RDONLY);
   execl("cat","cat",NULL);
}

```
```c
%%cat
char buf[512];
read_size=512;
if (read(0,buf,read_size) != read_size)
{
  fprintf(2,"readerror!");
}
else
{
   if (write(1,buf,read_size) != read_size)
   fprintf(2,"writeerror!");
}
```
上述代码中，在命令行，创建子进程并关闭标准输入当前的连接（键盘），并打开要cat的文件，此时标准输入0 与 目标文件发生连接，后续read中，就会从目标文件中读取数据，最终写到标准输出连接的对象：控制台中。

 
 参数介绍
 O_RDONLY, O_WRONLY, O_RDWR, O_CREATE, and O_TRUNC, which instruct open to open the file  for reading, or for writing, or for both reading and writing, to create the file if it doesn’t exist, and to truncate the file to zero length.

## dup函数 
dup函数复制一个文件描述符，连接相同的底层IO对象
```c
 fd = dup(1);
 write(1, "hello ", 6);
 write(fd, "world\n", 6);
```
这时，fd也连接到标准输出流连接的对象，他和1一起输出了 hello world

**注意**：fork和dub相同的文件描述符（close之后可以关联不同文件）对于同一文件共享同一个offset，但是其他方式生成的文件描述符号，比如对于同一文件open两次，生成两个不同的文件描述符号，他们并不共享同一个offset


## 例：错误流的重定向
```powershell
ls existing-file non-existing-file > tmp1 2>&1
```
在这行代码中，相当于执行了  2=dup（1）这一行代码，原本代表错误流的文件符2也关联了标准输出流的对象。


# 前置知识pipe

## grep命令 
grep命令用于显示目标文件中带有某些条件的行 


### 1 展示日志文件中带有error的行
```sh
grep "error" log.txt
```

### 2 参数i，忽略大小写
```sh
grep -i "error" log.txt
```
n参数，显示行号
### 3 r参数，递归，在目录及子目录下查找目标文件

```sh
grep -r "error" ./src
```

### 4 l 参数 ，显示目标文件名而不是行 


```sh
grep -l "error" file1 file2 ...
```


### 5 正则表达式E ，多个正则表达式e，反向搜索v


## pipeline

### 1引例 
请看如下命令 

```powershell
grep fork sh.c | wc -l   
```
这个命令行的意思是，先找到sh文件中的fork行，作为输入，write端，通过管道传输，到读端 wc当中 ，wc即读这些输入，计算他们有多少行

所以最终的效果是计算sh文件中有多少行含有fork。
--- -



### 2 **pipe，管道 ，使用格式**

```powershell
cmd-left | cmd-right
```

左端是作为写端的命令，它的输出结果将通过管道传输到右边的读端当中。

### 3内核代码

```c
  case PIPE:
    pcmd = (struct pipecmd*)cmd;
    if(pipe(p) < 0)
      panic("pipe");
    if(fork1() == 0){
      close(1);
      dup(p[1]);
      close(p[0]);
      close(p[1]);
      runcmd(pcmd->left);
    }
    if(fork1() == 0){
      close(0);
      dup(p[0]);
      close(p[0]);
      close(p[1]);
      runcmd(pcmd->right);
    }
    close(p[0]);
    close(p[1]);
    wait(0);
    wait(0);
    break;
```


这里创建了两个子进程，一个重定向了它的标准输出到管道的pipe写端（p[1]），执行左端的命令，一个重定向了它的标准输入到pipe的读端(p[0])，执行右端的命令。

### 4 read阻塞机制
在一个进程中，如果用读端read p[0]，将会发生阻塞，直到所有引用写端的文件描述符（包括本进程和子进程）都读到了EOF或者关闭。

### 5 递归机制

### 6 pipe 的 终结 

```powershell
echo hello world | wc
```



```powershell
echo hello world >/tmp/xyz; 
wc </tmp/xyz 
```

使用临时文件，我们可以替代pipe，但是pipe还是有些好处的（学了这么久聊以自慰）


![pipe的优点](https://i-blog.csdnimg.cn/direct/74fc2d7ab39d40289e5682fe1e0a8bb8.png)
# 文件系统
文件系统，可以理解为一个树，以root根目录作为根节点，连接各个文件夹，文件
C语言中与文件系统相关的常见system call

## chdir 切换相对路径
类似于命令行中的cd
```c
chdir("/a");
chdir("/b");
```

## mkdir 创建路径
下端在当前目录下创建一个新的文件夹（路径），并在里面创建一个file

```c
mkdir("/dir")
fd = open("/dir/file", O_CREATE|O_WRONLY);
close(fd);
```

## mknod 创建设备文件
设备文件是和文件系统和相关硬件设备交互的特殊文件，读该文件进行读写时，将会和相关硬件进行交互而不是文件系统。

```c
mknod("/console",1,1)
```

## fstat
顾名思义 file-status，用于查看文件的状态

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

main()
{
   struct stat buf;
   int fd;
   fd = open ("/etc/passwd", O_RDONLY);
   fstat (fd, &buf);
   printf("/etc/passwd file size = %d\n",(int)(buf.st_size));
}
```
输出目标文件结果的字节数。
buf会返回一个存储相关文件信息的结构体
 ![stat结构体](https://i-blog.csdnimg.cn/direct/c292f813442e4dbc85caf039400ca16f.png)
 ## link & unlink

```c
open("a",O_CREATE|O_WRONLY);
link("a","b");
```

上述代码创建了一个a文件，并link了一个别名b。a和b有着相同的Inode，指向同一数据块

```c
unlink("a");
```
在上述代码的基础上，我们移除了名字a，但是文件会依然存在，它还有一个名字b，一个文件物理意义上的消失仅发生当它的**所有名字**和**引用它的文件描述符**都移除了。


### unlink创建临时文件小技巧

```c
fd = open ("/tmp/xyz",O_CREATE|O_WRONLY);
unlink("/tmp/xyz");
```

上述代码创建了一个临时文件xyz，但是又移除了临时文件的名字，这样，它剩下和fd产生关联，当该fd 关闭（close）时或者process 退出（exit） 时，这个临时文件将被清除。


## 相关命令行
上述文件system call主要是c语言，而命令行也提供了与文件系统相关的命令行程序。像是mkdir，ln，rm。而chdir对应的cd则是由cd内核实现的。







 













