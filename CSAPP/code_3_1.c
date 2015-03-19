int
b()
{
	int a = 1;
	return a;
}

int
test(void)
{	
	int a;
	a = b();
	a = a + 1;
	a = a * 2;
	while(a)
		a--;
	return a;
}