public class FirstGrade {
	final String st1 = "FirstGrade.st1";
	
	public static void main(final String[] args){
		final String st1 = "SecondGrade.st1";
		
		class Student{
			String getSt1(){
				return st1;
			}
		}
		class College{
			String st1 = "Course.st1";
			College(){
				System.out.println(new Student().getSt1());
			}
		}
		College col = new College();
	}
}
