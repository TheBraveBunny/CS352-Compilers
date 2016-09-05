int main(int a){
	int i;
	i = 0;
	while ( i < 20 ){
		i=i+1;
		a= a*6;
		if ( i == a) continue;
		else if(i > a ) {
			i=i+1;
			a = a+i;
		}
		else a = i+17;

		a = a+1;

	}
	return 0;
}
