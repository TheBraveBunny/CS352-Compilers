int thing;

int foo(int i){
   while(i) {
	   int a;
	   int b;
	   if(i> 0){
	       a = 1;
	       b = a;
	       printf("in if\n");
	   }
	   else{
		a=2;
		int c;
	   }
   	
	a=b;
   	printf("a = %d", a);
   }
   return 1;
}
main(){
   foo(0);
}

