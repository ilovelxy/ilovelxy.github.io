/**
 * 某寺庙有小和尚，老和尚若干，有一水缸，由小和尚提水入缸供老和尚饮用。水缸可容10桶水，水取自同一井中。水井径狭，每次只能容一个桶取水。水桶总数是3个。
 * 每次入缸取水仅为1桶水，且不可同时进行。试给出有关从缸取水、入水的算法描述
 * */

/** 分析：
 * 从井中取水并放入水缸是一个连续的动作，可视为一个进程；
 * 从缸中取水可视为另一个进程。
 * 设水井和水缸为临界资源，引入well和vat；
 * 3个水桶无论是从井中取水还是将水倒入水缸都是一次一个，应该给他们设置一个信号量pail，抢不到水桶的进程只好等待。
 * 水缸满时，不可以再放水，设置empty信号量来控制入水量；
 * 水缸空时，不可以取水，设置full信号量来控制。
 * */

semaphore well = 1, vat = 1;
semaphore pail = 3;
semaphore empty = 3, full = 0;

从井中取水
{
    while (1)
    {
        P(empty);
        P(pail); //桶
        P(well); //井
        从井中取水
        V(well);

        P(vat); //缸
        入缸;

        V(vat);
        V(pail);
        V(full);
    }
}

从缸中取水
{
    while (1)
    {
        P(full);
        P(pail);
        P(vat);

        取水；
        V(pail);
        V(vat);
        V(empty);
    }
}