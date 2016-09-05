int thing;

int foo(int i)
{
   {
	nt a = 1;
	printf("this is in a block!\n");
   }

   printf("a = %d", i);

   return 1;
}
main()
{
   foo(0);
}

