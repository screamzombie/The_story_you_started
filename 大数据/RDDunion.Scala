package cn.qw.demo

import org.apache.spark.SparkConf
import org.apache.spark.SparkContext

object SparkUnion{
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
    .setMaster("local")
    .setAppName("study")
    
    val sc = new SparkContext(conf)
    
    val l1 = List(1,2,3,4,5)
    val l2 = List(6,7,8,9,0)
    
    val RDD1 = sc.parallelize(l1)  //将一个List转化成RDD
    val RDD2 = sc.parallelize(l2)
    
    val unionRDD = RDD1.union(RDD2)  //取并集
    unionRDD.foreach(println)
  }
}
