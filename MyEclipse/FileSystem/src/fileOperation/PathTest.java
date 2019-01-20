package fileOperation;

import java.io.File;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;


public class PathTest {

	public static void main(String[] args) {
		// Path 和 java.io.File 基本相似
		// 获得path方法一, ~/temp/abc.txt
		Path path = FileSystems.getDefault().getPath("~/temp", "abc.txt");
		System.out.println(path.getNameCount());
		
		// 获取path方法二, 用File的toPath()方法获得Path对象
		File file = new File("~/temp/abc.txt");
		Path pathOther = file.toPath();
		// 0,说明这两个Path是相等的
		System.out.println(path.compareTo(pathOther));
		
		// 获取Path方法三
		Path path3 = Paths.get("~/temp", "abc.txt");
		System.out.println(path3.toString());
		
		// 合并两个path
		Path path4 = Paths.get("~/temp");
		System.out.println("path4: " + path4.resolve("abc.txt"));
		
		if (Files.isReadable(path)) {
			System.out.println("it is readable");
		} else {
			System.out.println("it is not readable");
		}
	}
}
