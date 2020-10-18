package cn.qw.demo

import org.apache.spark.SparkConf
import org.apache.spark.SparkContext
import org.apache.spark.SparkConf
import org.apache.spark.SparkConf

/*
 * 随着移动互联网、物联网等新技术的迅速发展，人类进入数据时代。
大数据带来的信息风暴正深刻改变我们的生活、工作和思维方式，对网络舆情管理也带来深刻影响。
在电影行业大数据舆情管理有着广泛的应用，可以通过舆情分析来判断当前电影的热度和影响度等。

id, created_at, attitudes_count, comments_count, reposts_count, screen_name, follow_count,followers_count, gender, text
字段含义：id,发布时间,点赞数,评论数,转发数,作者昵称,关注,粉丝数,博主性别,博客内容

1、该数据集log_movie.txt是通过网络爬虫从某主流媒体网站爬取下来的部分关于电影《烈火英雄》、《上海堡垒》的数据，请将该数据上传到hdfs中，目录可以自行创建指定

2、使用Spark将数据集中数据关于“烈火英雄”相关的数据提取出来，并回写到hdfs中（请提供编程代码）

3、使用Spark统计《烈火英雄》相关文章关于评论人性别的占比（请提供完整代码和结果截图5分）

4、统计关于《上海堡垒》话题的舆情走势，已知其上映时间为2019-08-09。（本题可以使用你擅长的编程语言和框架）

4.1、讨论热度的计算，按照日期对数据集中每日总评论数计算，按照日期排序（请提供完整代码和结果截图3分）
4.2、传播影响的计算，计算出转发次数最多的前5条文章，并列出该文章博主的粉丝数（请提供完整代码和结果截图3分) 
*/

object SparkUnion {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf()
      .setMaster("local")
      .setAppName("study")
    val sc = new SparkContext(conf)            
    
    val data = sc.textFile("data/log_movie.txt")  
    
    val data1 =  data.map(line=>(line.split(",")(8),1))  //也是从0开始计数，所以填的是8
    //data1.foreach(println)
    val sum = data1.count()   //返回数据集中存在的元素数，在这里就是算总数啦
    //println(sum)
    val data2 = data1.reduceByKey(_+_)  //按key分类,并且累计，这是一个简写，记住就行了哦，突击！突击！
    //于是在这里我们得到了俩种性别的人数总和
    /*
    val female =  data2.take(1).map(line=>line._2) // 通过这总方式就可以只输出一个了
    female.foreach(println)   //C味的Spark
    * */
    data2.foreach(line => {
      //println(line._1+":"+(line._2.toDouble/sum).formatted("%.2f").toDouble*100+"%") 你不能这么写，这样会把这个字符串重复输出100次类似python    
        println(line._1+":"+((line._2.toDouble/sum).formatted("%.2f").toDouble*100)+"%") //这其实也算是多此一举的写法了，我故意的
        //println(line._1 + ": " + (line._2.toDouble * 100 / sum).formatted("%.2f") + "%")  推荐写法
    } )   
  }
}
