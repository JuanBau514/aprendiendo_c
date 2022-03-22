#include<iostream>
#include<locale.h>
using namespace std;

main()
{
	int num;
	int cociente,residuo;
	
	num=10;
	cociente=num/2;
	residuo=num%2;
	printf("cociente %d\n",cociente);
	printf("residuo %d\n",residuo);
	num=cociente;
	
	cociente=num/2;
	residuo=num%2;
	printf("cociente %d\n",cociente);
	printf("residuo %d\n",residuo);
	
	cociente=num/2;
	residuo=num%2;
	printf("cociente %d\n",cociente);
	printf("residuo %d\n",residuo);	
	cociente=num/2;
	
	cociente=num/2;
	residuo=num%2;
	printf("cociente %d\n",cociente);
	printf("residuo %d\n",residuo);	
	
	residuo=num%2;
	printf("cociente %d\n",cociente);
	printf("residuo %d\n",residuo);	
}
