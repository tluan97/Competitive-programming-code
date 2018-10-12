
vector<double> a;

double average(vector<double> a){
	double x=0.0;
	for (int i=0;i<a.size();i++)
		x+=a[i];
	x/=a.size();
	return x;
}
double standard(vector<double> a){
	double s=0.0;
	double x=average(a);
	for (int i=0;i<a.size();i++){
		s+=pow(a[i]-x,2);
	}
	s=sqrt(s/(a.size()-1));
	return s;
}
