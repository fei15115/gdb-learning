# GDB学习笔记

## 日期2023.05.05

### 搭建docker测试环境
```
FROM ubuntu:20.04
RUN \
      apt-get update && apt-get install -y \
      # general tools
      cmake \
      gcc \
      vim \
      gdb

CMD ["/bin/bash"]

docker build -t gdb-test:1.0 -f "path" .
```
----
### 简单的断点
break可以根据行号，函数以及条件生成断点。</br>
break+行号</br>     
```
break 6
```
break+函数名
```
break add
```
break+条件
```
break 10 if index==3
```
---
### 测试示例
```
    root@0f99be1456a0:/code/code-space/code-share/work-space/learn/GDB-learn/gdb-learning/code/add# gdb test.out
    (gdb) break 6
    Breakpoint 1 at 0x1149: file main.c, line 6.
    (gdb) c
    The program is not being run.
    (gdb) run
    Starting program: /code/code-space/code-share/work-space/learn/GDB-learn/gdb-learning/code/add/ test.out
    warning: Error disabling address space randomization: Operation not permitted
    Breakpoint 1, add (a=21956, b=108265568) at main.c:6
    warning: Source file is more recent than executable.
    6       {
    (gdb) step
    7               return a+b;
    (gdb) c
    Continuing.
    3
    [Inferior 1 (process 54) exited normally]
    (gdb)
```