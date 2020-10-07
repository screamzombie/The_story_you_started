package qw.demo;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class makeNUMBERS {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter("data/numbers.txt"));
        Random random = new Random();
        for(int i =0 ;i<10;i++) {
            int x = (int)Math.floor((random.nextDouble() * 100.0));
            if(i==0){
                bw.write(String.valueOf(x));
            }else{

                bw.write(x+""); //这个是JAVA的类型转换
            }
        }
        bw.close();
    }
}
