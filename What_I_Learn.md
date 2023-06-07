# GDB学习笔记

## 更新日期2023.05.07

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
## 简单的断点
break可以根据行号，函数以及条件生成断点。</br>
tbreak和break类似，只是tbreak只会停一次
### 创建断点
```
break+行号</br>             break 6                 
break+函数名                break add               
break+条件                  break 10 if index==3
break+文件+函数名
---------------------------------------------------------------------------------
(gdb) b break_test.c:add
Breakpoint 6 at 0x5572b858d149: file break_test.c, line 4.
(gdb) info b
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x00005572b858d194 in main at break_test.c:14
        stop only if c>=50
6       breakpoint     keep y   0x00005572b858d149 in add at break_test.c:4
(gdb)    
```
### 列出断点
```
(gdb) info b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x00005572b858d149 in add at break_test.c:4
        breakpoint already hit 1 time
2       breakpoint     keep y   0x00005572b858d194 in main at break_test.c:14
        stop only if c>=50
(gdb)
```
### 删除断点
```
delete breakpoint 3 4 5
(gdb) info b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001149 in add at break_test.c:4
2       breakpoint     keep y   0x0000000000001194 in main at break_test.c:14
        stop only if c>=50
3       breakpoint     keep y   0x0000000000001194 in main at break_test.c:14
        stop only if c>=50
4       breakpoint     keep y   0x0000000000001194 in main at break_test.c:14
        stop only if c>=50
5       breakpoint     keep y   0x0000000000001194 in main at break_test.c:14
        stop only if c>=50
(gdb) delete breakpoint 3 4 5
(gdb) info b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000001149 in add at break_test.c:4
2       breakpoint     keep y   0x0000000000001194 in main at break_test.c:14
        stop only if c>=50
```