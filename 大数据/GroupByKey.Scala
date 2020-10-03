package cn.qw.demo

import org.apache.spark.SparkConf
import org.apache.spark.SparkContext

object study {
  def main(args: Array[String]): Unit = {
      val conf = new SparkConf()
      .setMaster("local")
      .setAppName("study")      //设置
      
      val sc = new SparkContext(conf) //创建对象
      val student = sc.textFile("data/test.txt") //创建RDD
      // 前面的可以说都是固定格式了
      
      val tupleRDD1 = student
      .flatMap(line=>line.split(",")(4))
      .map(x => (x,1))
      
      tupleRDD1.groupByKey()  //分完组
               .map(x=>(x._1,x._2.sum))  //把数字加起来，组名不改
               .foreach(println)
      
      tupleRDD1.reduceByKey(_+_).foreach(println)
  }
}
