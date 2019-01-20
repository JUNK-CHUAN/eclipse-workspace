package fileOperation;

import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.Date;

public class FilesTest {

	public static void main(String[] args) {
		moveFile();
		fileAttributes();
		createDirectory();
	}
	
	public static void moveFile() {
		Path from = Paths.get("~/temp", "abc.txt");
		// 移动~/temp/abc.txt到~/temp/test/def.txt, 若目标已存在，则替换
		Path to = from.getParent().resolve("test/def.txt");
		try {
			// 文件的大小bytes
			System.out.println(Files.size(from));
			// 调用文件移动方法，若存在，则替换
			Files.move(from, to, StandardCopyOption.REPLACE_EXISTING);
		}catch (IOException e) {
			System.err.println("移动文件夹错误" + e.getMessage());
		}
	}
	
	public static void fileAttributes() {
		Path path = Paths.get("~/temp");
		// 1
		System.out.println(Files.isDirectory(path, LinkOption.NOFOLLOW_LINKS));
		// 2
		try {
			// 获取文件属性
			BasicFileAttributes attributes = Files.readAttributes(path, 
					BasicFileAttributes.class);
			System.out.println(attributes.isDirectory());
			System.out.println(new Date(attributes.lastModifiedTime().toMillis()));
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void createDirectory() {
		Path path = Paths.get("~/temp");
		try {
			if (Files.notExists(path)) {
				Files.createDirectories(path);
				System.out.println("creat dir");
			}else {
				System.out.println("dir exists");
			}
			Path path2 = path.resolve("A.java");
			Path path3 = path.resolve("B.java");
			Path path4 = path.resolve("C.txt");
			Path path5 = path.resolve("D.jpg");
			Files.createFile(path2);
			Files.createFile(path3);
			Files.createFile(path4);
			Files.createFile(path5);
			
			// 不加条件遍历
			DirectoryStream<Path> paths = Files.newDirectoryStream(path);
			for (Path p : paths) {
				System.out.println(p.getFileName());
			}
			System.out.println();
			
			// 创建一个带有过滤器,过滤文件名以java txt结尾的文件
			DirectoryStream<Path> pathsFilter = 
					Files.newDirectoryStream(path, "*.{java,txt}");
			for (Path p : pathsFilter) {
				System.out.println(p.getFileName());
			} 
			
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
}
