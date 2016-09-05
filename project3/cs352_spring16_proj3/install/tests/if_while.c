int thing;

int foo(int i)
{
   int a=1;
   a = 5;
   int b = 5;
   if(i> 0){
       a = 1;
       b = a;
       printf("in if\n");
   }
   else{
   	a=2;
	int c;
   }
   while(a) {
   	a=b;
	b=b-1;
   }

   printf("a = %d", a);

   return 1;
}
main()
{
   foo(0);
}

