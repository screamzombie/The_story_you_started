package qw.demo;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;


import java.io.IOException;

/**
 * 使用 MapReduce 的处理方式,去除 words.txt 中以 2 开头的数字,将结果保存为num2.txt
 */
public class WordCount {
    public static class MyMapper extends Mapper<LongWritable, Text,Text,LongWritable> {
        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            // 这里重写了父类方法！
            String []words = value.toString().split(","); //转换成字符串后再切片
            for(String word:words){
                if(!word.startsWith("2")){  //这个方法我不知道怎么办呢？！
                    context.write(new Text(word),new LongWritable(1));
                }
            }
        }
    }
    public static class Myreduce extends Reducer<Text,LongWritable,Text,LongWritable> {
        @Override
        protected void reduce(Text key, Iterable<LongWritable> values, Context context) throws IOException, InterruptedException {
            long sum = 0L;
            for (LongWritable value : values) {
                sum += value.get();
            }
            context.write(key, new LongWritable(sum));
        }
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, WordCount.class.getSimpleName());  //开始使用套话了！！！

        job.setMapperClass(MyMapper.class);
        job.setReducerClass(Myreduce.class);

        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(LongWritable.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(LongWritable.class);

        FileInputFormat.setInputPaths(job,"data/numbers.txt");
        FileOutputFormat.setOutputPath(job, new Path("data/010"));  //问题来了我怎么知道应该导入什么类呢？
        // 还是说像上面的模板一样？？？

        job.waitForCompletion(true);
    }
}
