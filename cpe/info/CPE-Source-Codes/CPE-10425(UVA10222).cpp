#include <stdio.h>
char table[256];
//`1234567890-=
//qwertyuiop[]\
//asdfghjkl;'
//zxcvbnm,./
//~!@#$%^&*()_+
//QWERTYUIOP{}
//ASDFGHJKL:"
//ZXCVBNM<>?
char before[]="234567890-="
        "ertyuiop[]\\"
        "dfghjkl;'"
        "cvbnm,./"
        "@#$%^&*()_+"
        "ERTYUIOP{}|"
        "DFGHJKL:\""
        "CVBNM<>? ";
char after[] ="`1234567890"
        "qwertyuiop["
        "asdfghjkl"
        "zxcvbnm,"
        "~!@#$%^&*()"
        "qwertyuiop{"
        "asdfghjkl"
        "zxcvbnm< ";
int main()
{
  char c;
  for(int i=0;before[i]!='\0';i++){
    table[before[i]]=after[i];
  }
  while(scanf("%c",&c)>0){
    printf("%c",table[c]);
  }
  return 0;
}
