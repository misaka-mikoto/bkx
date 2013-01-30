BKX file backup tool 1.0.4
==

It can help me to backup the useful file!

BKX文件备份小工具，它可以帮助你备份有用文件！

使用方法：

1、使用ROOT权限执行make和make install命令完成安装，完毕后就可以使用bkx命令控制备份和恢复动作；

2、需要备份的时候使用bkx命令加-s参数再加上备份文件的源路径，比如：bkx -s /etc/samba/smb.conf；

3、如果需要恢复的时候把使用bkx加-r参数再加上源文件本来所在的详细路径，比如：bkx -r /etc/samba/smb.conf;

4、如果需要卸载的话，可以在安装包下ROOT权限执行make remove命令。
