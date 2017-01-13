int strlen(char *str) {
  register int length=0;
  for (;*str!='\0';++str,++length);
  return length;
}
void swapchar(char *char1, char *char2) {
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}
void strrev(char *str) {
  register char temp;
  for (register int i=0,j=strlen(str)-1; i<j; ++i, --j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void strsrt(char *strStart, char * strEnd) {
  int length = strEnd-strStart;

}
