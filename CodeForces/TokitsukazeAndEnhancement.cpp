#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 0, 3, 1, 2 };
	char cad[] = "DCBA";

	int n;
	scanf("%d", &n );

	int ans = arr[ n%4 ];
	int sum = 0;

	if( arr[ (n+1)%4 ] > ans )
	{
		ans = arr[ (n+1)%4 ];
		sum = 1;
	}

	if( arr[ (n+2)%4 ] > ans )
	{
		ans = arr[ (n+1)%4 ];
		sum = 2;
	}
	
	printf("%d %c\n", sum, cad[ ans ]);
}
