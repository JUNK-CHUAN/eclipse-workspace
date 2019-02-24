Java 与 文件系统 是两套系统

Java读写文件只能以(数据)流的形式进行读写

Java.io包中包含：
	节点类：直接对文件进行读写
	包装类：  转化类：字节/字符/数据类型的转化类
		装饰类：装饰节点类

字节：byte, 8bit, 最基础的存储单位
字符：a, 1000, 我
数据类型：3, 5.25, abcdef
文件以字节保存, 因此程序将变量保存到文件需要转化

  节点类：直接操作文件类
    InputStream, OutputStream(字节)
      FileInputStream, FileOutputStream
    Reader, Writer(字符)
      FileReader, FileWriter
  转换类：字符到字节之间的转换
    InputStreamReader：文件读取时字节转化为Java能理解的字符
    OutputStreamWriter：Java将字符转化为字节输入到文件中
  装饰类：装饰节点类
    DataInputStream, DataOutputStream：封装数据流
    BufferedInputStream, BufferedOutputStream：缓存字节流
    BufferedReader, BufferedWriter：缓存字符流


Java.io:
    字符流：
      Writer:
	OutputStreamWriter(转换流):FileWriter
	PrintWriter(打印流)
	FileWriter(过滤流)
	StringWriter(字符串流)
	PipedWriter(管道流)
	CharArrayWriter(内存流)
      Reader:
	InputStreamReader(转换流):FileReader
	BufferedReader(缓冲流):LineNumberReader
	FileReader(过滤流):PushbackReader
	StringReader(字符串流)
	PipeReader(管道流)
	CharArrayReader(内存流)
    字节流：
      InputStream:
	FileInputStream(文件流)
	ByteArrayInputStream(内存操作流)
	PipeInputStream(管道流)
	FilterInputStream(过滤流):
	    DataInputStream(数据操作流)
	    InflaterInputStream: ZipInputStream(压缩流)
	    BufferedInputStream(缓冲流)
	    PushbackInputStream(回退流)
	SequenceInputStream(合并流)
	ObjectInputStream(合并流)
      OutputStream:
	FileOutputStream(文件流)
	ByteArrayOutputStream(内存操作流)
	PipedOutputStream(管道流)
	FilterOutputStream(过滤流):
	    PrintStream(打印流)
	    DataOutputStream(数据操作流)
	    BufferedOutputStream(缓冲流)
	    DeflaterOutputStream: ZipOutputStream(压缩流)
	ObjectOutputStream(对象流)
    文件处理：
	File:
	FileFilter:
	FilenameFilter:
	RandomAccessFile:
	FileDescriptor:
    其他流：



Java zip包支持Zip 和 Gzip 包的压缩和解压缩
Zip文件操作类：java.util.zip
	-java.io.InputStream, java.io.OutputStream 的子类
	-ZipInputStream, ZipOutputStream 压缩文件输入/输出流
	-ZipEntry压缩项
单个/多个压缩
	-打开输出zip文件
	-添加一个ZipEntry
	-打开一个输入文件, 读数据, 向ZipEntry写数据, 关闭输入文件
	-重复以上两个步骤, 写入多个文件到zip文件中
	-关闭zip文件
	-查看SingleFileZip.java 和 MultipleFileZip.java
单个/多个解压
	-打开输入的zip文件
	-获取下一个ZipEntry
	-新建一个目标文件, 从ZipEntry读取数据, 向目标文件写入数据, 关闭目标文件
	-重复以上两个步骤, 从zip包中读取数据到多个目标文件
	-关闭zip文件
	-查看SingleFileUnzip.java 和 MultipleFileUnzip.java