#ifndef MAIN_H
#define MAIN_H

int main (void){
	/* Low-level output tracking */
	int _putchar(char c);
	
	/* Calculator Function Prototypes */
	
	int a = 0;
	int b = 0;
	int c = 4;
	
	
	
	while (c!= 0){
		printf("Simple Calculator/n 1-Add/n 2-Subtract/n 3-Multiply/n 4-Divide/n 0-Quit");
		
		switch (c){
			case 1:
				puts(int add(a,b));
				
			case 2:
				puts(int sub(a,b));
				
			case 3:
				puts(int mul(a,b));
				
			case 4:
				puts(int div(a,b));
				
				
		}
		//int mod(a,b);
	}
	puts("Bye!");}


#endif /* MAIN_H */
