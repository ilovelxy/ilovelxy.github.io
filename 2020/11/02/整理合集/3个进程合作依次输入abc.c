/**
 * 如下图所示，三个合作进程P1，P2，P3，他们都需要通过同一设备输入各自的数据a,b,c.该输入设备必须互斥地使用，
 * 而且其第一个数据必须由P1进程读取，第二个数据必须被P2进程读取，第三个数据必须被P3进程读取，然后，
 * 三个进程分别对输入数据进行下列计算：
 * P1:x=a+b;
 * P2:y=a*b;
 * P3:z=y+c-a;
 * 最后，P1进程通过所连接的打印机将计算结果x,y,z的值打印出来。
 * 请用信号量实现它们的同步。
 * 
 **/

/**
 * 分析：
 * 为了控制三个进程依次使用输入设备进行输入，需分别设置三个不同的信号量S1、S2、S3，其中S1的初值为1，
 * S2和S3的初值为0.使用上述信号量后，三个进程不会同时使用输入设备，因此不必再为输入设备设置互斥信号量。
 * 另外，还需要设置信号量Sb,Sy,Sz,分别表示数据b是否已经输入，以及y,z是否已计算完成，它们的初值均为0.
 * 三个进程的动作可描述为：
 * */

semaphore S1=1,S2=0,S3=0;
semaphore Sb=0,Sy=0,Sz=0;
P1(){
P(S1);
读入a;


P(Sb);

x=a+b;
P(Sy);
P(Sz);
输出x,y,z的值;
}

P2(){
P(S2);
读入b;
V(Sb);
V(s3);
y=a*b;
V(Sy);
}

P3(){
P(S3);
读入c;

P(Sy);
z=y+c-a;
V(Sz);
}
