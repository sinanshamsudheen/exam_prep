class Employee{
    String name;
    int age;
    int phone;
    String address;
    double salary;
    public void printSalary(){
        System.out.println("salary of employee: "+salary);
    }
}
class Officer extends Employee{
    String specialization;
}
class Manager extends Employee{
    String department;
}
public class inher{
    public static void main(String[] args) {
        Officer of=new Officer();
        of.name="sinan";
        of.age=20;
        of.phone=999999;
        of.address="kannur";
        of.salary=6.9;
        of.specialization="flirts";
        
        Manager mg=new Manager();
        mg.name="aadil";
        mg.age=19;
        mg.phone=6969;
        mg.address="tvm";
        mg.salary=79.5;
        mg.department="cars";

        System.out.println(mg.name);
        System.out.println(mg.salary);
        System.out.println(mg.address);
        System.out.println(mg.phone);
        System.out.println(mg.age);
        System.out.println(mg.department);
        mg.printSalary();
        
        System.out.println(of.name);
        System.out.println(of.salary);
        System.out.println(of.address);
        System.out.println(of.phone);
        System.out.println(of.age);
        System.out.println(of.specialization);
        of.printSalary();


    }
}

