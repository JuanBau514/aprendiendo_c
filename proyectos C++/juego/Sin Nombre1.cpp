void main ()
{
	int k = {100,200,300,400,500,600,700};
	int*t=k+2;
	cout<<*t;
	cout<<"/n"<<*(t+2)+*t;
	*t=*t+10;
	cout<<*t;
	t=t+3;
	cout<<*t;
	*t=*t+*(t-2);
	cout<<*t;

}
