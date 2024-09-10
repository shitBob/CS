# Learning GDB

## 1 start a gdb session

我们在命令行中输入
```
g++ -g -std=c++14 basic1.cc -o basic1
gdb ./basic1
```


第一行代码使得编译生成的可执行文件可以支持调试，第二行代码启动gdb调试器，并指定要调试的可执行文件。


## 2 set breakpoints


我们可以设置断点，在程序运行到断点处停下来，可以查看变量的值，或者进行单步调试。

```
break 12
run
```

设置断点的命令是`break`，后面跟着行号。运行程序的命令是`run`。

