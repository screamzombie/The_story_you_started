// 感谢老王！！！
// 记得版本降低
package cn.qw.demo

import org.apache.spark.SparkConf
import org.apache.spark.SparkContext

// WordCount
object study {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
    conf.setMaster("local")
    conf.setAppName("WordCount")
    //上面的都是套话
    val context =new SparkContext(conf)
    val RDD1 =context.textFile("data/word.text")
    // 把一个文件转化为RDD数据集
    val RDD2 = RDD1.flatMap(line => line.split(","))  //扁平化切片
    RDD2.foreach(println)  //读给自己看
    val RDD3 = RDD2.map(word=>(word,1))  //在每个后面加1，变成键值对
    RDD3.foreach(println)
    
    val RDD4 = RDD3.reduceByKey((x,y)=>x+y)//累积
    RDD4.foreach(println)//再次输出
    println("测试结束！")    
  }
}