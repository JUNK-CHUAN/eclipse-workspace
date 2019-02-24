package fileOperation;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class MultipleFileZip {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		File file = new File("~/temp/multiple");         // 定义要压缩的文件夹
		File zipFile = new File("~/temp/multiple2.zip"); // 定义压缩文件名称
		
		InputStream input = null;                        // 定义文件输入流
		ZipOutputStream zipOut = null;                   // 声明压缩流对象
		zipOut = new ZipOutputStream(new FileOutputStream(zipFile));
		zipOut.setComment("Multiple file zip");          // 设置注释
		
		// 开始压缩
		int temp = 0;
		if (file.isDirectory()) {                        // 判断是否是文件夹
			File lists[] = file.listFiles();             // 列出全部子文件
			for (int i = 0; i<lists.length; i++) {
				input = new FileInputStream(lists[i]);   // 定义文件的输入流
				zipOut.putNextEntry(new ZipEntry(file.getName() 
					+ File.separator + lists[i].getName())); // 设置ZipEntry对象
				System.out.println("正在压缩" + lists[i].getName());
				while ((temp = input.read()) != -1) {    // 读取内容
					zipOut.close();
				}
				input.close();
			}
		}
		zipOut.close();
		System.out.println("multiple file zip done.");
	}

}
