package qw.demo;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

public class MapReduceLog {
    public static class MyMapper extends Mapper<LongWritable, Text,Text, NullWritable> {
        // 这里我有一个疑问，怎么判断传入传出的元素。怎么划分？？？
        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            String line = value.toString(); //将value转换成String ，但是我怎么判断呢？？？
            if(line.indexOf("uid")!=-1 && line.indexOf("platform")!=-1 && line.indexOf("app_version")!=-1
             && line.indexOf("pid")!=-1){
                line = line.replaceAll("\"locationcity\":0", "\"locationcity\":1"); //替换，这是什么规则？
            }
            context.write(new Text(line),NullWritable.get());
        }
    }

    public static class MyReduce extends Reducer<Text,NullWritable,Text,NullWritable> {
        @Override
        protected void reduce(Text key, Iterable<NullWritable> values, Context context) throws IOException, InterruptedException {
            for (NullWritable nullWritable:values){
                context.write(key,nullWritable);
            }
        }
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        //设置配置参数
        Configuration conf = new Configuration();
        //创建任务
        Job job = Job.getInstance(conf,MapReduceLog.class.getSimpleName());  //模板哦
        // 指定Jar文件，貌似在txt本地运行的时候，不需要设置下面的一句
        job.setJarByClass(MapReduceLog.class);
        //指定输入路径
        FileInputFormat.addInputPath(job,new Path("data/log.log"));  //要导入啥啥lib包

        //指定Mapper类
        job.setMapperClass(MyMapper.class);
        //指定map的输出的K V
        job.setMapOutputKeyClass(Text.class);
        job.setOutputValueClass(NullWritable.class);

        //指定reduce类
        job.setReducerClass(MyReduce.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(NullWritable.class);
        //设置输出文件路径
        FileOutputFormat.setOutputPath(job,new Path("data/005"));
        job.waitForCompletion(true);
    }

}
