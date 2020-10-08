package spark_study

import org.apache.spark.{SparkConf, SparkContext}


/**
 * 使用Spark将数据集中”房屋用途” 是 普通住宅 并且 交易权属 是 商品房 的相关的数据提取出来，
 * 并回写到ershoufang目录中，如果文件ershoufang存在就删除原有的目录 （请提供编程代码）（3分）。
 */
object ershoufang {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
    conf.setAppName("ershoufang")
    conf.setMaster("local")

    val sc = new SparkContext(conf)
    val data1 =  sc.textFile("data/ershoufang-clean-utf8-v1.1.csv") //读文件
    val data2 = data1.map(line => line.split(","))  //用,切分
    //data2.foreach(println)
    val data_1 = data2.filter(f=>f(20)=="普通住宅")  //如果是真就返回一个true，因为scala默认最后一个是返回值
    val data_2 = data2.filter(f=>f(18)=="商品房")
    val data_3 = data_2.map(line => line.mkString(","))  //写回数据中
    data_3.saveAsTextFile("data/hello")
  }
}
