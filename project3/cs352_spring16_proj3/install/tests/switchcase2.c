int thing;

int foo(int i)
{
   switch(i){
   	case 1:
		printf("1!\n");
		i=i+2;
	case 0:
	default: 
		printf("not 1!\n");
   }


   printf("a = %d", i);

   return 1;
}
main()
{
   foo(0);
}

