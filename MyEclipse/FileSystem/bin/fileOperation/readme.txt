

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