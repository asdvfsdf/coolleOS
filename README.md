# coolleOS
## FOR 2024  

### RISCV工具链  
因为RISCV工具链太大了，所以就不放在这里了，有发行版也可以从gitee上下载，不建议在github上下载。  
gitee镜像：  
https://gitee.com/riscv-mcu/riscv-gnu-toolchain  
发行版：  
https://toolchains.bootlin.com/releases_riscv64-lp64d.html  
https://toolchains.bootlin.com/  
下载完将工具链/bin/加入目录即可

### 准备qemu  
可以到官网下载：  
https://www.qemu.org
也可以：  
sudo apt install qemu   
不过这样下载下来的是6版本，我是这样下载的，后期估计要换呢  

### 下载opensbi  
https://github.com/riscv-software-src/opensbi  
请将opensbi解压到当前工作目录
根据所需进行make  
我们使用opensbi的跳到目标地址的控件，所以目前来说是  
make PLATFORM=generic clean  
make PLATFORM=generic FW_JUMP_ADDR=0x80200000

### 运行项目
#### 清理之前项目
make clean
#### 制作新镜像
make
#### 运行
make run
#### gdb调试
make .gdbinit  
make gdb
#### push到仓库
make push mes="thanks\ for\ your\ help"  
mes的值是commit -m 要附带的信息
