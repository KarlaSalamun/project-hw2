#include <cmplx.h>
#include <stdio.h>
#include <fftw3.h>
#include <math.h>

int main () {
	fftw_complex a, b, c;
	double mag, phs, real, imag;
	
	a[0]=2;
	a[1]=2;
	b[0]=1;
	b[1]=1;
	
	cmplx_div(a, b, c);
	printf("c=%f+%f*i", c[0], c[1]);
	
	cmplx_mul(a, b, c);
	printf("\nc=%f+%f*i", c[0], c[1]);
	
	mag=cmplx_mag(a);
	printf("\n|a|=%f", mag);
	
	phs=cmplx_phs(a);
	printf("\nphs(a)=%f", phs);
	
	real=cmplx_real(mag, phs);
	printf("\nreal=%f", real);
	
	imag=cmplx_imag(mag, phs);
	printf("\nimag=%f\n", imag);
	
	return 0;
}	
