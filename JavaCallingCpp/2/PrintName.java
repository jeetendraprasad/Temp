public class PrintName{
    static{
        System.loadLibrary("name");
    }

    //functions are defined in a c-file
    private static native void printName(final String name);
    private static native void greeting();
    private static native int add(int num1, int num2);
    private static native String append(final String str1, final String str2);

    public static void main(final String ... args){

        printName("[JAVA]Jeetendra Prasad");

        greeting();

        int sum = add(23,45);

        System.out.print("[JAVA]" +sum+"\n");

        System.out.print("[JAVA] Printing combined message in Java. " + append("[JAVA]Message1"," [JAVA]Message2") + "\n");
    }
}
