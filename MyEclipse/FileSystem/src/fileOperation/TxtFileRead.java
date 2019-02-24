package fileOperation;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class TxtFileRead {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		readFile1();
		System.out.println("================");
		readFile2(); // JDK 7以上使用
	}

	private static void readFile1() {
		// TODO Auto-generated method stub
		FileInputStream fis = null;
		InputStreamReader isr = null;
		BufferedReader br = null;
		try {
			fis = new FileInputStream("~/temp/abc.txt"); // 节点类
			isr = new InputStreamReader(fis, "UTF-8");   // 转化类
			//isr = new InputStreamReader(fis);
			br = new BufferedReader(isr);                // 装饰类
			String line;
			while ((line = br.readLine()) != null) {
				System.out.println(line);
			}
		}catch (Exception ex) {
			ex.printStackTrace();
		}finally {
			try {
				br.close();
			}catch (Exception ex) {
				ex.printStackTrace();
			}
		}
	}

	private static void readFile2() {
		// TODO Auto-generated method stub
		String line;
		// try-resource 语句,自动关闭资源
		try (BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("~/temp/abc,txt")))) {
			while ((line = in.readLine()) != null) {
				System.out.println(line);
			}
		}catch (Exception ex) {
			ex.printStackTrace();
		}
	}

}
