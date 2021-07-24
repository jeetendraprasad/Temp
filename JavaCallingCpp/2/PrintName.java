public class PrintName{
    static{
        System.loadLibrary("name");
    }
    //the function is defined in a c-file
    private static native void printName(final String name);

    private static native void greeting();

    public static void main(final String ... args){

        printName("Jeetendra Prasad");

        greeting();
    }
}
