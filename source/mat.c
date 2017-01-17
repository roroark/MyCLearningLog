#include <math.h>

double sum(double * arr, long length) {
  double s = 0;
  for (int i=0; i<length; i++) s+=arr[i];
  return s;
}
double average(double * arr, long length) {
  double sum(double *, long), avg = sum(arr, length);
  return avg/length;
}
double stdev(double *arr, long length) {
  double avg = average(arr, length);
  double variance = 0;
  for (int i=0; i<length; i++) variance += (arr[i]-avg)*(arr[i]-avg);
  variance /= length;
  return sqrt(variance);
}
