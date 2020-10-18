package spark_study

import org.apache.spark.{SparkConf, SparkContext}

/**
 *  使用Spark统计”房屋用途” 是 普通住宅 相关的 所在区域的占比（请提供完整代码和结果截图4分）。
 */
object ershoufangdiqu {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
    conf.setMaster("local")
    conf.setAppName("areanumbers")

    val sc = new SparkContext(conf)
    val RDD1 = sc.textFile("data/ershoufang-clean-utf8-v1.1.csv")
    //tmd你不切片，写个锤子啊
    val data1 = RDD1.map(line=>line.split(",")) //切片
    val data2 = data1.filter(f=>f(20)=="普通住宅") //这就是Scala这门语言的有趣之处了
    // 然后就是统计！！！
    //data2.foreach(line=>line.foreach(println))  //good！！！，你现在已经完全懂了！可以去写Scala了a
    val data3 = data2.map(line=>(line(2),1)) //取出元素并且把它变成元组的形式
    val sum_total = data3.count()    //总数
    val data4 = data3.reduceByKey(_+_) //按键取总和 还是比较简单的
    data4.foreach(line=>{
      println(line._1+":"+((line._2.toDouble*100/sum_total).formatted("%.2f"))+"%")
    })
    //data3.foreach(println)

  }
}
