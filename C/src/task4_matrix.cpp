#include<stdio.h>
#include<stdlib.h>
#include <time.h>  

int main()
{
	int vector[600]={0};
	int input[600][600]={0};   
	int output[600]={0};
	int i,j,k,m;
	
	clock_t start, finish; //�����һ�ε���CPUʱ�ӵ�λ��ʵ�ʣ��������Ϊ����һ��������
	double Total_time;//����һ��double���͵ı��������ڴ洢ʱ�䵥λ
	start = clock();//��ȡ����Ҫ����ִ��ʱ������֮ǰ��CPUʱ��ռ��ֵ
	
	//�������500*500��������� 
	 for (i = 0; i < 500; ++i)            
    {                                  
        for (j = 0; j < 500; ++j)        
        {                              
            input[i][j] = rand() % 1000; 
        }                              
    } 
   
   //�������500�������� 
   	for (j = 0; j < 500; ++j)        
        {                              
            vector[j] = rand() % 1000; 
        }
	
	start = clock();//��ʼ��ʱ 

 for(int m=0;m<1;m++)
 {
	 
	//����������� 
	for(i=0;i<500;i++)
	for(j=0;j<500;j++)
	{
		output[i]=output[i]+vector[j]*input[i][j];
	}
  }
  
    finish = clock();//ֹͣ��ʱ
	
	Total_time = (double)(finish-start)/CLK_TCK; //����ʱ��
	 
    //���������� 
	for(k=0;k<500;k++)
	printf("%d\n",output[k]);
	
		
	//�������ʱ��
	printf("���δ�������ʱ��Ϊ��%lf ms\n",1000*Total_time); 
	
	return 0;
	
}
