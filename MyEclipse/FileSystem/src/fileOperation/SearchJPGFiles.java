package fileOperation;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.FileVisitOption;
import java.nio.file.FileVisitResult;
import java.nio.file.FileVisitor;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.PathMatcher;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.EnumSet;

@SuppressWarnings("rawtypes")
class Search implements FileVisitor {

	private final PathMatcher matcher;

	public Search(String ext) {
		matcher = FileSystems.getDefault().getPathMatcher("glob:" + ext);
	}
	
	public void judgeFile(Path file) throws IOException {
		Path name = file.getFileName();
		if (name != null &&matcher.matches(name)) {
			// 文件名字已经匹配
			System.out.println("Searched file was found: " + name + " in " 
								+ file.toRealPath().toString());
		}
	}
	
	@Override
	public FileVisitResult preVisitDirectory(Object dir, BasicFileAttributes attrs) throws IOException {
		// TODO Auto-generated method stub
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFile(Object file, BasicFileAttributes attrs) throws IOException {
		// TODO Auto-generated method stub
		judgeFile((Path) file);
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult visitFileFailed(Object file, IOException exc) throws IOException {
		// TODO Auto-generated method stub
		// report an error if necessary
		return FileVisitResult.CONTINUE;
	}

	@Override
	public FileVisitResult postVisitDirectory(Object dir, IOException exc) throws IOException {
		// TODO Auto-generated method stub
		System.out.println("Visited: " + (Path)dir);
		return FileVisitResult.CONTINUE;
	}
		
	// 查找一个目录下的所有的jpg文件,包括子文件夹
	public class SearchJPGFiles {
		
		public void main(String[] args) throws IOException {
			// 定义扩展名，和待查找目录
			String ext = "*.jpg";
			Path fileTree = Paths.get("~/temp");
			Search walk = new Search(ext);
			EnumSet<FileVisitOption> opts = EnumSet.of(FileVisitOption.FOLLOW_LINKS);
			
			Files.walkFileTree(fileTree, opts, Integer.MAX_VALUE, walk);
		}
	}
}
