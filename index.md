## Welcome to GitHub Pages

一个数组有2n个元素，其中有n个奇数、n个偶数，数组无序，写一个算法使得奇数位置放置奇数，偶数位置放置偶数。

解题思路：
刚开始想到的算法很暴力，先遍历用队列分别存储奇数和偶数，然后分别将偶、奇数队列出队放入数组中。

后来查资料用双指针或双索引可以较好的解决此问题：
偶数索引遍历数组的偶数索引位置，奇数索引遍历数组的奇数索引位置。
判断是否符合条件，不符合交换位置。这样一次遍历即可调整好位置。

/**
 *算法内容
 *a为数组
 *size为数组a的长度
 */
bool OddEvent(int *a, int size)
{
    if( !IsEvent( size )  ) return false;
    int event_index = 0;    //偶数下标
    int odd_index = 1;      //奇数下标
    while(event_index <= size - 2 && odd_index <= size - 1)
    {
        while( IsEvent( a[event_index] ) ) event_index += 2;
        while( IsOdd( a[odd_index] ) )     odd_index   += 2;
        if(event_index <= size - 2 && odd_index <= size - 1)
        {
            swap(&a[event_index], &a[odd_index]);
            event_index += 2;
            odd_index += 2;
	}
    }
    return true;
}
/**
 *是否是偶数
 */
bool IsEvent( int num )
{
    return (num % 2 == 0);
}
 
/**
 *是否是奇数
 */
bool IsOdd( int num )
{
    return (num % 2 == 1);
}
void swap(int *a, int *b){
    int p;
    p = *a;
    *a = *b;
    *b = p;
}


