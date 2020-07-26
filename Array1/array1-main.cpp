#include <iostream>
#include <cstdlib>
//#include "stdafx.h"
#include <queue>

void sort(int * array ,int length);

bool IsEvent( int num );
bool IsOdd( int num );
bool OddEvent(int *a, int size);
void swap(int *a, int *b);
void Swap(int &a, int &b);
void Swap2(int& a, int& b);

int main(){
	int array[20]={1,2,1,2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2};//20
	int a[20]={1,2,1,2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2};//20
	int m =20;
	std::cout << "原始数组:\n";
	for(int i = 0; i < m; ++i)
	{
		std::cout << i << ":" << array[i] << " "; 
	}
	std::cout << std::endl;
	//sort(array,m);

	int index = 0;
	int odd_count = 0;
	int event_count = 0;
	OddEvent(array, m);
/*
	while( odd_count < event_count ) 
	{
		if( IsEvent( a[index] ) ) 
		{
			a[index]= GetOddNum();
			++odd_count;
			--event_count;
		}
		index++;
 
	}
	while( event_count < odd_count )
	{
		if( IsOdd( a[index] ) )
		{
			a[index] = GetEventNum();
			++event_count;
			--odd_count;
		}
		++index;  
	}
*/
	std::cout << "处理过后的数组:\n";
	for(int j = 0; j < m; ++j)
	{
		std::cout << j << ":" << array[j] << " "; 
	}
	std::cout << std::endl;
	return 0;
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
 
/**
 *算法内容
 */
bool OddEvent(int *a, int size)
{
 
	if( !IsEvent( size )  ) return false;
	int event_index = 0;	//偶数下标
	int odd_index = 1;	//奇数下标
	while(event_index <= size - 2 && odd_index <= size - 1)
	{
		while( IsEvent( a[event_index] ) ) event_index+=2;
		while( IsOdd( a[odd_index] ) ) odd_index+=2;
		if(event_index <= size - 2 && odd_index <= size - 1)
		{
			/*
			int tmp = a[event_index];
			a[event_index] = a[odd_index];
			a[odd_index] = tmp;	
			*/
			swap(&a[event_index], &a[odd_index]);
			//Swap(a[event_index], a[odd_index]);
			//Swap2(a[event_index], a[odd_index]);
			event_index += 2;
			odd_index += 2;
		}
	}
	return true;
}


void swap(int *a, int *b){
  int p;
  p = *a;
  *a = *b;
  *b = p;
}

void Swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void Swap2(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/*
void sort(int * array ,int length){
    for(int i = 0 ;i < length ; i++){
        int j = i+1;
        if((i & 0x01) == 0){//奇数位置
            if((array[i] & 0x01 )== 0){//不是奇数
                while(j < length){
                    // 奇数位置放置的是奇数，继续往后遍历
                    if((j & 0x01) == 0 && (array[j] &0x01) == 1) j++;
                    else {
                        // 如果是偶数继续往后遍历
                        if((array[j] &0x01) == 0) j++;
                        else break;// 找到奇数
                    }
                }
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }else{// 表示偶数位置
            if((array[i] & 0x01) ==1){//不是偶数
                while(j < length){
                    if((j & 0x01) == 1 && (array[j] &0x01) == 0) j++;
                    else {
                        if((array[j] &0x01) == 1) j++;
                        else break;
                    }
                }
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
*/