#include<stdio.h>
#include<stdlib.h>
#include <time.h>  

int main()
{
	int vector[600]={0};
	int input[600][600]={0};   
	int output[600]={0};
	int i,j,k,m;
	
	clock_t start, finish; //定义第一次调用CPU时钟单位的实际，可以理解为定义一个计数器
	double Total_time;//定义一个double类型的变量，用于存储时间单位
	start = clock();//获取进入要测试执行时间代码段之前的CPU时间占用值
	
	//随机生成500*500的输入矩阵 
	 for (i = 0; i < 500; ++i)            
    {                                  
        for (j = 0; j < 500; ++j)        
        {                              
            input[i][j] = rand() % 1000; 
        }                              
    } 
   
   //随机生成500的列向量 
   	for (j = 0; j < 500; ++j)        
        {                              
            vector[j] = rand() % 1000; 
        }
	
	start = clock();//开始计时 

 for(int m=0;m<1;m++)
 {
	 
	//计算输出矩阵 
	for(i=0;i<500;i++)
	for(j=0;j<500;j++)
	{
		output[i]=output[i]+vector[j]*input[i][j];
	}
  }
  
    finish = clock();//停止计时
	
	Total_time = (double)(finish-start)/CLK_TCK; //计算时间
	 
    //输出结果矩阵 
	for(k=0;k<500;k++)
	printf("%d\n",output[k]);
	
		
	//输出所用时间
	printf("本次处理所用时间为：%lf ms\n",1000*Total_time); 
	
	return 0;
	
}
