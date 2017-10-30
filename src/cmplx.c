#include<fftw3.h>
#include<math.h>
#include<cmplx.h>

void cmplx_div(fftw_complex a, fftw_complex b, fftw_complex c) {
	
	c[0]=(a[0]*b[0]+a[1]*b[1])/(b[0]*b[0]+b[1]*b[1]);
	c[1]=(a[1]*b[0]-a[0]*b[1])/(b[0]*b[0]+b[1]*b[1]);
	
	return;
}


void cmplx_mul (fftw_complex a, fftw_complex b, fftw_complex c) {
	
	c[0]=a[0]*b[0]-a[1]*b[1];
	c[1]=a[0]*b[1]+a[1]*b[0];
	return;
}


double cmplx_mag(fftw_complex a) {

	double mag;
	mag=sqrt(a[0]*a[0]+a[1]*a[1]);
	return mag;
}


double cmplx_phs(fftw_complex a) {
	double phs;
	phs=atan(a[1]/a[0]);
	return phs;
}


double cmplx_real(double mag, double phs) {
	double real;
	real=mag*cos(phs);
	return real;
}


double cmplx_imag(double mag, double phs) {
	double imag;
	imag=mag*sin(phs);
	return imag;
}
