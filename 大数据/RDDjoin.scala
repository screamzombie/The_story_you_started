package cn.qw.demo

import org.apache.spark.SparkConf
import org.apache.spark.SparkContext
import org.apache.spark.SparkConf

object SparkUnion {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setMaster("local")
      .setAppName("study")

    val sc = new SparkContext(conf)
    val students = sc.textFile("data/students.txt")
    val score = sc.textFile("data/score.txt")
    val stuRDD = students.map(line => (line.split(",")(0), line)) //学号做为key，一整行作为value
    val scoreRDD = score.map(line => (line.split(",")(0), line))

    val joinRDD = stuRDD.join(scoreRDD) //连接俩个RDD 做的是笛卡尔积
    //  joinRDD.foreach(println)
    val scoreInfoRDD = joinRDD.map(x => {
      val id = x._1
      val studentInfo = x._2._1
      val scoreInfo = x._2._2
      val strings = scoreInfo.split(",")
      studentInfo + "," + strings(1) + "," + strings(2)
    })
    val sumCoreRDD = scoreInfoRDD
    .map(line=>line.split(","))
    .map(list=>(list.take(5).mkString(","),list(6).toInt))
    .reduceByKey((x, y) => x + y)
    .map(x=>x._1+","+x._2)
                    
    sumCoreRDD.saveAsTextFile("data/004")
        
    val avg = scoreInfoRDD
    .map(line => line.split(","))
    .map(line => (line.take(5).mkString(","),line(6)toInt))
    .groupByKey
    .map(x => (x._1,x._2.sum / x._2.count(x=>true).toDouble))
    
    
    avg.foreach(println)
    
  }
}
