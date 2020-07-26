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
	std::cout << "ԭʼ����:\n";
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
	std::cout << "������������:\n";
	for(int j = 0; j < m; ++j)
	{
		std::cout << j << ":" << array[j] << " "; 
	}
	std::cout << std::endl;
	return 0;
}


/**
 *�Ƿ���ż��
 */
bool IsEvent( int num )
{
	return (num % 2 == 0);
}
 
/**
 *�Ƿ�������
 */
bool IsOdd( int num )
{
	return (num % 2 == 1);
}
 
/**
 *�㷨����
 */
bool OddEvent(int *a, int size)
{
 
	if( !IsEvent( size )  ) return false;
	int event_index = 0;	//ż���±�
	int odd_index = 1;	//�����±�
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
        if((i & 0x01) == 0){//����λ��
            if((array[i] & 0x01 )== 0){//��������
                while(j < length){
                    // ����λ�÷��õ��������������������
                    if((j & 0x01) == 0 && (array[j] &0x01) == 1) j++;
                    else {
                        // �����ż�������������
                        if((array[j] &0x01) == 0) j++;
                        else break;// �ҵ�����
                    }
                }
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }else{// ��ʾż��λ��
            if((array[i] & 0x01) ==1){//����ż��
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