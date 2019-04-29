
class Volume  
{ 
     public static void main(String args[])  
     { 
         Box b = new Box(5,5,5); 
         System.out.println(b.volume); 
     } 
} 
class Box  
{ 
     public int volume; 
     Box(int length, int width, int height)  
     { 
         this.volume = length * width * height; 
     } 
} 

class Volume2  
{ 
     public static void main(String args[])  
     { 
         Box2 b = new Box2(5,5,5); 
         System.out.println(b.getVolume()); 
     } 
} 
final class Box2  
{ 
     private int volume; 
     Box2(int length, int width, int height)  
     { 
         this.volume = length * width * height; 
     } 
     public int getVolume()  
     {  
         return volume;   
     } 
} 

class Name { 
	String name; 
	public String getName(String name) 
	{ 
		this.name = name; 
		return name; 
	} 
} 

class Age { 
	int age; 
	public int getAge(int age) 
	{ 
		this.age = age; 
		return age; 
	} 
} 

class Number { 
	int rno; 
	public int getNumber(int no) 
	{ 
		this.rno = no; 
		return rno; 
	} 
} 

class Display { 
	public static void main(String[] args) 
	{ 
		Name n = new Name(); 
		System.out.println(n.getName("NewBorn")); 
		Age a = new Age(); 
		System.out.println(a.getAge(19)); 
		Number no = new Number(); 
		System.out.println(no.getNumber(7205)); 
	} 
} 
