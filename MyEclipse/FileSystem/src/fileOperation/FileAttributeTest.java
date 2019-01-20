package fileOperation;

import java.io.*;

public class FileAttributeTest {

	public static void main(String[] args) {
		// 创建目录
		File d = new File("~/temp");
		if (!d.exists()) {
			d.mkdirs();
		}
		System.out.println("Is d directory?" + d.isDirectory());
		
		// 创建文件
		File f = new File("~/temp/abc.txt");
		if (!f.exists()) {
			try {
				f.createNewFile();
			}catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		// 输出文件相关属性
		System.out.println("Is a file?" + f.isFile());
		System.out.println("Name: " + f.getName());
		System.out.println("Parent: " + f.getParent());
		System.out.println("Path: " + f.getPath());
		System.out.println("Size: " + f.length() + "bytes");
		System.out.println("Last Modified time: " + f.lastModified() + "ms");
		
		// 遍历d目录下的所有的文件信息
		System.out.println("list file in d dictionary");
		File[] fs = d.listFiles();
		for (File fi:fs) {
			System.out.println(fi.getPath());
		}
		
		// 删除目录呵文件夹
		//f.delete()
		//d.delete()
	}
}
