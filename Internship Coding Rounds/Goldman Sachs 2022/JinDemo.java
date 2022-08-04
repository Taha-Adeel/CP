class Jin{
	Jin() {}
	private Jin(byte b) { }
	Jin(int x) { }
	Jin(int x, int... y) { }
}

class JinDemo{
	public static void main(String args[]){
		int a = 3;
		Jin obj = new Jin();
		Jin obj1 = new Jin(a++);
		Jin obj2 = new Jin(++a + a, a++ + a, ++a + a);

		System.out.println(a);
	}
}