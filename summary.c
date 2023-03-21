// 排序算法总结

                平均时间复杂度     最好情况     最坏情况     空间复杂度     稳定性     比较算法
冒泡排序           O(n^2)           O(n)       O(n^2)         O(1)        稳定        是
选择排序           O(n^2)          O(n^2)      O(n^2)         O(1)       不稳定       是
插入排序           O(n^2)           O(n)       O(n^2)         O(1)        稳定        是
希尔排序       O(nlogn)~O(n^2)    O(n^1.3)     O(n^2)         O(1)       不稳定       是
归并排序          O(nlogn)        O(nlogn)    O(nlogn)        O(n)        稳定        是
快速排序          O(nlogn)        O(nlogn)     O(n^2)        O(logn)     不稳定       是
堆排序            O(nlogn)        O(nlogn)    O(nlogn)        O(1)       不稳定       是
计数排序           O(n+k)          O(n+k)      O(n+k)         O(k)        稳定        否    
桶排序             O(n+c)           O(n)       O(n^2)        O(n+k)       稳定        否
基数排序           O(n*k)          O(n*k)      O(n*k)        O(n+k)       稳定        否

快速排序比归并排序要快，快速排序和归并排序都会有常数因子，会给程序的效率带来一定的影响，
快速排序的常数因子比归并排序的常数因子小得多，快速排序比归并排序更快，而且快速排序的空间复杂度更低。

快速排序比堆排序要快，堆排序存在将根节点从堆上拿走以后，剩下的节点存在堆重建的过程，堆重建的过程
也是要消耗时间的，需要比较很多次才能建二叉树变成二叉堆，堆排序大量的时间消耗在堆重建上，从效率
上快速排序是要优于堆排序的。

快速排序最坏情况会达到O(n^2)的情况，这取决于基准数的选取，基准数的选取也有优化的办法，
比如三取样划分，队头/队尾/中间，以及JDK的双轴排序对快速排序的改进。

如果数据量较小，可以采用选择排序，数据量较大，采用快速排序，灵活使用这两种排序可以达到更高的效率。