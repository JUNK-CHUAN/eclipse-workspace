package fileOperation;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;

public class BinFileWrite {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		writeFile();
		System.out.println("done.");
	}

	private static void writeFile() {
		// TODO Auto-generated method stub
		FileOutputStream fos = null;
		DataOutputStream dos = null;
		BufferedOutputStream bos = null;
		try {
			fos = new FileOutputStream("~/temp/abc.txt"); // 节点类
			bos = new BufferedOutputStream(fos);          // 装饰类
			dos = new DataOutputStream(bos);              // 装饰类
			
			dos.writeUTF("a");
			dos.writeInt(20);
			dos.writeInt(100);
			dos.writeUTF("b");
			
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			try {
				dos.close();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
		}
	}

}
