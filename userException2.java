class invalidException2 extends Exception{
    public invalidException2(String message){
        super(message);
    }
}
class AgeValidator2{
    void Validator(int age) throws invalidException2{
        if(age<18){
            throw new invalidException2("minor");
        }
    }
}
public class userException2{
    public static void main(String[] args) {
        try {
            AgeValidator2 a=new AgeValidator2();
            a.Validator(12);
            
        } catch (Exception e) {
            System.out.println("error found: "+e.getMessage());
        }
    }
}