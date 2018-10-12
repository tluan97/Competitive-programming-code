
class readline {
private:
	char s[1010];
	int pos;
	void ignoreSpace(){
		while (s[pos]<=32 && s[pos]>0)
			pos++;
	}
	void pass(char aa, char bb){
		while (s[pos]>=aa && s[pos]<=bb)
			pos++;
	}
public:
	char* load(){
		pos=0;
		return gets(s);
	}
	int readInt(int *p){
		int old=pos;
		ignoreSpace();
		pass('+','9');
		return sscanf(s+old,"%d",p);
	}
}rln;
void test_(){
	while (rln.load()){
		int sum=0,p;
		for (;;){
			if (rln.readInt(&p)!=1)
				break;
			sum+=p;
		}
		printf("%d\n",sum);
	}
}
