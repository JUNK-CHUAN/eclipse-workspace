package fileOperation;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;

public class BinFileRead {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		readFile();
		System.out.println("done.");
	}

	private static void readFile() {
		// TODO Auto-generated method stub
		// try-resource 语句,自动关闭资源
		try (DataInputStream dis = new DataInputStream(new BufferedInputStream(new FileInputStream("~/temp/abc.txt")))) {
			String a,b;
			int c,d;
			a = dis.readUTF();
			c = dis.readInt();
			d = dis.readInt();
			b = dis.readUTF();
			System.out.println("a: " + a);
			System.out.println("b: " + b);
			System.out.println("c: " + c);
			System.out.println("d: " + d);
			
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

}
