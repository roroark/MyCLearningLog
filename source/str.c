int str_length(char *str) {
  register int length=0;
  for (;*str!='\0';++str,++length);
  return length;
}
void swap_char(char *char1, char *char2) {
    char temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}
void str_reverse(char *str) {
  int str_length(char *);
  register char temp;
  for (register int i=0,j=str_length(str)-1; i<j; ++i, --j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}
// Assumes there is enough space to do the desired operation.
void str_copy(char *src, char *dest) {
  while((*dest++ = *src++) != '\0');
}
void str_append(char *src, char *dest) {
  void str_copy(char *, char *);
  while(*++dest != '\0');
  str_copy(src, dest);
}
void str_copy_at(char *src, char *dest, long offset) {
  void str_copy(char *, char *);
  dest += offset;
  str_copy(src, dest);
}
void strsrt(char *strStart, char * strEnd) {
  int length = strEnd-strStart;

}
