import java.io.File;
import java.util.Random;
import java.io.*;

public class matrix
{
    //生成随机矩阵
    public static void matrix_rand(int [][]mat,int rows,int cols)
    {
        Random rand = new Random();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                mat[i][j] = rand.nextInt(100)+1;
            }
        }
    }

    //矩阵与向量相乘
    public static void matrix(int [][]A, int [][]B, int [][]C)
    {
        for(int i=0;i<500;i++)
        {
            for(int j=0;j<1;j++)
            {
                C[i][j] = 0;
                for(int k = 0; k < 500; k++)
                {
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    }

    public static void writeFile(int [][]A, String filename,int rows,int cols) {
        try {
            File writeName = new File(filename);
            writeName.createNewFile(); // 创建新文件
            try (FileWriter writer = new FileWriter(writeName);
            ) {
                for(int i=0; i<rows;i++)
                {
                    for(int j=0;j<cols;j++)
                    {
                        writer.write(String.valueOf(A[i][j]));
                        writer.write(" ");
                    }
                    writer.write("\n");
                }
                writer.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //主函数
    public static void main(String[] args){
        int [][]input=new int[600][600];
        int [][]vector=new int[600][600];
        int [][]output=new int[600][600];

        matrix_rand(input,500,500);
        matrix_rand(vector,500,1);
        writeFile(input, "input.txt",500,500);
        writeFile(vector, "vector.txt",500,1);

        long startTime = System.currentTimeMillis();    //获取开始时间

        for(int i=0;i<1;i++)
        {
            matrix(input, vector, output);
        }

        long finishTime = System.currentTimeMillis();    //获取结束时间

        writeFile(output, "output.txt",500,1);
        System.out.println("计算结束，结果存入输出文件中!");

        System.out.println("本次处理所用时间：" + (finishTime - startTime) + "ms");    //输出程序运行时间
    }
}
