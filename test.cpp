void factor(int n) 
     { 
       int i; 
       for(i=2;i<=(int)sqrt(n);i++) 
       { 
         while(n % i == 0) 
         { 
           printf("%d ",i); 
           n /= i; 
         } 
       } 
       if (n > 1) printf("%d",n); 
       printf("\n"); 
     }  

         int fi(int n) 
     { 
       int result = n; 
       for(int i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) result -= result / i; 
         while (n % i == 0) n /= i; 
       } 
       if (n > 1) result -= result / n; 
       return result; 
     } 
