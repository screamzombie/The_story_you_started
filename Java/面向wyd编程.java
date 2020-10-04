package qw.demo;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


public class mapreduce {
    public static class MyMap extends Mapper<LongWritable, Text, Text, Text> {
        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            //super.map(key, value, context);
            String[] lines = value.toString().split(",");  //把value,用","切分转化成一个字符串数组
            long sum = 0L;  //long型后面要加L
            long totalTimes = lines.length - 2;  // 这个其实具体题目具体对待的，就像以前用 Python 统计人数一样，具体对待数据
            for (int i = 2; i <= lines.length; i++) {
                sum += Long.parseLong(lines[i]);   //这句啥意思啊？
            }
            context.write(new Text(lines[0]), new Text(totalTimes + "_" + sum));
        }
    }

    public static class MyReduce extends Reducer<Text, Text, Text, Text> {
        @Override
        protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            //super.reduce(key, values, context);
            int count = 0; //考试人数计数器
            int totalScore = 0;//得分计数器
            int examTimes = 0; //考试次数计数器
            for (Text t : values) {   //和C++有点相似，类似的遍历写法
                String[] arrs = t.toString().split("_");
                count++;
                totalScore += Integer.parseInt(arrs[1]); // 得回去看看Java了
                examTimes += Integer.parseInt(arrs[0]);
            }
            float avg = totalScore * 1.0F / examTimes;

            context.write(key, new Text(count + "\t" + avg));
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf);   //报错一定要看看前面import到底对不对
        job.setJarByClass(mapreduce.class);  //写你自己写的类的名字

        job.setMapperClass(MyMap.class);   //套话
        job.setReducerClass(MyReduce.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        FileInputFormat.setInputPaths(job, new Path("data/studentsScore.txt")); //导入不对再换一个包，我感觉还是全部导入算了
        FileOutputFormat.setOutputPath(job, new Path("data/output"));

        job.waitForCompletion(true);  //必须要有这些话
        System.out.println("代码运行结束！");
    }
}