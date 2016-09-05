int thing;

int foo(int i)
{
   switch(i){
   	case 1:
		printf("1!\n");
		i=i+1;
		break;
	case 0:
	case 2: 
		printf("not 1!\n");
		break;
	default:
   }


   printf("a = %d", i);

   return 1;
}
main()
{
   foo(0);
}

