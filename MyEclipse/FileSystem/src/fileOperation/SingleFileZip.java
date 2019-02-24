package fileOperation;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class SingleFileZip {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		File file = new File("~/temp/abc.txt");            // 定义要压缩的文件
		File zipFile = new File("~/temp/single.zip");      // 定义压缩文件名称
		
		InputStream input = new FileInputStream(file);     // 定义文件的输入流
		ZipOutputStream zipOut = null;                     // 声明压缩流
		zipOut = new ZipOutputStream(new FileOutputStream(zipFile));
		zipOut.putNextEntry(new ZipEntry(file.getName())); // 设置ZipEntry对象
		zipOut.setComment("single file zip");              // 设置注释
		
		int temp = 0;
		while((temp = input.read()) != -1) {
			zipOut.write(temp);
		}
		input.close();
		zipOut.close();
		System.out.println("single file zip done.");
	}

}
