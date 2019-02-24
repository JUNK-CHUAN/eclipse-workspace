package fileOperation;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;

public class MultipleFileUnzip {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		// 待解压的zip文件需要在zip文件上构建输入流, 读取数据到Java中
		File file = new File("~/temp/multiple.zip"); // 定义压缩文件名
		File outFile = null;                         // 输出文件的时候需要有文件夹的操作
		ZipFile zipFile = new ZipFile(file);         // 实例化ZipFile对象
		ZipInputStream zipInput = null;              // 定义压缩输入流
		
		// 定义解压的文件名
		OutputStream out = null;                     // 定义输出流, 用于输出每一个实体内容
		InputStream input = null;                    // 定义输入流, 读取每一个ZipEntry
		ZipEntry entry = null;                       // 每一个压缩实体
		zipInput = new ZipInputStream(new FileInputStream(file)); // 实例化ZipInputStream
		
		// 遍历压缩包中的文件
		while ((entry = zipInput.getNextEntry()) != null) {       // 得到一个压缩实体
			System.out.println("解压缩" + entry.getName());
			outFile = new File("~/temp/" + entry.getName());      // 定义输出的文件路径
			if (!outFile.getParentFile().exists()) {              // 如果输出文件夹不存在
				outFile.getParentFile().mkdirs();
				// 创建文件夹, 如果这里有多级文件夹不存在, 需要mkdirs
				// 如果仅有一级文件夹不存在, 仅需mkdir
			}
			if (!outFile.exists()) {                 // 判断输出文件是否存在
				if (entry.isDirectory()) {
					outFile.mkdirs();
					System.out.println("Creating directory...");
				} else {
					outFile.createNewFile();
					System.out.println("Creating file...");
				}
			}
			if (!entry.isDirectory()) {
				input = zipFile.getInputStream(entry);
				out = new FileOutputStream(outFile);
				int temp = 0;
				while ((temp = input.read()) != -1) {
					out.write(temp);
				}
				input.close();
				out.close();
			}
			
		}
		input.close();
		zipInput.close();
		zipFile.close();
	}

}
