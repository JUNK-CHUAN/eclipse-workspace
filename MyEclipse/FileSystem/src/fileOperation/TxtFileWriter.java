package fileOperation;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

public class TxtFileWriter {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		writeFile1();
		System.out.println("====================");
		writeFile2(); // JDK 7以上才能使用
	}

	public static void writeFile1() {
		FileOutputStream fos = null;
		OutputStreamWriter osw = null;
		BufferedWriter bw = null;
		try {
			fos = new FileOutputStream("~/temp/abc.txt"); // 节点类
			osw = new OutputStreamWriter(fos, "UTF-8");   // 转化类
			// osw = new OutputStreamWriter(fos);         // 转化类
			bw = new BufferedWriter(osw);                 // 修饰类
			
			bw.write("我们是：");
			bw.newLine();
			bw.write("Ecnuers");
			bw.newLine();
		}catch (Exception ex) {
			ex.printStackTrace();
		}finally {
			try {
				bw.close();
			}catch (Exception ex) {
				ex.printStackTrace();
			}
		}
	}
	
	private static void writeFile2() {
		// TODO Auto-generated method stub
		// try-resource 语句,自动关闭资源
		try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("~/temp/abc.txt")))) {
			bw.write("我们是:");
			bw.newLine();
			bw.write("Ecnuers");
			bw.newLine();
		}catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
