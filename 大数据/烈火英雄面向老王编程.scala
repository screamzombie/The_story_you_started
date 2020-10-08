package spark_study

import org.apache.spark.{SparkConf, SparkContext}

object movie2 {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
    conf.setAppName("movie2")
    conf.setMaster("local")

    val sc: SparkContext = new SparkContext(conf)

    val data1 = sc.textFile("data/log_movie.txt")
    val data2 = data1.map(line=>(line.split(",")(8),1))  //这一步是将 f => (f,1) 这样类似的东西
    //data2.foreach(println)
    val datasum = data2.count()  //保存数据总数！

    val data3 = data2.reduceByKey(_+_) //分组并求和的写法
    /**
     * 比如我的内存中存在如下的以key-value形式的数据集（RDD）：
     *
     * hello:1   sparkSubmit:1   red:1   sparkSubmit:1    hello:2    hello:1    hello:4    red:1   red:1   red:1 ... ...
     *
     * reduceByKey的作用对象是(key, value)形式的RDD，而reduce有减少、压缩之意，reduceByKey的作用就是对相同key的数据进行处理，最终每个key只保留一条记录。
     *
     * 保留一条记录通常有两种结果。一种是只保留我们希望的信息，比如每个key出现的次数。第二种是把value聚合在一起形成列表，这样后续可以对value做进一步的操作
     *
     * 以上面的数据集为例，在spark中比如是word：RDD[(String, Int)]  两个字段分别是word、单个单词在不同文件中出现的次数，现在我们需要统计每个单词出现的总次数。
     */
    //data3.foreach(println)
    data3.foreach(line => {   //这里加个花括号又是在搞什么哦！！！
      println(line._1+":"+(((line._2).toDouble/datasum)*100).formatted("%.2f")+"%")  //这是多么丑陋的代码啊
    })
    println("代码测试结束！")
  }
}
