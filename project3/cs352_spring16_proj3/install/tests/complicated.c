int thing;

int main()
{
   int i = 10;
   while(i>=10){
	   switch(i){
		case 10:
			while(i<20){
				printf("1!\n");
				i=i+1;
				break;
			}
		case 27:
		case 28:
		case 29:
		case 30:
			i=i/i;
			continue;
		default: 
			while(i>27){
				i=i/3;
				printf("smaller!\n");
			}
			while(i<27){
				printf("1!\n");
				i=i+1;	
			}
			i = i+3;
	   }
   }


   printf("a = %d", i);

   return 1;
}
