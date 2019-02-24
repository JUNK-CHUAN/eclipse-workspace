package fileOperation;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class SingleFileUnzip {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub

		// 待解压文件需要从zip文件打开输入流, 读取数据到java中
		File zipFile = new File("~/temp/single.zip");
		ZipInputStream input = null;
		input = new ZipInputStream(new FileInputStream(zipFile));
		ZipEntry entry = input.getNextEntry();
		System.out.println("压缩实体名称" + entry.getName());
		
		// 新建目标文件, 需要从目标文件打开输出流, 数据从java流入
		File outFile = new File("~/temp/" + entry.getName());
		OutputStream out = new FileOutputStream(outFile);
		int temp = 0;
		while((temp = input.read()) != -1) {
			out.write(temp);
		}
		input.close();
		out.close();
		System.out.println("unzip done.");
	}

}
