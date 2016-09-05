int main(int a){
	int i;
	i = 0;
	while ( i < 20 ){
		i=i+1;
		a= a*6;
		if ( i == a) continue;
		else if(i > a ) {
			int w = i;
			i=i+1;
			a = a+w;
		}
		else a = i+17;

		a = a+1;

	}
	return 0;
}
