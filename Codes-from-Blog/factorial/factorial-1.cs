using System;
 

class Program
{
    public static void Main()
    {
        int T, N, sum, x;
        T = int.Parse(Console.ReadLine());
        while (T>0)
        {
            N = int.Parse(Console.ReadLine());
            x = 5;
            sum = 0;
            while (N / x > 0)
            {
                sum += N / x;
                x *= 5;
            }
            Console.WriteLine(sum);
            T--;
        }
    }
}
