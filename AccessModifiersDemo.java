class AccessModifiersDemo 
{
    int defaultNumber = 0;
    
    public static String PublicMethod()
    {
        return "Inside the public method";
    }
    
    private static String PrivateMethod()
    {
        return "Inside the private method";
    }
    
    protected static String ProtectedMethod()
    {
        return "Inside the protected method";
    }
    public static void main(String[] args) 
    {
        System.out.println("Message returned from Public Method : " + PublicMethod());
        System.out.println("Message returned from Private Method : " + PrivateMethod());
        System.out.println("Message returned from Protected Method : " + ProtectedMethod());
    }
}