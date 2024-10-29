class InvalidException extends Exception{
    public InvalidException(String message){
        super(message);
    }
}
class AgeValidater{
    void validate(int age) throws InvalidException{
        if(age<18){
            throw new InvalidException("access denied!");
        }
        else{
            throw new InvalidException("access granted");
        }
    }
}
public class userException {
    public static void main(String[] args) {
        try{
            AgeValidater a1=new AgeValidater();
            a1.validate(12);
        }catch(Exception e){
            System.out.println("Caught an exception: "+e.getMessage());
        }
        
    }
}
